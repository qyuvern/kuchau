void lecturaSensores(float sensores[6]) {
  for (int i = 0; i < 6; i++) {
    sensores[i] = analogRead(i); // o como leas tus sensores
  }
}
