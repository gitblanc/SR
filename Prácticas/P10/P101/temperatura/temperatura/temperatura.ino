#include <DHT.h> // Librerías externas
#include <SPI.h> //Importamos librería comunicación SPI 
#include <Ethernet.h> //Importamos librería Ethernet

byte mac[] = {0x54, 0x55, 0x58, 0x10, 0x00, 0xB3}; // Tiene que ser única en la red local, cuidado, cambiad el último dígito por el de vuestro grupo
EthernetServer servidor(80); // Puerto en el 80
// Estos datos cogedlos del ordenador que uséis o del de al lado 
IPAddress dnsServer(8, 8, 8, 8);
IPAddress gateway(192, 168, 61, 13);
IPAddress subnet(255, 255, 255, 0);
// Que cada uno ponga la IP de su grupo (20X, dónde X es el número del grupo) 201, 202, 203, que es el que tiene asignado. Tiene que ser única en la red local, cuidado
IPAddress ip(192, 168, 61, 179);

// Descomentar el sensor a utilizar:
#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT22 // DHT 22 (AM2302) 
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

int pin_sensor = 5;
DHT dht(pin_sensor, DHTTYPE); 
float temperature, humidity;

void setup(){ 
  Serial.begin(9600);
  Ethernet.begin(mac,ip,dnsServer, gateway, subnet);
  servidor.begin();
  Serial.println("Setup");
  Serial.println(Ethernet.localIP()); 
  dht.begin();
  temperature = 0;
  humidity = 0; 
}

void loop(){
  
  EthernetClient cliente = servidor.available();

  if(!cliente){
    return;
  }
  // Hay cliente!
  Serial.println("Nuevo cliente, esperar mientras no está listo"); 
  while(!cliente.available()){
    delay(1); 
  }

  temperature = dht.readTemperature(); 
  humidity = dht.readHumidity();
  if (isnan(temperature) || isnan(humidity)) { 
    Serial.println("Fallo en la lectura del "+DHTTYPE); 
    return;
  }
  // Enviamos al cliente una respuesta HTTP
  cliente.println("HTTP/1.1 200 OK"); 
  cliente.println("Access-Control-Allow-Origin: *");
  cliente.println("Content-Type: application/json"); 
  cliente.println();
  cliente.println("{\"temperatura\": \"" + String(temperature) + "\", \"humedad\": \"" + String(humidity) + "\"}");
  delay(1000); // Actualizar cada segundo }
}
