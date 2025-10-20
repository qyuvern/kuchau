int v_s_min[6] = { 1023, 1023, 1023, 1023, 1023, 1023 };
int v_s_max[6] = { 0, 0, 0, 0, 0, 0 };
volatile int s_p[6];
bool online;

int pos;
int l_pos;


void lecturaSensores(int s[6]) {
  for (int i = 0; i < 6; i++) {
    s[i] = analogRead(i+1); // o como leas tus sensores
  }

  for (int i = 0; i < 6; i++) {
    if (s[i] < v_s_min[i]) {
      s[i] = v_s_min[i];
    }

    if (s[i] > v_s_max[i]) {
      s[i] = v_s_max[i];
    }
    s_p[i] = map(s[i], v_s_min[i], v_s_max[i], 100, 0);
  }

  volatile int sum = s_p[0] + s_p[1] + s_p[2] + s_p[3] + s_p[4] + s_p[5];
  if (sum > 100) {
    online = 1;

  } 
  else {
    online = 0;
    sum = 100;
  }

}

void calibracion() {
  digitalWrite(PIN_Sensor_ON, HIGH);

  int v_s[6];

  for (int j = 0; j < 100; j++) {
    delay(30);
    v_s[0] = analogRead(A6);
    v_s[1] = analogRead(A5);
    v_s[2] = analogRead(A4);
    v_s[3] = analogRead(A3);
    v_s[4] = analogRead(A2);
    v_s[5] = analogRead(A1);

    for (int i = 0; i < 6; i++) {
      if (v_s[i] < v_s_min[i]) {
        v_s_min[i] = v_s[i];
      }
    }

    for (int i = 0; i < 6; i++) {
      if (v_s[i] > v_s_max[i]) {
        v_s_max[i] = v_s[i];
      }
    }
  }

  beep();
  beep();

  Serial.println();
  Serial.println();

  Serial.print("Minimos");
  Serial.print("\t");

  for (int i = 0; i < 6; i++) {
    Serial.print(v_s_min[i]);
    Serial.print("\t");
  }
  Serial.println();

  Serial.print("Maximos");
  Serial.print("\t");

  for (int i = 0; i < 6; i++) {
    Serial.print(v_s_max[i]);
    Serial.print("\t");
  }
  Serial.println();
  digitalWrite(PIN_Sensor_ON, LOW);
}

int getPos() {
  int s_p[6];
  lecturaSensores(s_p);
  int prom = -2.5 * s_p[0] - 1.5 * s_p[1] - 0.5 * s_p[2] + 0.5 * s_p[3] + 1.5 * s_p[4] + 2.5 * s_p[5];
  int sum = s_p[0] + s_p[1] + s_p[2] + s_p[3] + s_p[4] + s_p[5];

  if (online) {
    pos = int(100.0 * prom / sum);
  } 
  
  else {
    if (l_pos < 0) {
      pos = -255;
    }
    if (l_pos >= 0) {
      pos = 255;
    }
  }

  l_pos = pos;
  return pos;
}

/*
VIEJO
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
*/
