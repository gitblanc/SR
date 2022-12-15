#include <SPI.h> //Importamos librería comunicación SPI 
#include <Ethernet.h> //Importamos librería Ethernet
#include <DHT.h> // Librería externa
// Descomentar el sensor a utilizar:
#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT22 // DHT 22 (AM2302) 
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

#define DHT11_PIN 7
//Incluimos el dht
DHT dht(DHT11_PIN, DHTTYPE);

byte mac[] = {0x54, 0x55, 0x58, 0x10, 0x00, 0xB3}; // Tiene que ser única en la red local, cuidado, cambiad el último dígito por el de vuestro grupo
EthernetServer servidor(80); // Puerto en el 80
// Estos datos cogedlos del ordenador que uséis o del de al lado 
IPAddress dnsServer(8, 8, 8, 8);
IPAddress gateway(10,38,0,1);
IPAddress subnet(255, 255, 255, 0);

// Que cada uno ponga la IP de su grupo (20X, dónde X es el número del grupo) 201, 202, 203, que es el que tiene asignado. Tiene que ser única en la red local, cuidado
IPAddress ip(192, 168, 61, 203);

int led = 8; 
void setup(){
  Serial.begin(9600);
  Ethernet.begin(mac, ip, dnsServer, gateway, subnet); 
  servidor.begin();
  Serial.println("Setup");
  // Imprimir la IP 
  Serial.println(Ethernet.localIP());
   // Inicializar el led
  pinMode(led,OUTPUT);
  digitalWrite(led,HIGH);
}

void loop(){
  EthernetClient cliente = servidor.available();
  if (cliente) { 
    Serial.println("Nueva peticion"); 
    String peticion="";
    while (cliente.connected()) {
      if(cliente.available()) {
        char c = cliente.read(); //Lee peticion caracter a caracter
        peticion.concat(c);

        // Ha acabado la peticion http
        // Si contiene index responder con una web
        // la petición ha acabado '\n' y contiene la cadena "index" al principio: index, indexabc, indexación, etc. Usar equals para que sea igual
        if (c == '\n' && peticion.indexOf("index") != -1){
            Serial.println("Responder"); 
            // Serial.println(peticion);
            // contiene la cadena "encender"
            if(peticion.indexOf("encender") != -1){ 
                Serial.println("Encender Led"); 
                digitalWrite(led,HIGH);
            } else if(peticion.indexOf("apagar") != -1){ 
              // contiene la cadena "apagar" 
              Serial.println("Apagar led"); 
              digitalWrite(led,LOW);
            } else if(peticion.indexOf("mostrar") != -1) {
              //leer los valores que se les pasa
              if (isnan( dht.readTemperature()) || isnan(dht.readHumidity())) {
                  Serial.println("Fallo en la lectura del "+DHTTYPE);
                  return;
              }
              //contiene la cadena "mostrar"
              Serial.println("datos");
              cliente.println("{\"temperatura\": \"" + String( dht.readTemperature()) + "\", \"humedad\": \"" + String(dht.readHumidity()) + "\"}");
            }

            // Enviamos al cliente una respuesta HTTP
            cliente.println("HTTP/1.1 200 OK"); 
            cliente.println("Content-Type: text/html"); 
            cliente.println("Access-Control-Allow-Origin: *"); 
            cliente.println();
            break;
        }
      }
    }
  } 

  delay(1000); // Actualizar cada segundo
  cliente.stop();

}