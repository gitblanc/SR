//PINES LED
int red = 2;
int green = 3;

// Random
int pinForRandom = A0;
int randomNum = 0;

// Pines pulsadores
// Pulsador para el led rojo
int pinPulsadorR = 4;
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
  pinMode(pinPulsadorR, INPUT_PULLUP);
  pinMode(pinPulsadorG, INPUT_PULLUP);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  randomSeed(analogRead(pinForRandom));
  
}

void loop() {
  if(ronda == 1){
      generaSecuencia();
      muestraSecuencia();
      leeSecuencia();
   }
   if(ronda != 1){
      muestraSecuencia();
      leeSecuencia();
   }
}

void generaSecuencia(){
   for(int i = 0; i < MAX; i++){
      initialSequence[i] = generateRandom(2,4);
     	Serial.println(initialSequence[i]);
   }
  
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

void leeSecuencia() {
  valorPulsadorR = digitalRead(pinPulsadorR);
  valorPulsadorG = digitalRead(pinPulsadorG);

  for(int i = 0; i < ronda; i++) {

    while(pushedG == 0 || pushedR == 0) {
      if(valorPulsadorR == HIGH && pushedR == 0) {
        digitalWrite(red, HIGH);
        userSequence[i] = red;
        pushedR = 1;
        delay(200);
        if(userSequence[i] != initialSequence[i]) {
        	error();
            return;
        }
        digitalWrite(red, LOW);
      }

      if(valorPulsadorG == HIGH && pushedG == 0) {
        digitalWrite(green, HIGH);
        userSequence[i] = green;
        pushedG = 1;
        delay(200);
        if(userSequence[i] != initialSequence[i]) {
          error();
          return;
        }
        digitalWrite(green, LOW);
      }
    }
    
    if(valorPulsadorR == LOW && pushedR == 1) {
      pushedR = 0;
    } 
    
    if(valorPulsadorG == LOW && pushedG ==1) {
      pushedG = 0;
    }
  }
  gana();
}

void gana() {
  if(ronda < MAX) {
      ronda++;
  } 
  if(ronda == MAX) {
    digitalWrite(green, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(green, LOW);
    Serial.println("Fin juego");
  }
}

void error() {
  digitalWrite(red, HIGH);
  digitalWrite(red, LOW);
  digitalWrite(red, HIGH);
  digitalWrite(red, LOW);
  digitalWrite(red, HIGH);
  digitalWrite(red, LOW);
  
  ronda = 1;
}