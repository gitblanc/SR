#include <Keypad.h>
#include <TM1637.h>

//Teclado
const byte nfilas = 4;
const byte ncolumnas = 4;
char teclas[nfilas][ncolumnas] = {
   {'1','2','3','A'}, 
   {'4','5','6','B'}, 
   {'7','8','9','C'},
   {'*','0','#','D'}
  };
byte pinsFilas[nfilas] = { A0, A1, A2, A3 };
byte pinsColumnas[ncolumnas] = { 7, 6, 5, 4 };

Keypad teclado = Keypad(makeKeymap(teclas), pinsFilas, pinsColumnas,
nfilas, ncolumnas);

//Pantalla de segmentos
int pinClk = 10;
int pinDio = 11;
TM1637 screen(pinClk, pinDio);
long distance;
int cont = 0;

void setup() {
  Serial.begin(9600);
  //Pantalla de segmentos
  screen.init();
  screen.set(BRIGHT_TYPICAL);
  delay(1500);//esperamos a que se inicie la pantalla
}

void loop() {
  if(cont == 0){
    distance = 0000;
    mostrarPantalla(distance);
  }
  char teclaPulsada = teclado.getKey();
  Serial.println(teclaPulsada);
  if(teclaPulsada == "1"){
    mostrarPantalla(1);
  }
}

void mostrarPantalla(int valor){
  cont++;
  distance = valor;
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
