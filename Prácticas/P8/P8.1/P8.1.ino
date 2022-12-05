#include <Servo.h>

//Motores
Servo servoLeft; 
Servo servoRight;

int pinServoLeft = 8; 
int pinServoRight = 9;

//Línea
int NO_LINE = LOW; // También podría ponerse 0 
int LINE = HIGH; // También podría ponerse 1

//Direcciones izquierda y derecha
int pinIrDer = 3; 
int pinIrIzq = 2;
int pinMasIzq = 10;
int pinMasDer = 11;

void setup(){ 
  Serial.begin(9600); // Descomentar si queréis debuguear por consola 
  pinMode(pinIrDer, INPUT);
  pinMode(pinIrIzq, INPUT);
  servoLeft.attach(pinServoLeft); 
  servoRight.attach(pinServoRight);
}
void loop() {
  detectarLinea();
}

void detectarLinea(){
  if(digitalRead(pinIrIzq) == LINE && digitalRead(pinIrDer) == LINE && (digitalRead(pinMasIzq) == NO_LINE && digitalRead(pinMasDer) == NO_LINE)){
    goForward();
  }else if(digitalRead(pinIrIzq) == LINE && digitalRead(pinIrDer) == NO_LINE){
    right();
  }else if(digitalRead(pinIrIzq) == NO_LINE && digitalRead(pinIrDer) == LINE){
    left();
  }

  else if(digitalRead(pinMasIzq) == NO_LINE && digitalRead(pinMasDer) == LINE){
    right90();
  }else if(digitalRead(pinMasIzq) == LINE && digitalRead(pinMasDer) == NO_LINE){
    left90();
  }



  else if(digitalRead(pinIrIzq) == NO_LINE && digitalRead(pinIrDer) == NO_LINE){
    stopMovement();
  }
}

void left90(){
   servoLeft.write(180); 
   servoRight.write(0);
   delay(750);
}

void right90(){
   servoLeft.write(180); 
   servoRight.write(90); 
   delay(750);
}

void goForward(){
  // Adelante
  //servoLeft.write(180); // Velocidad Máxima 
  //servoRight.write(0);
  
  servoLeft.write(0); //Simulador
  servoRight.write(180);  
}

void goBackward(){
  // Atrás
  //servoLeft.write(0);
  //servoRight.write(180);

  servoLeft.write(180); //Simulador
  servoRight.write(0);  
}

void stopMovement(){
  // Detener
  servoLeft.write(90);  
  servoRight.write(90); 
   
}

void left(){
   servoLeft.write(90); 
   servoRight.write(0);   
}

void right(){
   servoLeft.write(180); 
   servoRight.write(90);  
}
