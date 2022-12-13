// C++ code
// GRUPO B3
// Mateo Rico Iglesias
// Chen Xin Pan Wang
// Eduardo Blanco Bielsa
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
  pinMode(pinMasIzq, INPUT);
  pinMode(pinMasDer, INPUT);
  servoLeft.attach(pinServoLeft); 
  servoRight.attach(pinServoRight);
}
void loop() {
  detectarLinea();
}

void detectarLinea(){
  if(digitalRead(pinIrIzq) == LINE && digitalRead(pinIrDer) == LINE && digitalRead(pinMasIzq) == NO_LINE && digitalRead(pinMasDer) == NO_LINE){
    goForward();
  }
  else if (digitalRead(pinIrIzq) == LINE && digitalRead(pinIrDer) == LINE && digitalRead(pinMasIzq) == LINE && digitalRead(pinMasDer) == LINE){
    Serial.println("CheckingNormal");
    checking();
  }
  else if(digitalRead(pinIrIzq) == LINE && digitalRead(pinIrDer) == LINE && digitalRead(pinMasDer) == LINE && digitalRead(pinMasIzq) == NO_LINE){
    right90();
  }
  else if(digitalRead(pinIrIzq) == LINE && digitalRead(pinIrDer) == NO_LINE && digitalRead(pinMasIzq) == NO_LINE && digitalRead(pinMasDer) == NO_LINE){
    right();
  }else if(digitalRead(pinIrIzq) == NO_LINE && digitalRead(pinIrDer) == LINE && digitalRead(pinMasIzq) == NO_LINE && digitalRead(pinMasDer) == NO_LINE){
    left();
  }
  else if(digitalRead(pinIrIzq) == NO_LINE && digitalRead(pinIrDer) == NO_LINE && digitalRead(pinMasIzq) == NO_LINE && digitalRead(pinMasDer) == NO_LINE){
    volver();
  }
  else if(digitalRead(pinIrIzq) == LINE && digitalRead(pinIrDer) == LINE && digitalRead(pinMasDer) == NO_LINE && digitalRead(pinMasIzq) == LINE){
    Serial.println("ChechingLeft");
    checkingLeft();
  }
}

void checkingLeft(){
  goForward();
  delay(400);
  if (digitalRead(pinIrIzq) == NO_LINE && digitalRead(pinIrDer) == NO_LINE && digitalRead(pinMasIzq) == NO_LINE && digitalRead(pinMasDer) == NO_LINE){
    Serial.println("left");
    goBackward();
    delay(200);
    left90NF();
  }

}

void checking(){
  goForward();
  delay(400);
  Serial.println("CHECKING");
  if (digitalRead(pinIrIzq) == LINE && digitalRead(pinIrDer) == LINE && digitalRead(pinMasIzq) == NO_LINE && digitalRead(pinMasDer) == NO_LINE){
      Serial.println("1");
      goBackward();
      delay(200);
      right90NF();
  }else if(digitalRead(pinIrIzq) == NO_LINE && digitalRead(pinIrDer) == NO_LINE && digitalRead(pinMasIzq) == NO_LINE && digitalRead(pinMasDer) == NO_LINE){
    Serial.println("2");
    goBackward();
    delay(200);
    right90NF();
  } 
  else if(digitalRead(pinIrIzq) == LINE && digitalRead(pinIrDer) == LINE && digitalRead(pinMasIzq) == LINE && digitalRead(pinMasDer) == LINE){
    Serial.println("STOP");
    stopMovement();
    exit(0);
  } 
 
}

void left90NF(){
   servoLeft.write(180); 
   servoRight.write(180); 
   delay(600);
   goForward();
   delay(190);
}

void right90NF(){
   servoLeft.write(0); 
   servoRight.write(0); 
   delay(600);
   goForward();
   delay(190);
}

void left90(){
   goForward();
   delay(200);
   servoLeft.write(180); 
   servoRight.write(180); 
   delay(600);
   goForward();
   delay(190);
}

void right90(){
   goForward();
   delay(200);
   servoLeft.write(0); 
   servoRight.write(0); 
   delay(600);
   goForward();
   delay(190);
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

void volver(){
   servoLeft.write(180);
   servoRight.write(0);
   delay(150);
   servoLeft.write(180); 
   servoRight.write(180);
   delay(1200);
}

void left(){
   servoLeft.write(90); 
   servoRight.write(0);   
}

void right(){
   servoLeft.write(180); 
   servoRight.write(90);  
}

