void lecturaSensores(float sensores[6]) {
  for (int i = 0; i < 6; i++) {
    sensores[i] = analogRead(i+1); // o como leas tus sensores
  }
}