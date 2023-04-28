#include <iostream>

using namespace std;

int main() {
    int temp[10];
    int *ptr = temp;

    cout << temp << endl;
    cout << temp[0] << endl;
    cout << temp[1] << endl;
    cout << &ptr << endl;
}

// constants won't change
const int buttonPin = 2;
const int ledPin = 13;

// variables will change
int buttonState = 0;

void setup() {
    // init the LED pin as an output
    pinMode(ledPin, OUTPUT);
    // init the pushbutton pin as an input
    pinMode(buttonPin, INPUT);
}

void loop() {
    // read the state of the pushbutton value
    buttonState = digitalRead(buttonPin);

    // check if the pushbutton is pressed
    if (buttonState == HIGH) {
        // LED on
        digitalWrite(ledPin, HIGH);
    } else {
        // LED off
        digitalWrite(ledPin, low);
    }
}
