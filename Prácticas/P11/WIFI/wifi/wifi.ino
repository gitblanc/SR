//LED LDR
int ldr = A1;

void setup() {
  Serial.begin(9600);
}
void loop() {
  int sensorvalue=analogRead(A1);
  Serial.println(sensorvalue);
}
