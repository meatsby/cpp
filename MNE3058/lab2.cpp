// Traffic Light Density Control Program

int greenPin = 9;     // Green LED connected to pin 3
int yellowPin = 10;    // Yellow LED connected to pin 5
int redPin = 12;       // Red LED connected to pin 6
int potPin = A0;      // Potentiometer connected to analog pin A0

int potValue = 0;     // Variable to store potentiometer value

void setup() {
    pinMode(greenPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(redPin, OUTPUT);
}

void loop() {
    // Read potentiometer value and map it to the range 0-255
    potValue = analogRead(potPin);
    int density = map(potValue, 0, 1023, 0, 255);

    // Turn on Green LED with PWM based on density value
    analogWrite(greenPin, density);
    delay(5000);                    // Wait for 5 seconds

    // Flicker Yellow LED for 3 times
    for(int i=0; i<3; i++) {
        digitalWrite(yellowPin, HIGH);
        delay(500);
        digitalWrite(yellowPin, LOW);
        delay(500);
    }

    // Turn on Red LED with PWM based on density value
    analogWrite(redPin, density);
    delay(5000);                    // Wait for 5 seconds

    // Turn off all LEDs
    analogWrite(greenPin, 0);
    analogWrite(yellowPin, 0);
    analogWrite(redPin, 0);
}
