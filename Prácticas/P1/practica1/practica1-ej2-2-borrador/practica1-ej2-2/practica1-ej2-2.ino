//pin leds
int pinRed = 2;
int pinGreen = 3;

// Random
int pinForRandom = A0;
int randomNum = 0;

// Estructura de datos
int initialSequence[3];

// Método para generar números random
int generateRandom(int from, int to){
  return random(from, to);  
}

int rondaJuego = 0;

void showInitialSequence() {
  for(int i = 0; i < 3; i++){
      if (initialSequence[i] == 1){
        digitalWrite(pinRed, HIGH);
        delay(1000);
        digitalWrite(pinRed, LOW);
        delay(1000);
    } else{
        digitalWrite(pinGreen, HIGH); 
        delay(1000); 
        digitalWrite(pinGreen, LOW); 
        delay(1000);
    }
  }

  //se sumaria una ronda mas
  rondaJuego = rondaJuego +1;
}

void setup() {
  if(rondaJuego == 0) {
    //se inicializa la primera vez el juego
    Serial.begin(9600);
    pinMode(pinRed, OUTPUT);
    pinMode(pinGreen, OUTPUT);
    randomSeed(analogRead(pinForRandom));

    for(int i = 0; i < 3; i++){
    // Se crea una sequencia de led 1 o 2 random
    initialSequence[i] = generateRandom(1,3);   
    Serial.println(initialSequence[i]);
    }
  }

}

void loop() {
   

}
