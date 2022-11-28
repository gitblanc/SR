//LEDS
//led 1 izq
int green1 = 10;
int blue1 = 9;
int red1 = 8;
//led 2 der
int green2 = 6;
int blue2 = 5;
int red2 = 7;
//peatones
int greenP = 6;
int redP = 5;

//BUZZER
int pinbuzzer = 12;
int valorBuzzer = 600;

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
  int pot1Value = analogRead(p1);
  Serial.println(pot1Value);
  if(pot1Value<=20){
       asignarLed1(0,0,0);
       asignarLed2(255,255,255);
  }else if(pot1Value <= 255){
    asignarLed1(0,0,pot1Value);
  }else if(pot1Value <= 510){
    asignarLed1(0,pot1Value-510,0);
  }
}

void auxiliar(){
  int pot1Value = analogRead(p1);
  if(pot1Value>=20 && pot1Value<50){
       asignarLed1(0,0,50);
  }else if(pot1Value>=50 && pot1Value<100){
       asignarLed1(0,0,100);
  }else if(pot1Value>=100 && pot1Value<150){
       asignarLed1(0,0,150);
  }else if(pot1Value>=150 && pot1Value<200){
       asignarLed1(0,0,200);
  }else if(pot1Value>=200 && pot1Value<250){
       asignarLed1(0,0,255);
  }else if(pot1Value>=250 && pot1Value<300){
       asignarLed1(0,50,50);
  }else if(pot1Value>=300 && pot1Value<350){
       asignarLed1(0,100,100);
  }else if(pot1Value>=350 && pot1Value<400){
       asignarLed1(0,150,150);
  }else if(pot1Value>=400 && pot1Value<450){
       asignarLed1(0,200,200);
  }else if(pot1Value>=450 && pot1Value<500){
       asignarLed1(0,255,255);
  }else if(pot1Value>=500 && pot1Value<550){
       asignarLed1(50,50,50);
  }else if(pot1Value>=550 && pot1Value<600){
       asignarLed1(100,100,100);
  }else if(pot1Value>=600 && pot1Value<650){
       asignarLed1(150,150,150);
  }else if(pot1Value>=650 && pot1Value<700){
       asignarLed1(200,200,200);
  }else if(pot1Value>=700 && pot1Value<750){
       asignarLed1(255,255,255);
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

void hacerSonarBuzzer(){
    tone(pinbuzzer, valorBuzzer);
}

void mutearBuzzer(){
   noTone(pinbuzzer);
}
