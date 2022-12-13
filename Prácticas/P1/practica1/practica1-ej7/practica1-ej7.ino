// C++ code
// GRUPO B3
// Mateo Rico Iglesias
// Chen Xin Pan Wang
// Eduardo Blanco Bielsa

//LEDS
int ledA = 4;
int ledB = 3;
int ledC = 2;

//POTENCIOMETROS
int p1 = A2;

void setup(){
  Serial.begin(9600);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
}

void loop(){
  int pot1Value = analogRead(p1);
  if(pot1Value<=40){
    encenderLeds(LOW,LOW,LOW);//NINGUNO
       
  }else if(pot1Value <= 255){
    encenderLeds(HIGH,LOW,LOW);//A
    
  }else if(pot1Value <= 400){
    encenderLeds(LOW,HIGH,LOW);//B
    
  }else if(pot1Value <= 510){
    encenderLeds(LOW,LOW,HIGH);//C
    
  }else if(pot1Value <= 610){
    encenderLeds(HIGH,HIGH,LOW);//AB
    
  }else if(pot1Value <= 765){
    encenderLeds(LOW,HIGH,HIGH);//BC
    
  }else if(pot1Value <= 850){
    encenderLeds(HIGH,LOW,HIGH);//AC
    
  }else if(pot1Value <= 950){
    encenderLeds(HIGH,HIGH,HIGH);//ABC
  }
}

void encenderLeds(int a, int b, int c){
  digitalWrite(ledA, a);
  digitalWrite(ledB, b);
  digitalWrite(ledC, c);
}
