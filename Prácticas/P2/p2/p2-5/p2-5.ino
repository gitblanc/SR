#include <Keypad.h>
#include <TM1637.h>
//Leds
int ledRojo = 2;
int ledVerde = 3;

//Teclado
const byte nfilas = 4;
const byte ncolumnas = 4;
char teclas[nfilas][ncolumnas] = {
   {'1','2','3','A'}, 
   {'4','5','6','B'}, 
   {'7','8','9','C'},
   {'*','0','#','D'}
  };
byte pinsFilas[nfilas] = { A0, A1, A2, A3};
byte pinsColumnas[ncolumnas] = { 7, 6, 5, 4 };

Keypad teclado = Keypad(makeKeymap(teclas), pinsFilas, pinsColumnas,
nfilas, ncolumnas);

bool isOpened = false;

double inicioCuentaTiempo;

int sizeOfBuffer;

//Contraseña
String bufferLectura = "";//para la contraseña
String password = "9876";

// Sensor ultrasonidos
long distance;
long responseTime;

int pinTrig = 9;
int pinEcho = 8;

// Sensor de luz
int sensorLuz = A4;

//Pantalla de segmentos
int pinClk = 10;
int pinDio = 11;
TM1637 screen(pinClk, pinDio);

int cont = 0;
bool entroUltrasonidos = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  //Ultrasonidos
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  digitalWrite(ledVerde, HIGH);
  //Sensor de luz
  pinMode(sensorLuz, INPUT);
  //Pantalla de segmentos
  screen.init();
  screen.set(BRIGHT_TYPICAL);
  delay(1500);//esperamos a que se inicie la pantalla
}

void loop() {
  char teclaPulsada = teclado.getKey();
  if(bufferLectura == password && !isOpened){
      inicioCuentaTiempo = millis();
      isOpened = true;
      Serial.println("Contraseña correcta -> puerta ABIERTA");
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledRojo, HIGH);
      sizeOfBuffer = 0;
  }else if(teclaPulsada == 'C'&& isOpened){
        isOpened = false;
        Serial.println("Tecla pulsada: C -> puerta CERRADA");
        digitalWrite(ledRojo, LOW);
        digitalWrite(ledVerde, HIGH);
        bufferLectura = ""; // reinicio del buffer
        sizeOfBuffer = 0;
  }
  else if (hayPersonasInterior() < 100 && hayPersonasExterior() < 10 && isOpened){
    inicioCuentaTiempo = millis();
    isOpened = true;
    Serial.println("Objeto grande detectado -> puerta ABIERTA");
    digitalWrite(ledRojo, HIGH);
    digitalWrite(ledVerde, LOW);
  }
  else if(millis() - inicioCuentaTiempo >= 5000 && isOpened){
        isOpened = false;
        digitalWrite(ledRojo, LOW);
        digitalWrite(ledVerde, HIGH);
        bufferLectura = ""; // reinicio del buffer
        sizeOfBuffer = 0;
        Serial.println("Pasaron 5 segundos -> puerta CERRADA");
  }else if(hayPersonasInterior() < 100 && isOpened){//Caso 3 sensor de luz
        Serial.println("Hay personas en el interior -> PUERTA CERRADA");
        digitalWrite(ledRojo, LOW);
        digitalWrite(ledVerde, HIGH);
        bufferLectura = ""; // reinicio del buffer
        sizeOfBuffer = 0;
        if(entroUltrasonidos){
          cont+=1;
          mostrarPantalla(cont);
          entroUltrasonidos = false;
        }
        isOpened = false;
  }else if(hayPersonasExterior() < 10 && isOpened){
    Serial.println("Hay personas en el interior -> puerta ABIERTA");
    entroUltrasonidos = true;
    isOpened = false;
    sizeOfBuffer = 0;
  }else if(sizeOfBuffer > 3 && !isOpened){
    bufferLectura = ""; // reinicio del buffer
    sizeOfBuffer = 0;
    for(int i = 0; i <= 3; i++){
      digitalWrite(ledVerde, HIGH);
      delay(200);
      digitalWrite(ledVerde, LOW);
      delay(1000);
    }
    digitalWrite(ledVerde, HIGH);
  }
  else if(isdigit(teclaPulsada) && !isOpened){
    bufferLectura += teclaPulsada;
  Serial.println("buffer: "+bufferLectura);
    sizeOfBuffer++;
  }
}

long hayPersonasExterior(){
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(10);
  digitalWrite(pinTrig, HIGH);//enviamos el pulso
  delayMicroseconds(10);
  responseTime = pulseIn(pinEcho, HIGH);// Medimos la longitud
  //Serial.println("Tiempo: " + String(responseTime) + " microsegundos");
  distance = 0.01716*responseTime;// Calculamos la distancia una vez conocemos la velocidad
  //Serial.println("Distance: " + String(distance) + " cm");
  delay(100);
  return distance;
}

int hayPersonasInterior(){
  return analogRead(sensorLuz);
}

void mostrarPantalla(int contador){
distance = contador;
//4.-
int digit0 = distance/1000; 
Serial.println("Digit0 "+ String(digit0));
int digit1 = (distance - digit0*1000)/100; 
Serial.println("Digit1 "+ String(digit1));
int digit2 = (distance - (digit0*1000 + digit1*100))/10; 
Serial.println("Digit2 "+ String(digit2));
int digit3 = distance - (digit0*1000 + digit1*100 + digit2*10);
Serial.println("Digit3 "+ String(digit3));
screen.display(0, digit0); 
screen.display(1, digit1); 
screen.display(2, digit2); 
screen.display(3, digit3);
}
