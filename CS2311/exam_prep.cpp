#define LED 11
#define BUTTON_1 3
#define BUTTON_2 2

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(BUTTON_1, INPUT);
    pinMode(BUTTON_2, INPUT);
}

void loop() {
    if (digitalRead(BUTTON_1) && digitalRead(BUTTON_2)) {
        digitalWrite(LED, HIGH);
    }
}
