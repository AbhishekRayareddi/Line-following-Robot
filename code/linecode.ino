// ================= IR SENSOR =================
int irPins[8] = {32, 33, 34, 35, 36, 39, 18, 19};
int ir[8];

// ================= MOTOR DRIVER =================
// LEFT motor
#define AIN1 26
#define AIN2 27
#define PWMA 25

// RIGHT motor
#define BIN1 14
#define BIN2 33
#define PWMB 13

// ================= PWM =================
#define PWM_FREQ 20000
#define PWM_RES  8
#define CH_LEFT  0
#define CH_RIGHT 1

// ================= PID =================
float Kp = 25;     // start values
float Ki = 0;
float Kd = 15;

int baseSpeed = 120;
int maxSpeed  = 200;

float error = 0, lastError = 0;
float correction;

// ================= SETUP =================
void setup() {
  Serial.begin(115200);

  // IR pins
  for (int i = 0; i < 8; i++) {
    pinMode(irPins[i], INPUT_PULLUP);
  }

  // Motor direction pins
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  // PWM setup
  ledcSetup(CH_LEFT, PWM_FREQ, PWM_RES);
  ledcSetup(CH_RIGHT, PWM_FREQ, PWM_RES);
  ledcAttachPin(PWMA, CH_LEFT);
  ledcAttachPin(PWMB, CH_RIGHT);

  // Motor forward direction
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

// ================= MAIN LOOP =================
void loop() {
  readSensors();
  calculateError();
  pidControl();
}

// ================= FUNCTIONS =================

void readSensors() {
  for (int i = 0; i < 8; i++) {
    ir[i] = digitalRead(irPins[i]);
  }
}

void calculateError() {
  int weights[8] = {-350, -250, -150, -50, 50, 150, 250, 350};
  int sum = 0;
  int count = 0;

  for (int i = 0; i < 8; i++) {
    if (ir[i] == 0) {          // BLACK line detected
      sum += weights[i];
      count++;
    }
  }

  if (count == 0) {
    error = lastError;         // line lost
  } else {
    error = sum / count;
  }
}

void pidControl() {
  float P = error;
  float D = error - lastError;

  correction = (Kp * P) + (Kd * D);

  int leftSpeed  = baseSpeed + correction;
  int rightSpeed = baseSpeed - correction;

  leftSpeed  = constrain(leftSpeed,  0, maxSpeed);
  rightSpeed = constrain(rightSpeed, 0, maxSpeed);

  ledcWrite(CH_LEFT, leftSpeed);
  ledcWrite(CH_RIGHT, rightSpeed);

  lastError = error;
}

