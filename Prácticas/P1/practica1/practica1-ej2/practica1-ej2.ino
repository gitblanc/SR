//C++
// Pines leds
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

// Estructura de datos
int initialSequence[3];

// Ronda de partida
int round = 0;

// Método para generar números random
int generateRandom(int from, int to){
  return random(from, to);  
}

// Método para mostrar la secuencia obtenida
void showInitialSequence(){
  for(int i = 0; i < 3; i++){
    if (initialSequence[i] == 1){
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
  round = 1;  
}

void showSequence(){
    
}

boolean play(){
    
}

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(pinPulsadorR, INPUT_PULLUP);
  pinMode(pinPulsadorG, INPUT_PULLUP);
  randomSeed(analogRead(pinForRandom));
  //int len = sizeof(initialSequence);
  // Secuencia inicial
  for(int i = 0; i < 3; i++){
    // Se crea una sequencia de led 1 o 2 random
    initialSequence[i] = generateRandom(1,3);   
    //Serial.println(initialSequence[i]);
  }
}

void loop() {
    if (round == 0)
      showInitialSequence();
    else
      showSequence();
    play();
  }

}
