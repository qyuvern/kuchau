#define PINBOTON 2
#define PINBUZZER 10
#define PINLED 13
#define PIN_Sensor_ON 11
static float lastError = 0.0f; 

void setup() {
	Serial.begin(9600);
  WaitBoton();
}

void loop() {
	
	int cal[2];
	calibracion(cal);

	int b = cal[0];
	int n = cal[1];

	while(!digitalRead(PINBOTON)){
		lastError = PID(lastError, b, n); // actualizamos esta shet y la ejecutamos
	}
	
	beep();
	Motores(0,0);
	WaitBoton();
	
	//test_sensores();
	
	
	//test_motores();
}
