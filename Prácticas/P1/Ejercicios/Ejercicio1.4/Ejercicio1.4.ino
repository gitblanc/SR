// C++ code
// GRUPO B3
// Mateo Rico Iglesias
// Chen Xin Pan Wang
// Eduardo Blanco Bielsa

//LEDS
//semáforo 1
int green1 = 13;
int yellow1 = 12;
int red1 = 11;
//semáforo 2
int green2 = 7;
int yellow2 = 6;
int red2 = 5;

int verde = 1;
int amarillo = 2;
int rojo = 3;

int delayVerdeRojo = 3000;
int delayAmarillo = 1500;

void setup(){
  Serial.begin(9600);
  pinMode(red1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(yellow2, OUTPUT);
}

void loop(){
  //SEM 1 verde
  //SEM 2 rojo
  circuitoSemaforos(verde,rojo,amarillo,rojo,verde,amarillo,delayVerdeRojo);
  
  //SEM 1 amarillo
  //SEM 2 rojo
  circuitoSemaforos(amarillo,rojo,verde,rojo,verde,amarillo,delayAmarillo);

  //SEM 1 rojo
  //SEM 2 verde
  circuitoSemaforos(rojo,verde,amarillo,verde,rojo,amarillo,delayVerdeRojo);

  //SEM 1 rojo
  //SEM 2 amarillo
  circuitoSemaforos(rojo,amarillo,amarillo,verde,rojo,verde,delayVerdeRojo);
}

void circuitoSemaforos(int act1, int act2, int des11, int des12, int des21, int des22, int delaySemaforo){
  //leds activados
  habilitarSemaforo1(act1);
  habilitarSemaforo2(act2);
  //leds desactivados
  //--SEMAFORO 1---
  deshabilitarSemaforo1(des11);
  deshabilitarSemaforo1(des12);
  //--SEMAFORO 2---
  deshabilitarSemaforo2(des21);
  deshabilitarSemaforo2(des22);
  delay(delaySemaforo);
}

void habilitarSemaforo1(int color){
  if(color == verde){//verde
    digitalWrite(green1, HIGH);
  }else if(color == amarillo){//amarillo
    digitalWrite(yellow1, HIGH);
  }else{//rojo
    digitalWrite(red1, HIGH);
  }
}

void deshabilitarSemaforo1(int color){
  if(color == verde){//verde
    digitalWrite(green1, LOW);
  }else if(color == amarillo){//amarillo
    digitalWrite(yellow1, LOW);
  }else{//rojo
    digitalWrite(red1, LOW);
  }
}

void habilitarSemaforo2(int color){
  if(color == verde){//verde
    digitalWrite(green2, HIGH);
  }else if(color == amarillo){//amarillo
    digitalWrite(yellow2, HIGH);
  }else{//rojo
    digitalWrite(red2, HIGH);
  }
}

void deshabilitarSemaforo2(int color){
  if(color == verde){//verde
    digitalWrite(green2, LOW);
  }else if(color == amarillo){//amarillo
    digitalWrite(yellow2, LOW);
  }else{//rojo
    digitalWrite(red2, LOW);
  }
}
