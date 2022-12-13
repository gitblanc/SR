// C++ code
// GRUPO B3
// Mateo Rico Iglesias
// Chen Xin Pan Wang
// Eduardo Blanco Bielsa

// Pins leds
int led1 = 2;
int led2 = 3;
int led3 = 4;

// Random
int pinForRandom = A0;
int randomNum = 0;

// Pin pulsador
int pinPulsador = 5;
int valorPulsador = 0;
int pushed = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(pinPulsador, INPUT_PULLUP);
  
  randomSeed(analogRead(pinForRandom));
}

void loop()
{
  valorPulsador = digitalRead(pinPulsador);
  if (valorPulsador == HIGH && pushed == 0) {
    // Si detecta que pulsamos el pulsador imprime por el monitor serie "pulsado".
    // se ha pulsado
    pushed = 1;
    // Número random entre 1 y 3
    randomNum = random(1,4);
    Serial.println(randomNum);
    if(randomNum == 2){
      digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
    }else if(randomNum == 1){
      digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
    }else{
      digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
    }
  }else if (valorPulsador == LOW && pushed == 1){
      pushed = 0;
  }
}
