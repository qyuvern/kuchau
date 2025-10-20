void test_motores() {
  Serial.println("Presiona el botón, ambos motores deberían moverse hacia adelante. Si uno o ambos van para atrás, cambia la polarización de los cables ;P.");
  Serial.println("");
  
  delay(500);
  WaitBoton();

  Motores(50, 0);

  delay(1000);

  WaitBoton();

  Motores(0,50);

  Serial.println("---o---");

  Serial.println("Presiona otra vez el botón para detener los motores");
  Serial.println("");
  WaitBoton();
  Motores(0, 0);
  delay(1000);

  WaitBoton();
  Motores(50,50);
  delay(500);
  Motores(0,0);
}

void test_sensores(){
  int v1 = analogRead(A1);
  int v2 = analogRead(A2);
  int v3 = analogRead(A3);
  int v4 = analogRead(A4);
  int v5 = analogRead(A5);
  int v6 = analogRead(A6);
  float prom = (v1+v2+v3+v4+v5+v6)/6;

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
  Serial.print(v6);
  Serial.print(" | Promedio = ");
  Serial.println(prom);

  delay(1);
}
