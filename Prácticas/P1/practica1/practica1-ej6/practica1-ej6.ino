//LEDS
//led 1 izq
int green1 = 12;
int blue1 = 11;
int red1 = 10;
//led 2 der
int green2 = 9;
int blue2 = 8;
int red2 = 7;

//BUZZER
int pinbuzzer = 6;
int minBuzzer = 0;
int maxBuzzer = 600;

//POTENCIOMETROS
int p1 = A2;
int p2 = A3;

void setup(){
  Serial.begin(9600);
  pinMode(red1, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(blue1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(blue2, OUTPUT);
  pinMode(pinbuzzer, OUTPUT);
}

void loop(){
  int frecuencia = map(analogRead(p2), 0, 1023, minBuzzer, maxBuzzer);
  int pot1Value = analogRead(p1);
  hacerSonarBuzzer(frecuencia);
  if(pot1Value<=40){//apagado,blanco
       asignarLed1(0,0,0);
       asignarLed2(255,255,255);
  }else if(pot1Value <= 255){//rojo,azul
    asignarLed1(pot1Value,0,0);
    asignarLed2(0,pot1Value,0);
  }else if(pot1Value <= 400){//morado, rosa
    asignarLed1(255,255,0);
    asignarLed2(255,20,0);
  }else if(pot1Value <= 510){//verde,verde
    asignarLed1(0,0,pot1Value);
    asignarLed2(0,0,pot1Value);
  }else if(pot1Value <= 610){//verde,amarillo
    asignarLed1(0,0,pot1Value);
    asignarLed2(pot1Value,0,pot1Value);
  }else if(pot1Value <= 765){//amarillo,verde
    asignarLed1(pot1Value,0,pot1Value);
    asignarLed2(0,0,pot1Value);
  }else if(pot1Value <= 850){//morado,rosa
    asignarLed1(pot1Value,pot1Value,0);
    asignarLed2(pot1Value,20,0);
  }else if(pot1Value <= 950){//azul,rojo
    asignarLed1(0,pot1Value,0);
    asignarLed2(pot1Value,0,0);
  }else if(pot1Value <= 1000){
    asignarLed1(pot1Value,pot1Value,pot1Value);
    asignarLed2(0,0,0);
  }
}


void asignarLed1(int r, int g, int b){
  digitalWrite(green1, g);
  digitalWrite(blue1, b);
  digitalWrite(red1, r);
}

void asignarLed2(int r, int g, int b){
  digitalWrite(green2, g);
  digitalWrite(blue2, b);
  digitalWrite(red2, r);
}

void hacerSonarBuzzer(int frecuencia){
    if(frecuencia <= 10){
      mutearBuzzer();
    }else{
      tone(pinbuzzer, frecuencia);
    }
}

void mutearBuzzer(){
   noTone(pinbuzzer);
}
