// C++ code
// GRUPO B3
// Mateo Rico Iglesias
// Chen Xin Pan Wang
// Eduardo Blanco Bielsa

//LEDS
//semáforo 1
int green1 = 11;
int blue1 = 12;
int red1 = 10;
//semáforo 2
int green2 = 8;
int blue2 = 9;
int red2 = 7;
//peatones
int greenP = 6;
int redP = 5;

int verde = 1;
int amarillo = 2;
int rojo = 3;

int delayVerdeRojo = 1000;
int delayPeatones = 1000;
int delayAmarillo = 500;

//COLORES
int r = 0;
int g = 0;
int b = 0;

//BUZZER
int pinbuzzer = 4;
int valorBuzzer = 600;

int contRojo = 1;//variable auxiliar para evitar la repetición innecesaria de pitidos

void setup(){
  Serial.begin(9600);
  pinMode(red1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(blue1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(blue2, OUTPUT);
  pinMode(greenP, OUTPUT);
  pinMode(redP, OUTPUT);
  analogWrite(red1, r);
  analogWrite(green1, g);
  analogWrite(blue1, b);
  analogWrite(red2, r);
  analogWrite(green2, g);
  analogWrite(blue2, b);
  pinMode(pinbuzzer, OUTPUT);
}

void loop(){
  //SEM 1 verde
  //SEM 2 rojo
  circuitoSemaforos(verde,rojo,delayVerdeRojo);
  
  //SEM 1 amarillo
  //SEM 2 rojo
  circuitoSemaforos(amarillo,rojo,delayAmarillo);

  //SEM 1 rojo
  //SEM 2 verde
  circuitoSemaforos(rojo,verde,delayVerdeRojo);

  //SEM 1 rojo
  //SEM 2 amarillo
  circuitoSemaforos(rojo,amarillo,delayVerdeRojo);
}

void circuitoSemaforos(int act1, int act2, int delaySemaforo){
  //leds activados
  habilitarSemaforo1(act1);
  if(act1 == amarillo){//si el sem1 está en rojo, pita para los ciegos
    if(contRojo == 1){
      parpadeoLedVerdePeatones();
    }
  }if(act2 == verde){//si el sem2 está en verde, pone en rojo para peatones
    desactivarSemaforoPeatones();
    contRojo++;
  }if(act1 == verde && act2 == rojo){//si el sem1 está en verde y el sem2 en rojo, se pone verde el paso peatonal
    activarSemaforoPeatones();
  }if(act2 == amarillo){
    contRojo--;
  }
  //El semáforo 2 es el que tiene paso para peatones
  habilitarSemaforo2(act2);
  delay(delaySemaforo);
}

void habilitarSemaforo1(int color){
  if(color == verde){//verde
    r = 0;
    g = 255;
    b = 0;
  }else if(color == amarillo){//amarillo
    r = 255;
    g = 255;
    b = 0;
  }else{//rojo
    r = 255;
    g = 0;
    b = 0;
  }
  asignarColoresSemaforo1();
}

void habilitarSemaforo2(int color){
  if(color == verde){//verde
    r = 0;
    g = 255;
    b = 0;
  }else if(color == amarillo){//amarillo
    r = 255;
    g = 255;
    b = 0;
  }else{//rojo
    r = 255;
    g = 0;
    b = 0;
  }
  asignarColoresSemaforo2();
}

void asignarColoresSemaforo1(){
  analogWrite(red1, r);
  analogWrite(green1, g);
  analogWrite(blue1, b);
}

void asignarColoresSemaforo2(){
  analogWrite(red2, r);
  analogWrite(green2, g);
  analogWrite(blue2, b);
}

void activarSemaforoPeatones(){
  delay(1000); //espera x segundos después de que se ponga en rojo el semaforo 2
  digitalWrite(redP, LOW);
  digitalWrite(greenP, HIGH);
}

void desactivarSemaforoPeatones(){
  mutearBuzzer();
  digitalWrite(redP, HIGH);
  digitalWrite(greenP, LOW);
}

void hacerSonarBuzzer(){
    tone(pinbuzzer, valorBuzzer);
}

void mutearBuzzer(){
   noTone(pinbuzzer);
}

void parpadeoLedVerdePeatones(){
  for(int i = 0; i < 20; i++){
    digitalWrite(greenP, HIGH);
    hacerSonarBuzzer();
    delay(100);
    mutearBuzzer();
    delay(100);
  }
}
