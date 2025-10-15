void lecturaSensores(int sensores[6]) {
  for (int i = 0; i < 6; i++) {
    sensores[i] = analogRead(i+1); // o como leas tus sensores
  }
}

void calibracion(int cal[2]) {
  int sensores[6];   // Declarar el arreglo aquí correctamente
  long n_sum = 0;    // Usar long para evitar overflow si sumas muchos valores
  long b_sum = 0;
  const int iteraciones = 100;

  for (int i = 0; i < iteraciones; i++) {
    lecturaSensores(sensores);

    // suma sensores que te interesan
    n_sum += sensores[0] + sensores[1] + sensores[4] + sensores[5];
    b_sum += sensores[2] + sensores[3];
    delay(10); // opcional, para estabilizar lecturas
  }

  // Promedios. Como hiciste 100 iteraciones y sumas 4 sensores para n_sum,
  // el total de lecturas para n_sum es 100 * 4 = 400
  float n_prom = n_sum / (float)(iteraciones * 4);
  float b_prom = b_sum / (float)(iteraciones * 2);

  Serial.print("n = ");
  Serial.print(n_prom);
  Serial.print(" b = ");
  Serial.println(b_prom);

  cal[0] = (int)n_prom;
  cal[1] = (int)b_prom;
}
