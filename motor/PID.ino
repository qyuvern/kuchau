const int pesos[6] = {-5, -3, -1, 1, 3, 5};

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
	const float Tp = 25.0f;
  const int ref[6] = {986, 986, 505, 505, 986, 986};
	const float Kp = 0.39f, Ki = 0.1f, Kd = 0.01f;
	
	// y ahora las variables, como son static esta es la "semilla" y luego cambian :p
	static float integral = 0.0f;
  static float derivada = 0.0f;
	static float lastError = 0.0f;

	float error = 0.0f;
  float sensores[6];
  lecturaSensores(sensores);

  for(int i = 0; i < 6; i++){
    error += pesos[i]*( ref[i] - sensores[i] );
  }


	integral += error;
	derivada = error - lastError;

	float PID = Kp * error + Ki * integral + Kd * derivada;

  float izq = Tp-PID;
  float der = Tp+PID;

	Motores((int)izq, (int)der); // en nuestro código se llama así la función :P

	lastError = error; // actualizamos esta shet
}
