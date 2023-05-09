#include "TRSensors.h"
#include <Wire.h>

#define PWMA 6        // L-Motor Speed
#define AIN2 A0       // L-Motor Forward
#define AIN1 A1       // L-Motor Backward
#define PWMB 5        // R-Motor Speed
#define BIN1 A2       // R-Motor Forward
#define BIN2 A3       // R-Motor Backward
#define NUM_SENSORS 5 // IR Sensors
#define Addr 0x20     // Communication address for the joystick

#define KP 0.075
#define KI 0.0001
#define KD 20
#define MAX_SPEED 80

TRSensors trs = TRSensors();
unsigned int sensorValues[NUM_SENSORS];
unsigned int error_prior = 0;
unsigned int previousPosition;
long integral = 0;

// Setup Functions
void PCF8574Write(byte data);
byte PCF8574Read();
void waitForButtonPress();
void calibrate();

// Motor Control Functions
void forward(int speed);
void forward(int leftMotorSpeed, int rightMotorSpeed);
void backward(int speed);
void rotateRight(int speed);
void rotateLeft(int speed);
void stop();
bool searchTrack();
bool searchTrack(int ms);
int PIDControl();

void setup() {
    Serial.begin(115200); // Serial communication begins with 115200 bauds.
    Wire.begin();         // Communication with the joystick.

    waitForButtonPress();

    // L-Motor Setup
    pinMode(PWMA, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(AIN1, OUTPUT);

    // R-Motor Setup
    pinMode(PWMB, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);

    // Calibration
    calibrate();

    waitForButtonPress();

    delay(100);
}

void loop() {
    bool trackFound = searchTrack();

    // When the previous position detected is right in the middle
    if (!trackFound && previousPosition == 2000) {
        // Try tracking broken line forward
        forward(30);
        trackFound = searchTrack(1000);
    }
    // When the previous position detected only left side
    if (!trackFound && previousPosition < 2000) {
        // Try tracking steep curve on the left
        rotateLeft(90);
        delay(100);
        forward(30);
        trackFound = searchTrack(1000);
        // If nothing found
        if (!trackFound) {
            // Try tracking broken line on the right
            rotateRight(90);
            delay(200);
            forward(30);
            trackFound = searchTrack(1000);
            stop();
        }
    }
    // When the previous position detected only right side
    if (!trackFound && 2000 < previousPosition) {
        // Try tracking steep curve on the right
        rotateRight(90);
        delay(100);
        forward(30);
        trackFound = searchTrack(1000);
        // If nothing found
        if (!trackFound) {
            // Try tracking broken line on the left
            rotateLeft(90);
            delay(200);
            forward(30);
            trackFound = searchTrack(1000);
            stop();
        }
    }

    if (trackFound) {
        int m_control = PIDControl();
        bool onMiddle = sensorValues[1] > 450 && sensorValues[2] > 900 && sensorValues[3] > 450;

        if (onMiddle) {
            forward(MAX_SPEED);
        }
        if (m_control > 0) {
            forward(MAX_SPEED, MAX_SPEED - m_control);
        } else {
            forward(MAX_SPEED + m_control, MAX_SPEED);
        }
    }
}

// PCF8574 is a chip to transmit and convert the input value of the joystick to the digital value.
void PCF8574Write(byte data) {
    Wire.beginTransmission(Addr);
    Wire.write(data);
    Wire.endTransmission();
}

byte PCF8574Read() {
    int data = -1;
    Wire.requestFrom(Addr, 1);
    if (Wire.available()) {
        data = Wire.read();
    }
    return data;
}

void waitForButtonPress() {
    byte value;
    while (value != 0xEF) {                 // If the joystick button is not pressed,
        PCF8574Write(0x1F | PCF8574Read()); // Waits until the press is detected.
        value = PCF8574Read() | 0xE0;       // 0xEF = 0b11101111, the button pressed.
    }
}

void calibrate() {
    stop();
    rotateRight(80);

    // Calibration for 10 seconds
    for (int i = 0; i < 100; i++) {
        if (i < 25 || i >= 75) {
            rotateLeft(80);
        } else {
            rotateRight(80);
        }
        trs.calibrate();
    }

    // Stop after the calibration
    stop();
}

void forward(int speed) {
    digitalWrite(AIN2, HIGH);
    digitalWrite(AIN1, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMA, speed);
    analogWrite(PWMB, speed);
}

void forward(int leftMotorSpeed, int rightMotorSpeed) {
    digitalWrite(AIN2, HIGH);
    digitalWrite(AIN1, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMA, leftMotorSpeed);
    analogWrite(PWMB, rightMotorSpeed);
}

void backward(int speed) {
    digitalWrite(AIN2, LOW);
    digitalWrite(AIN1, HIGH);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMA, speed);
    analogWrite(PWMB, speed);
}

void rotateRight(int speed) {
    digitalWrite(AIN2, HIGH);
    digitalWrite(AIN1, LOW);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMA, speed);
    analogWrite(PWMB, speed);
}

void rotateLeft(int speed) {
    digitalWrite(AIN2, LOW);
    digitalWrite(AIN1, HIGH);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
    analogWrite(PWMA, speed);
    analogWrite(PWMB, speed);
}

void stop() {
    digitalWrite(AIN2, LOW);
    digitalWrite(AIN1, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
}

bool searchTrack() {
    bool derailed = sensorValues[0] < 20
                    && sensorValues[1] < 20
                    && sensorValues[2] < 20
                    && sensorValues[3] < 20
                    && sensorValues[4] < 20;
    unsigned int temp = trs.readLine(sensorValues);
    if (derailed) {
        return false;
    }
    previousPosition = temp;
    return true;
}

bool searchTrack(int ms) {
    bool trackDetected = sensorValues[0] > 50
                         || sensorValues[1] > 50
                         || sensorValues[2] > 50
                         || sensorValues[3] > 50
                         || sensorValues[4] > 50;

    for (int i = 0; i < ms; i++) {
        unsigned int temp = trs.readLine(sensorValues);
        if (trackDetected) {
            // Reset PID in order to prevent integral getting larger
            error_prior = 0;
            integral = 0;
            previousPosition = temp;
            return true;
        }
        delay(1);
    }
    return false;
}

int PIDControl() {
    unsigned int position = trs.readLine(sensorValues);
    previousPosition = position;
    stop();

    int error = (int) position - 2000;
    integral += error;
    int derivative = error - error_prior;
    error_prior = error;
    int m_control = KP * error + KI * integral + KD * derivative;

    if (m_control > MAX_SPEED) {
        return MAX_SPEED;
    }
    if (m_control < -MAX_SPEED) {
        return -MAX_SPEED;
    }
    return m_control;
}
