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
	
	lastError = PID(lastError); // actualizamos esta shet y la ejecutamos

	if (digitalRead(PINBOTON)){
		beep();
		delay(500);
		Motores(0,0);
		WaitBoton();
	}


	
	//test_sensores();
	
}