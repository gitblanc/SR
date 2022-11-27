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
int initialPulsador[3];

// Ronda de partida
int ronda = 0;
int maxRound = 3;

// Método para generar números random
int generateRandom(int from, int to){
  return random(from, to);  
}

// Método para mostrar la secuencia obtenida
void showInitialSequence(){
  for(int i = 0; i < sizeof(initialSequence); i++){
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
  ronda = ronda + 1;  
  initialPlay();
}

void showSequence(){
  if(ronda != maxRound) {
    int sequence[sizeof(initialSequence +1)];
    for(int i = 0; i < sizeof(initialSequence +1) ; i++) {
      sequence[i] = initialSequence[i];
    }
    sequence[sizeof(initialSequence +1)] = (generateRandom(1,2));
    ronda = ronda +1;
    for(int i = 0; i < sizeof(sequence); i++) {
      if (initialSequence[i] == 1){
      	digitalWrite(red, HIGH);
      	delay(1000);
      	digitalWrite(red, LOW);
     	delay(1000);
    	}	else{
      	digitalWrite(green, HIGH); 
      	delay(1000); 
      	digitalWrite(green, LOW); 
      	delay(1000);
    	}
    }
  }
  play();
}

boolean play(){
    Serial.println("Empieza el juego");
  	Serial.begin(1000);
  
}

boolean initialPlay() {
  
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
    Serial.println(initialSequence[i]);
  }
}

void loop() {
  if (ronda == 0) {
    showInitialSequence();
 	play();
  } else {
      showSequence();
  }
 }

