float PID(float lastError, int b, int n){
  const int pesos[6] = {1, 0.5, 0.2, 0.2, 0.5, 1};

  const float Tp = 25.0f;
  const int ref[6] = {n, n, b, b, n, n};
	const float Kp = 0.39f, Ki = 0.1f, Kd = 0.01f;
	
	// y ahora las variables, como son static esta es la "semilla" y luego cambian :p
	static float integral = 0.0f;
  static float derivada = 0.0f;

  static float error = 0.0f;

  int sensores[6];
  lecturaSensores(sensores);
  
  

  // Error ponderado
  for(int i = 0; i < 6; i++){
    error += pesos[i]*( sensores[i] - ref[i] );
  }

  

  integral += error;
	derivada = error - lastError;

  integral = constrain(integral, -100, 100);

	float PID = Kp * error + Ki * integral + Kd * derivada;

  float izq = Tp+PID;
  float der = Tp-PID;

	Motores((int)izq, (int)der); // en nuestro código se llama así la función :P
  Serial.print("Sensores: {");
  for (int i = 0; i < 6; i++){
    Serial.print(" ");
    Serial.print(sensores[i]);
  }
  Serial.print("} ");
  Serial.print(" | Motores:");
  Serial.print("(");
  Serial.print(izq);
  Serial.print(", ");
  Serial.print(der);
  Serial.print(")");
  Serial.print(" | Error: ");
  Serial.println(error);
  return error;
}
