#define RED_LED 13
#define L_MOTOR 9
#define R_MOTOR 5
#define STOP 3
#define RESTART 2
#define POT_PIN A0
#define RPM_THRESHOLD 2000

volatile bool safe = true;

void setup() {
    Serial.begin(9600);
    pinMode(RED_LED, OUTPUT);
    pinMode(L_MOTOR, OUTPUT);
    pinMode(R_MOTOR, OUTPUT);
    pinMode(STOP, INPUT);
    pinMode(RESTART, INPUT);
    attachInterrupt(digitalPinToInterrupt(STOP), stop, CHANGE);
    attachInterrupt(digitalPinToInterrupt(RESTART), restart, RISING);
}

void loop() {
    int val = read();
    int rpm = map(val, 0, 255, 0, 3846);
    if (rpm > RPM_THRESHOLD || !safe) {
        digitalWrite(RED_LED, HIGH);
        analogWrite(R_MOTOR, LOW);
        analogWrite(L_MOTOR, LOW);
    } else {
        digitalWrite(RED_LED, LOW);
        analogWrite(R_MOTOR, val);
        analogWrite(L_MOTOR, LOW);
    }
}

int read() {
    int potValue = analogRead(POT_PIN);
    return map(potValue, 0, 1023, 0, 255);
}

void stop() {
    safe = !safe;
}

void restart() {
    digitalWrite(RED_LED, LOW);
}
