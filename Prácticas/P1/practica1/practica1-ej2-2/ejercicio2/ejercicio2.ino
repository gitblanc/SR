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
int initialSequence[5];
int initialPulsador[5];

// Ronda de partida
int ronda = 0;
int maxRound = 3;

//iteraciones a hacer en cada ronda
int it_ronda_1 = 3;

// Método para generar números random
int generateRandom(int from, int to){
  return random(from, to);  
}

void generateSequenceLucesRonda1() {
   for(int i = 0; i < sizeof(initialSequence)-2; i++) {
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
}

void generateSequenceLucesRonda2() {
   for(int i = 0; i < sizeof(initialSequence)-1; i++) {
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
}

void generateSequenceLucesRonda3() {
   for(int i = 0; i < sizeof(initialSequence); i++) {
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
}

void secuenciaLucesIncorrecto() {
  digitalWrite(red, HIGH);
  digitalWrite(red, LOW);
  digitalWrite(red, HIGH);
  digitalWrite(red, LOW);
  digitalWrite(red, HIGH);
  digitalWrite(red, LOW);
}

void ganar() {
  digitalWrite(green, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(green, LOW);
}

void volverAEmpezar() {
  //hacer la secuencia inicial maximo de 5 (rellenarlo entero)
  for(int i = 0; i < 5; i++){
    // Se crea una sequencia de led 1 o 2 random
    initialSequence[i] = generateRandom(1,3);   
    //Serial.println(initialSequence[i]);
  }
}
void comprobarColor(int it, int readG, int readR) {
 if(readG == HIGH && pushedG == 0) {
    pushedG = 1;
  	digitalWrite(green, HIGH);
    if(initialSequence[it] == 2) {
     Serial.println("Correcto");
    } else {
        secuenciaLucesIncorrecto();
        volverAEmpezar();
      }
  }  else if (readG == LOW && pushedG == 1){
        pushedG = 0;
   		digitalWrite(green, LOW);
  }

  if(readR == HIGH && pushedR == 0) {
    pushedR = 1;
    digitalWrite(red, HIGH);
    if(initialSequence[it] == 1) {
       Serial.println("Correcto");
    } else {
        secuenciaLucesIncorrecto();
        volverAEmpezar();
      }
  }  else if (readR == LOW && pushedR == 1){
        pushedR = 0;
    	digitalWrite(red, LOW);
  }


}

boolean PulsarNingunBoton(int readG, int readR) {
  if(readG == HIGH || readR == HIGH) {
    return true;
  } else {
    return false;
  }
}


void setup() {
  Serial.begin(9600);
  //hacer la secuencia inicial maximo de 5 (rellenarlo entero)
  for(int i = 0; i < 5; i++){
    // Se crea una sequencia de led 1 o 2 random
    initialSequence[i] = generateRandom(1,3);   
    Serial.println(initialSequence[i]);
  }

}

void loop() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(pinPulsadorR, INPUT_PULLUP);
  pinMode(pinPulsadorG, INPUT_PULLUP);
  randomSeed(analogRead(pinForRandom));

  valorPulsadorG = digitalRead(pinPulsadorG);
  valorPulsadorR = digitalRead(pinPulsadorR);
 if(ronda == 0) {
   generateSequenceLucesRonda1();
   int pulsaciones = 0;
   while(!PulsarNingunBoton(valorPulsadorG,valorPulsadorR )) {
   	while(pulsaciones != it_ronda_1) {
     	comprobarColor(pulsaciones, valorPulsadorG,valorPulsadorR );
     	pulsaciones++;
   	}
   }
   ronda++;
 } else if(ronda == 1) {
   generateSequenceLucesRonda2();
   int pulsaciones = 0;
   while(!PulsarNingunBoton(valorPulsadorG,valorPulsadorR )) {
   	while(pulsaciones != it_ronda_1 +1) {
     	comprobarColor(pulsaciones, valorPulsadorG,valorPulsadorR );
     	pulsaciones++;
   	}
   }
    ronda++;
 } else if(ronda == 2){
   generateSequenceLucesRonda3();
   int pulsaciones = 0;
   while(!PulsarNingunBoton(valorPulsadorG,valorPulsadorR )) {
   	while(pulsaciones != it_ronda_1 +2) {
     	comprobarColor(pulsaciones, valorPulsadorG,valorPulsadorR );
     	pulsaciones++;
   	}
   }
   ganar();
 }

}