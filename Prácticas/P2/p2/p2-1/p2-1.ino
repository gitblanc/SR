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

String bufferLectura = "";

void setup() {
  Serial.begin(9600);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledRojo, OUTPUT);
}

void loop() {
  digitalWrite(ledVerde, HIGH);
  int pushed = 0;
  char teclaPulsada = teclado.getKey();
  if(teclaPulsada == 'A' && pushed == 0){
      pushed = 1;
      Serial.println("Tecla pulsada: A");
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledRojo, HIGH);
      delay(5000);
      digitalWrite(ledRojo, LOW);
      digitalWrite(ledVerde, HIGH);
  }
  pushed = 0;
}
