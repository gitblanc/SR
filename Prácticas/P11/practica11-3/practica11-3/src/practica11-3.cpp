#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "DHT.h"
#include "HTTPClient.h"

#define pinSensor 27 // pin del dht
#define DHTTYPE 11 // tipo del dht

WiFiClient client;

DHT dht(pinSensor, DHTTYPE); // creamos el sensor dht 

AsyncWebServer server(80); // creamos el servidor

float t = 0; // temperatura
float h = 0; // humedad

String host = "http://ipv4";//aquí ponemos la ip de nuestro pc
String php_connecter = "/connect.php";

void connectToWifi(){
  WiFi.begin("wifi_nombre", "wifi_passwd");//aquí el nombre de la red y la contraseña
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

// CREAMOS EL HTML DE LA PÁGINA
  const char index_html[] PROGMEM = R"rawliteral(
  <!DOCTYPE HTML><html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
    <style>
      html {
      font-family: Arial;
      display: inline-block;
      margin: 0px auto;
      text-align: center;
      }
      h2 { font-size: 3.0rem; }
      p { font-size: 3.0rem; }
      .units { font-size: 1.2rem; }
      .dht-labels{
        font-size: 1.5rem;
        vertical-align:middle;
        padding-bottom: 15px;
      }
    </style>
  </head>
  <body>
    <h2>D32 Web Server</h2>
    <h3>Software para Robots 2022, Eduardo Blanco Bielsa</h3>
    <p>
      <i class="fas fa-thermometer-half" style="color:#FF0C00;"></i> 
      <span class="dht-labels">Temperatura</span> 
      <span id="temperatura">%TEMPERATURA%</span>
      <sup class="units">&deg;C</sup>
    </p>
    <p>
      <i class="fas fa-tint" style="color:#00add6;"></i> 
      <span class="dht-labels">Humedad</span>
      <span id="humedad">%HUMEDAD%</span>
      <sup class="units">&percnt;</sup>
    </p>
  </body>
  <script>
  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("temperatura").innerHTML = this.responseText;
      }
    };
    xhttp.open("GET", "/temperatura", true);
    xhttp.send();
  }, 10000 ) ;

  setInterval(function ( ) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        document.getElementById("humedad").innerHTML = this.responseText;
      }
    };
    xhttp.open("GET", "/humedad", true);
    xhttp.send();
  }, 10000 ) ;
  </script>
  </html>)rawliteral";

// Cogemos los valores del DHT
String processor(const String& var){
  if(var == "TEMPERATURA"){
    return String(leerTemperatura());
  }
  else if(var == "HUMEDAD"){
    return String(leerHumedad());
  }
  return String();
}

void setup(){
  Serial.begin(115200);

  dht.begin();//iniciamos el sensor
  
  connectToWifi(); // conectamos el d32 a la wifi

  // Página principal a tiempo real (root)
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });
  server.on("/temperatura", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(t).c_str());
  });
  server.on("/humedad", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(h).c_str());
  });
  
  // Start server
  server.begin();
}
 
void loop(){
  t = leerTemperatura();
  h = leerHumedad();

  HTTPClient http;
  String server = host + php_connecter + "?&temperatura=" + t + "&humedad=" + h;
  http.begin(server); 
  int httpCode = http.GET();

  if(httpCode > 0) {
    if(httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    } else {
      Serial.printf("HTTP GET... code: %d\n", httpCode);
    }
  } else {
    Serial.printf("HTTP GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
  delay(1000);
}