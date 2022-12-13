// C++ code
// GRUPO B3
// Mateo Rico Iglesias
// Chen Xin Pan Wang
// Eduardo Blanco Bielsa

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

void setup() {
  Serial.begin(9600);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  digitalWrite(ledVerde, HIGH);
}

void loop() {
  char teclaPulsada = teclado.getKey();
  if(teclaPulsada == 'A'&& !isOpened){
      inicioCuentaTiempo = millis();//empieza el contador
      isOpened = true;
      Serial.println("Tecla pulsada: A -> puerta ABIERTA");
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledRojo, HIGH);
      
  }else if(millis() - inicioCuentaTiempo >= 5000 && isOpened){
      isOpened = false;
      digitalWrite(ledRojo, LOW);
      digitalWrite(ledVerde, HIGH);
    }else if(teclaPulsada == 'C'&& isOpened){
      isOpened = false;
      Serial.println("Tecla pulsada: C -> puerta CERRADA");
      digitalWrite(ledRojo, LOW);
      digitalWrite(ledVerde, HIGH);
    
  }
}
