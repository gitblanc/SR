#include <Servo.h>
//2.-
Servo servo;
int boton_pin = 7; // Pin digital para el botón
int X_pin = A0; // Pin analógico para leer eje X
int Y_pin = A1; // Pin analógico para leer eje Y
int movimientoJoystickX = 90;
int movimientoJoystickY = 90;
void setup(){
 //3.-
 Serial.begin(9600);
 servo.attach(8);
 pinMode(boton_pin, INPUT);
}
void loop(){
 detectarJoystick();
 servo.write(movimientoJoystickX);
}

void detectarJoystick(){
 movimientoJoystickX = analogRead(X_pin);
 Serial.println(movimientoJoystickX);
 movimientoJoystickY = analogRead(Y_pin);
 delay(100);

}
