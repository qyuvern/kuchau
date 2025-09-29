#define PINBUZZER 10
#define PINBOTON 2
#define PINLED 13
#define PIN_Sensor_ON 11

void setup() {
  Serial.begin(115200);
  Peripherals_init();
  TB6612FNG_init();
  Sensors_init();

  digitalWrite(PINLED, LOW);
  delay(500);

  Motores(0, 0);
  Serial.println("Ahora, nos aseguraremos que los motores funcionan de manera correcta :3");
  Serial.println("Instrucciones:   ");
  Serial.println("");
  delay(100);
}


void loop() {
  Serial.println("Presiona el botón, ambos motores deberían moverse hacia adelante. Si uno o ambos van para atrás, cambia la polarización de los cables ;P.");
  Serial.println("");
  
  delay(500);
  WaitBoton();

  Motores(50, 50);

  delay(1000);

  Serial.println("---o---");

  Serial.println("Presiona otra vez el botón para detener los motores");
  Serial.println("");
  WaitBoton();
  Motores(0, 0);
  delay(1000);
  
}
