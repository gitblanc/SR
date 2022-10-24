#include <Servo.h>
//2.-
Servo servo;
int boton_pin = 7; // Pin digital para el botón
int X_pin = A0; // Pin analógico para leer eje X
int pinServo = 8; //Pin digital servo motor
int pinChoqueIzquierda = 11;
int pinChoqueDerecha = 4;
int modo = 2;
bool izquierda;
bool derecha;
bool pushed;

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
  Serial.println(modo);
  if(modo == 2) {
    cambiarModo();
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
       girarIzquierdaRapido();
     } else if(movimientoJoystickX < 150){
          girarIzquierdaRapido();
     } 
     else if(movimientoJoystickX > 530 && movimientoJoystickX < 900){
       Serial.println("Derecha");
       girarDerechaRapido();
     } else if(movimientoJoystickX > 900){
          girarDerechaRapido();
     } 
  } else if (modo == 1){
    cambiarModo();
    if(!pushed){
      girarIzquierdaRapido();
      modoAutomatico();
      pushed = true;
    }
     if(izquierda && pushed){
       Serial.println("Izquierda");
       girarIzquierdaRapido();
       modoAutomatico();
     } 
     else if(derecha && pushed){
       Serial.println("Derecha");
       girarDerechaRapido();
       modoAutomatico();
     }
  }
}

void modoAutomatico(){
 if(!digitalRead(pinChoqueIzquierda)){
    girarDerechaRapido();
 }
 else if(!digitalRead(pinChoqueDerecha)){
    girarIzquierdaRapido();
 }
}

void cambiarModo(){
  if(digitalRead(boton_pin) == LOW && modo == 1){
    modo = 2;
    pushed = false;
    delay(1000);
  } else if (digitalRead(boton_pin) == LOW && modo == 2) {
    modo = 1;
    delay(1000);
  }
}

void girarIzquierdaRapido(){
  izquierda = true;
  derecha = false;
  servo.write(0);
}

void girarIzquierdaLento(){
  izquierda = true;
  derecha = false;
  servo.write(85);
}

void girarDerechaRapido(){
  izquierda = false;
  derecha = true;
  servo.write(180);
}

void girarDerechaLento(){
  izquierda = false;
  derecha = true;
  servo.write(95);
}
int detectarJoystick(){
 return analogRead(X_pin);
}
