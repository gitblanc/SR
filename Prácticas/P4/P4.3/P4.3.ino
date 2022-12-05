#include <Servo.h>
//2.-
Servo servo;
int boton_pin = 7; // Pin digital para el botón
int X_pin = A0; // Pin analógico para leer eje X
int pinChoqueIzquierda = 11;
int pinChoqueDerecha = 4;

void setup(){
 Serial.begin(9600);
 servo.attach(8);
 pinMode(boton_pin, INPUT_PULLUP);
 pinMode(pinChoqueIzquierda, INPUT);
 pinMode(pinChoqueDerecha, INPUT);
}
void loop(){
  int movimientoJoystickX = detectarJoystick();
  Serial.println(movimientoJoystickX);
 if ((movimientoJoystickX > 490 && movimientoJoystickX < 530) || !digitalRead(pinChoqueDerecha) || !digitalRead(pinChoqueIzquierda)) {
    servo.write(90);
    if(!digitalRead(pinChoqueDerecha)){
      servo.write(88);
      delay(10);
      servo.write(90);
    } else if(!digitalRead(pinChoqueIzquierda)){
      servo.write(92);
      delay(10);
      servo.write(90);
    }
 }else if(movimientoJoystickX < 490 && movimientoJoystickX > 150){
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
