void seguirLineas(){
	
	// declaro las constantes
	const float Tp = 100.0f, ref = 0.0f;
	const float Kp = 0.39f, Ki = 0.1f, Kd = 0.01f;
	
	// y ahora las variables, como son static esta es la "semilla" y luego cambian :p
	static double integral = 0.0f;
	static double lastError = 0.0f;

	float error = lecturaSensores() - ref;

	integral += error;
	double derivada = error - lastError;

	PID = Kp * error + Ki * integral + Kd * derivada;
	Motores(Tp - PID, Tp + PID); // en nuestro código se llama así la función :P

	lastError = error; // actualizamos esta shet
}
