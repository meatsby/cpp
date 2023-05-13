#define RED_LED 11
#define YELLOW_LED 10
#define GREEN_LED 9
#define LDR_PIN A0

int density;

void setup() {
    pinMode(RED_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
}

void loop() {
    int ldrStatus = analogRead(LDR_PIN);

    if (ldrStatus <= 300) {
        digitalWrite(RED_LED, HIGH);
        digitalWrite(YELLOW_LED, HIGH);
        digitalWrite(GREEN_LED, HIGH);
    } else {
        digitalWrite(RED_LED, LOW);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(GREEN_LED, LOW);
    }
}
