#define ECHO   2
#define TRIG   3

void setup() {
    Serial.begin(115200);
    pinMode(ECHO, INPUT);
    pinMode(TRIG, OUTPUT);
}

void loop() {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);

    float timeTraveled = pulseIn(ECHO, HIGH);
    float distance = timeTraveled / 58;

    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println("cm");
    delay(250);
}
