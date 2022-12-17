// C++ code
// GRUPO B3
// Mateo Rico Iglesias
// Chen Xin Pan Wang
// Eduardo Blanco Bielsa

//PINES LED
int red = 2;
int green = 3;

// Random
int pinForRandom = A0;
int randomNum = 0;

// Pines pulsadores
// Pulsador para el led rojo
int pinPulsadorR = 6;
int valorPulsadorR = 0;
int pushedR = 0;
// Pulsador para el led verde
int pinPulsadorG = 5;
int valorPulsadorG = 0;
int pushedG = 0;

int ronda = 3;

const int MAX = 5;
int initialSequence[MAX];
int userSequence[MAX];

// Método para generar números random
int generateRandom(int from, int to){
  randomSeed(millis());
  return random(from, to);  
}

void setup(){
  Serial.begin(9600);
  pinMode(pinPulsadorR, INPUT_PULLUP);
  pinMode(pinPulsadorG, INPUT_PULLUP);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  randomSeed(analogRead(pinForRandom));
}

void loop() {
   Serial.print("Ronda de juego: ");
   Serial.println(ronda-2);
   if(ronda == 3){
      generaSecuencia();
      muestraSecuencia();
      leeSecuencia();
   }else if(ronda != 3){
      muestraSecuencia();
      leeSecuencia();
   }
}

void generaSecuencia(){
  Serial.print("Sequencia: ");
   for(int i = 0; i < MAX; i++){
      int x = generateRandom(2,4);
      initialSequence[i] = x;
      Serial.print(x);
      Serial.print(" ");
   }
  Serial.println();
}

void muestraSecuencia(){
  for(int i = 0; i < ronda; i++) {
      if (initialSequence[i] == 2){
        digitalWrite(red, HIGH);
        delay(1000);
        digitalWrite(red, LOW);
        delay(1000);
    }else{
      digitalWrite(green, HIGH); 
      delay(1000); 
      digitalWrite(green, LOW); 
      delay(1000);
    }
  }
}

void leerValorespines(){
  valorPulsadorR = digitalRead(pinPulsadorR);
    valorPulsadorG = digitalRead(pinPulsadorG);
}

void leeSecuencia() {
  pushedR = 0;
  pushedG = 0;
  int contRound = 0;
  while(contRound < ronda){
    leerValorespines();
    if(valorPulsadorR == HIGH && valorPulsadorG == LOW) {
        digitalWrite(red, HIGH);
        delay(500);
        digitalWrite(red, LOW);
        userSequence[contRound] = red;
        Serial.println(userSequence[contRound]);
        pushedR++;
        if(userSequence[contRound] != initialSequence[contRound]) {
          error();
            return;
        }
        contRound++;
    }else if(valorPulsadorG == HIGH && valorPulsadorR == LOW) {
        digitalWrite(green, HIGH);
        delay(500);
        digitalWrite(green, LOW);
        userSequence[contRound] = green;
        Serial.println(userSequence[contRound]);
        pushedG++;
        if(userSequence[contRound] != initialSequence[contRound]) {
          error();
          return;
        }
        contRound++;
    }
  }
  gana();
  return;
}

void gana() {
  if(ronda < MAX) {
      Serial.println("Ganaste la ronda :)");
      ronda++;
  }else if(ronda == MAX) {
    digitalWrite(green, HIGH);
    delay(500);
    digitalWrite(green, LOW);
    delay(500);
    digitalWrite(green, HIGH);
    delay(500);
    digitalWrite(green, LOW);
    delay(500);
    digitalWrite(green, HIGH);
    delay(500);
    digitalWrite(green, LOW);
    delay(500);
    Serial.println("Ganaste el juego :)");
    ronda = 3;
  }
  pushedR = 0;
  pushedG = 0;
}

void error() {
  Serial.println("Has perdido :(");
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(red, LOW);
  delay(500);
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(red, LOW);
  delay(500);
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(red, LOW);
  delay(500);
  
  ronda = 3;
}
