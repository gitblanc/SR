#include <Keypad.h>
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
byte pinsFilas[nfilas] = { 11, 10, 9, 8 };
byte pinsColumnas[ncolumnas] = { 7, 6, 5, 4 };

Keypad teclado = Keypad(makeKeymap(teclas), pinsFilas, pinsColumnas,
nfilas, ncolumnas);

bool isOpened = false;

double inicioCuentaTiempo;

int sizeOfBuffer;

//Contraseña
String bufferLectura = "";//para la contraseña
String password = "9876";

void setup() {
  Serial.begin(9600);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  digitalWrite(ledVerde, HIGH);
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
  }else if(millis() - inicioCuentaTiempo >= 5000 && isOpened){
        isOpened = false;
        digitalWrite(ledRojo, LOW);
        digitalWrite(ledVerde, HIGH);
        bufferLectura = ""; // reinicio del buffer
        sizeOfBuffer = 0;
        Serial.println("Pasaron 5 segundos -> puerta CERRADA");
  }else if(teclaPulsada == 'C'&& isOpened){
        isOpened = false;
        Serial.println("Tecla pulsada: C -> puerta CERRADA");
        digitalWrite(ledRojo, LOW);
        digitalWrite(ledVerde, HIGH);
        bufferLectura = ""; // reinicio del buffer
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
