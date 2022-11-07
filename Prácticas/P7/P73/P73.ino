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

//int contEspiral = 91;
int contEspiral = 89;

//ultrasonidos
int pinTrig = 4;
int pinEcho = 5;

bool estaEsquivando = false;

void setup(){ 
  Serial.begin(9600); // Descomentar si queréis debuguear por consola 
  pinMode(pinIrDer, INPUT);
  pinMode(pinIrIzq, INPUT);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  servoLeft.attach(pinServoLeft); 
  servoRight.attach(pinServoRight);
  ultrasonidos();
}
void loop() {
  detectarLinea();
}

bool detectarObstaculo(){
  long distance = ultrasonidos();
  return distance <= 20;
 }

void detectarLinea(){
  if(digitalRead(pinIrIzq) == LINE && digitalRead(pinIrDer) == LINE){
    if(detectarObstaculo()){
      rodearObstaculo();
    }else{
      goForward();
    }
    //contEspiral = 91;
    contEspiral = 89;
  }else if(digitalRead(pinIrIzq) == LINE && digitalRead(pinIrDer) == NO_LINE){
    left();
    //contEspiral = 91;
    contEspiral = 89;
  }else if(digitalRead(pinIrIzq) == NO_LINE && digitalRead(pinIrDer) == LINE){
    right();
    //contEspiral = 91;
    contEspiral = 89;
  }else if(digitalRead(pinIrIzq) == NO_LINE && digitalRead(pinIrDer) == NO_LINE){
    if(detectarObstaculo()){
      rodearObstaculo();
    }else if(estaEsquivando){
      estaEsquivando = false;
      recuperarLinea();
    }else{
      espiral();
      sumarContador();
    }
  }
}

void recuperarLinea(){
  goForward();
  delay(2000);
  right();
  delay(1200);
  goForward();
  delay(3000);
  right();
  delay(1200);
}

void sumarContador(){
  //contEspiral++;
  contEspiral--;
  delay(1000);
}

void goForward(){
  // Adelante
  //servoLeft.write(180); // Velocidad Máxima 
  //servoRight.write(0);
  servoLeft.write(0);
  servoRight.write(180);
  
}

void goBackward(){
  // Atrás
  //servoLeft.write(0);
  //servoRight.write(180);
  servoLeft.write(180);
  servoRight.write(0);
}

void stopMovement(){
  // Detener
  servoLeft.write(90);  
  servoRight.write(90); 
   
}

void left(){
   //servoLeft.write(90); 
   //servoRight.write(0); 
   servoLeft.write(90); 
   servoRight.write(180); 
}

void right(){
   //servoLeft.write(180); 
   //servoRight.write(90); 
   servoLeft.write(0); 
   servoRight.write(90);  
}

void espiral(){
   //servoLeft.write(contEspiral); 
   //servoRight.write(0);
   servoLeft.write(contEspiral); 
   servoRight.write(180);
}

void rodearObstaculo(){
  estaEsquivando = true;
  left();
  delay(1500);
  goForward();
  delay(2000);
  right();
  delay(1000);
  detectarLinea();
}

long ultrasonidos(){
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(10);
  digitalWrite(pinTrig, HIGH);//enviamos el pulso
  delayMicroseconds(10);
  long responseTime = pulseIn(pinEcho, HIGH);// Medimos la longitud
  //Serial.println("Tiempo: " + String(responseTime) + " microsegundos");
  long distance = 0.01716*responseTime;// Calculamos la distancia una vez conocemos la velocidad
  delay(100);
  return distance;
}
