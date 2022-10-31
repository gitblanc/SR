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

int contEspiral = 91;

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
  if(digitalRead(pinIrIzq) == LINE && digitalRead(pinIrDer) == LINE){
    goForward();
    contEspiral = 91;
  }else if(digitalRead(pinIrIzq) == LINE && digitalRead(pinIrDer) == NO_LINE){
    left();
    contEspiral = 91;
  }else if(digitalRead(pinIrIzq) == NO_LINE && digitalRead(pinIrDer) == LINE){
    right();
    contEspiral = 91;
  }else if(digitalRead(pinIrIzq) == NO_LINE && digitalRead(pinIrDer) == NO_LINE){
    espiral();
    sumarContador();
  }
}

void sumarContador(){
  contEspiral++;
  delay(1000);
}

void goForward(){
  // Adelante
  servoLeft.write(180); // Velocidad Máxima 
  servoRight.write(0);
  
}

void goBackward(){
  // Atrás
  servoLeft.write(0);
  servoRight.write(180);
  
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

void espiral(){
   servoLeft.write(contEspiral); 
   servoRight.write(0);
}
