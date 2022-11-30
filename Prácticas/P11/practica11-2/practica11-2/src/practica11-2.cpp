#include <Arduino.h>
#include "WiFi.h"
#include "Thingspeak.h"

#define CHANNEL_ID  1961514
#define CHANNEL_API_KEY  "HM2RB62HXYMLRLI7"

//PARA EL LDR
// vídeo de inspiración -> https://www.youtube.com/watch?v=F1fQ8m3S8-4
WiFiClient client;
int ldr = 34;
int led1 = 22;
//PARA EL TALKBACK
// web de inspiración -> https://es.mathworks.com/help/thingspeak/control-a-light-with-talkback-and-esp32.html
unsigned long myTalkBackID = 47432;
const char * myTalkBackKey = "MKBHKR8MYKS327NC";

void connectToWifi(){
  WiFi.begin("MOVISTAR_A22A", "Pg2a56i228y32FSQcYoV");
  // Espera a que se conecte la wifi
  uint32_t notConnectedCounter = 0;
  while (WiFi.status() != WL_CONNECTED) {
      delay(100);
      Serial.println("Wifi connecting...");
      notConnectedCounter++;
      if(notConnectedCounter > 150) { // resetea el d32 si no hay conexión tras 5s
          Serial.println("Resetting due to Wifi not connecting...");
          ESP.restart();
      }
  }
  Serial.print("Wifi connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  connectToWifi();
  ThingSpeak.begin(client);//instancia del cliente wifi
}

int leerTemperatura(){
  return analogRead(ldr);//saldrá un valor entre 0 y 4095
}

// Función que se encarga de realizar una petición POST
int httpPOST(String uri, String postMessage, String &response){

  bool connectSuccess = false;
  connectSuccess = client.connect("api.thingspeak.com",80);

  if(!connectSuccess){
      return -301;   
  }
  
  postMessage += "&headers=false";
  
  String Headers =  String("POST ") + uri + String(" HTTP/1.1\r\n") +
                    String("Host: api.thingspeak.com\r\n") +
                    String("Content-Type: application/x-www-form-urlencoded\r\n") +
                    String("Connection: close\r\n") +
                    String("Content-Length: ") + String(postMessage.length()) +
                    String("\r\n\r\n");

  client.print(Headers);
  client.print(postMessage);

  long startWaitForResponseAt = millis();
  while(client.available() == 0 && millis() - startWaitForResponseAt < 5000){
      delay(100);
  }

  if(client.available() == 0){       
    return -304; // Si no obtiene respuesta a tiempo
  }

  if(!client.find(const_cast<char *>("HTTP/1.1"))){
      return -303; // Si no puede corroborar la respuesta http
  }
  
  int status = client.parseInt();
  if(status != 200){
    return status;
  }

  if(!client.find(const_cast<char *>("\n\r\n"))){
    return -303;
  }

  String tempString = String(client.readString());
  response = tempString;
  
  return status;
}

void obtenerDatos(){
  ThingSpeak.setField(1, leerTemperatura());//lee la cantidad de luz del arduino y la envía
  ThingSpeak.setField(2, WiFi.RSSI());
  ThingSpeak.writeFields(CHANNEL_ID, CHANNEL_API_KEY);//más eficiente para hacer una única petición http
}

void encenderYApagarLed(){
  // creación de la URI de TalkBack
  String tbURI = String("/talkbacks/") + String(myTalkBackID) + String("/commands/execute");
  
  // Creamos el cuerpo del mensaje para la petición
  String postMessage =  String("api_key=") + String(myTalkBackKey);                      
                       
   // Creamos un String para los posibles comandos que haya en la cola
  String newCommand = String();

  // Make the POST to ThingSpeak
  int x = httpPOST(tbURI, postMessage, newCommand);
  client.stop();
  
  // Check the result
  if(x == 200){
    Serial.println("comprobando cola..."); 
    // check for a command returned from TalkBack
    if(newCommand.length() != 0){

      Serial.print("  Último comando de la cola");
      Serial.println(newCommand);

      if(newCommand.toInt() == 7){//enciende
        Serial.println("El led se enciende");
        digitalWrite(led1, HIGH);  
      }else if(newCommand.toInt() == 8){//apaga
      Serial.println("El led se apaga");
        digitalWrite(led1, LOW);
      }
    } else{
      Serial.println("  Nada nuevo...");  
    }
  } else{
    Serial.println("Problema comprobando la cola. Código de error: " + String(x));
  }
}

void loop() {
  // PARTE 1
  obtenerDatos();

  // PARTE 2
  // NOTA: se han de definir manualmente los comandos el ThingSpeak (TURN_ON y TURN_OFF)
  encenderYApagarLed();

  delay(20000); // Esperamos 20 segundos entre peticiones
}