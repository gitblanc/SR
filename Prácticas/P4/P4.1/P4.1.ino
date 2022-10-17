#include <Servo.h>
//2.-
Servo servo;
int boton_pin = 7; // Pin digital para el botón
int X_pin = A0; // Pin analógico para leer eje X

void setup(){
 Serial.begin(9600);
 servo.attach(8);
 pinMode(boton_pin, INPUT_PULLUP);
}
void loop(){
  int movimientoJoystickX = detectarJoystick();
  Serial.println(movimientoJoystickX);
 if(movimientoJoystickX < 490){
  Serial.println("Izquierda");
   girarIzquierda();
 } else if(movimientoJoystickX > 530){
   Serial.println("Derecha");
   girarDerecha();
 } else if (movimientoJoystickX > 490 && movimientoJoystickX < 530) {
    servo.write(90);
 }
}
int detectarJoystick(){
 return analogRead(X_pin);
}
