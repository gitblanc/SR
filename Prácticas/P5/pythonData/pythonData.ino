int pythonData;
void setup() {
  // Mismos Baudios que desde Python
  Serial.begin(9600);
  // Espera máxima datos del puerto Serie 
  Serial.setTimeout(1);
}
void loop() {
    // Esperamos en bucle hasta que tengamos datos en el puerto serie 
    while (!Serial.available());
    // Recogemos ese dato que sabemos será un entero
    pythonData = Serial.readString().toInt();
    // Hacemos lo que sea
    Serial.print("Arduino recibio un: ");
    Serial.print(pythonData);
    Serial.print(" y le sumamos 1: ");
    Serial.println(String(int(pythonData)+1)); 
}
 
