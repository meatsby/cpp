#define RED_LED 11
#define YELLOW_LED 10
#define GREEN_LED 9

void setup() {
    pinMode(RED_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
}

void loop() {
    digitalWrite(GREEN_LED, ledState);
    delay(1000);
    digitalWrite(GREEN_LED, LOW);
    delay(500);

    for(int i = 0; i < 3; i++) {
        digitalWrite(YELLOW_LED, ledState);
        delay(500);
        digitalWrite(YELLOW_LED, LOW);
        delay(500);
    }

    digitalWrite(RED_LED, ledState);
    delay(1000);
    digitalWrite(RED_LED, LOW);
    delay(500);
}
