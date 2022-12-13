// C++ code
// GRUPO B3
// Mateo Rico Iglesias
// Chen Xin Pan Wang
// Eduardo Blanco Bielsa

#include <Servo.h>
//2.-
Servo servo;
int boton_pin = 7; // Pin digital para el botón
int X_pin = A0; // Pin analógico para leer eje X
bool derecha = false;
bool izquierda = false;

void setup(){
 Serial.begin(9600);
 servo.attach(8);
 pinMode(boton_pin, INPUT_PULLUP);
}
void loop(){
  int movimientoJoystickX = detectarJoystick();
  Serial.println(movimientoJoystickX);
 if(movimientoJoystickX < 490 && movimientoJoystickX > 150){
  Serial.println("Izquierda");
   girarIzquierdaLento();
 } else if(movimientoJoystickX < 150){
      girarIzquierdaRapido();
 } 
 else if(movimientoJoystickX > 530 && movimientoJoystickX < 900){
   Serial.println("Derecha");
   girarDerechaLento();
 } else if(movimientoJoystickX > 900){
      girarDerechaRapido();
 } 
 else if (movimientoJoystickX > 490 && movimientoJoystickX < 530) {
    servo.write(90);
 }
}

void girarIzquierdaRapido(){
  servo.write(0);
}

void girarIzquierdaLento(){
  servo.write(85);
}

void girarDerechaRapido(){
  servo.write(180);
}

void girarDerechaLento(){
  servo.write(95);
}
int detectarJoystick(){
 return analogRead(X_pin);
}
