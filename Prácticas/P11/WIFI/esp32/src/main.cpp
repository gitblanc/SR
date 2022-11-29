#include <Arduino.h>
#include "WiFi.h"
#include "Thingspeak.h"

#define CHANNEL_ID  1961514
#define CHANNEL_API_KEY  "HM2RB62HXYMLRLI7"

//vídeo de inspiración -> https://www.youtube.com/watch?v=F1fQ8m3S8-4
WiFiClient client;
int ldr = 34;

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
  connectToWifi();
  ThingSpeak.begin(client);//instancia del cliente wifi
}

int leerTemperatura(){
  return analogRead(ldr);//saldrá un valor entre 0 y 4095
}

void loop() {
  ThingSpeak.setField(1, leerTemperatura());//lee la temperatura del arduino y la envía
  ThingSpeak.setField(2, WiFi.RSSI());
  ThingSpeak.writeFields(CHANNEL_ID, CHANNEL_API_KEY);//más eficiente para hacer una única petición http
  // //Serial.println(Serial2.readString());
  delay(20000);
}