#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "DHT.h"
#include "HTTPClient.h"
#include "SPIFFS.h"

#define pinSensor 27 // pin del dht
#define DHTTYPE 11 // tipo del dht

WiFiClient client;

DHT dht(pinSensor, DHTTYPE); // creamos el sensor dht 

float t = 0; // temperatura
float h = 0; // humedad

// referencia -> https://techtutorialsx.com/2018/10/04/esp32-http-web-server-serving-external-javascript-file/
AsyncWebServer server(80); //servidor del esp

void connectToWifi(){
  WiFi.begin("Xin", "olaquetal");//aquí el nombre de la red y la contraseña
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

float leerTemperatura(){
    return dht.readTemperature();//en celsius
}

float leerHumedad(){
    return dht.readHumidity();
}

void setup(){
  Serial.begin(115200);

  connectToWifi();
 
  if(!SPIFFS.begin()){
      Serial.println("An Error has occurred while mounting SPIFFS");
      return;
  }

  Serial.println(WiFi.localIP());

  server.on("/html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/test.html", "text/html");
  });
  // responsable de servir al .js
  server.on("/test.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/test.js", "text/javascript");
  });

  server.begin();
}

void loop(){
  // t = leerTemperatura();
  // h = leerHumedad();
}