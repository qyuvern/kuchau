void setup() {
  Serial.begin(9600);
}

void loop() {
  int v1 = analogRead(A1);
  int v2 = analogRead(A2);
  int v3 = analogRead(A3);
  int v4 = analogRead(A4);
  int v5 = analogRead(A5);
  int v6 = analogRead(A6);

  Serial.print(v1);
  Serial.print(", ");
  Serial.print(v2);
  Serial.print(", ");
  Serial.print(v3);
  Serial.print(", ");
  Serial.print(v4);
  Serial.print(", ");
  Serial.print(v5);
  Serial.print(", ");
  Serial.println(v6);

  delay(1);
  
}
