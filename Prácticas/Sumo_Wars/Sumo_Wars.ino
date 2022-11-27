#include <Servo.h>

//Motores
Servo servoLeft; 
Servo servoRight;

int pinServoLeft = 8; 
int pinServoRight = 9;

//ultrasonidos
int pinTrig = 4;
int pinEcho = 5;

//Línea
int NO_LINE = LOW; // También podría ponerse 0 
int LINE = HIGH; // También podría ponerse 1

//Direcciones izquierda y derecha
int pinIrDer = 3; 
int pinIrIzq = 2;

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
    goBackward();
    delay(300);
    turnAroundLeft();
  }else if(digitalRead(pinIrIzq) == LINE && digitalRead(pinIrDer) == NO_LINE){
    turnAroundRight();
  }else if(digitalRead(pinIrIzq) == NO_LINE && digitalRead(pinIrDer) == LINE){
    turnAroundLeft();
  }else if(digitalRead(pinIrIzq) == NO_LINE && digitalRead(pinIrDer) == NO_LINE){
    while(!detectarObstaculo()){
      turnAroundLeft();
    }
  }
}

void goBackward(){
  // Adelante
  servoLeft.write(180); // Velocidad Máxima 
  servoRight.write(0);
}

void goForward(){
  // Atrás
  servoLeft.write(0);
  servoRight.write(180);
}

void stopMovement(){
  // Detener
  servoLeft.write(90);  
  servoRight.write(90); 
}

void turnAroundLeft(){
  servoLeft.write(180);
  servoRight.write(180);
  delay(750);
  goForward();
  delay(200);
}

void turnAroundRight(){
  servoLeft.write(0);
  servoRight.write(0);
  delay(750);
  goForward();
  delay(200);
}

bool detectarObstaculo(){
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(10);
  digitalWrite(pinTrig, HIGH);//enviamos el pulso
  delayMicroseconds(10);
  long responseTime = 0;
  pulseIn(pinEcho, HIGH);// Medimos la longitud
  long distance = 0.01716*responseTime;// Calculamos la distancia una vez conocemos la velocidad
  delay(100);
  return distance <= 4;
}
