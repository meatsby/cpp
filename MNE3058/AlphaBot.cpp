#include "TRSensors.h"
#include <Wire.h>

#define PWMA 6  // L-Motor Speed
#define AIN2 A0 // L-Motor Forward
#define AIN1 A1 // L-Motor Backward
#define PWMB 5  // R-Motor Speed
#define BIN1 A2 // R-Motor Forward
#define BIN2 A3 // R-Motor Backward
#define NUM_SENSORS 5 // IR Sensors
#define Addr 0x20     // Communication address for the joystick

#define KP 0.075
#define KI 0.0001
#define KD 20
#define MAX_SPEED 180

//Global variables to be stored regardless of the loop function
TRSensors trs = TRSensors();
unsigned int sensorValues[NUM_SENSORS];
unsigned int error_prior = 0;
unsigned int position;
long integral = 0;

byte value;
bool trackFound = true; //Boolean data type variable to ensure the robot is on the line.

void PCF8574Write(byte data); //Communication for the joystick.
byte PCF8574Read();

bool derailed() {
    return sensorValues[0] < 20
           && sensorValues[1] < 20
           && sensorValues[2] < 20
           && sensorValues[3] < 20
           && sensorValues[4] < 20;
}

bool onTrack() {
    return sensorValues[0] > 50
           || sensorValues[1] > 50
           || sensorValues[2] > 50
           || sensorValues[3] > 50
           || sensorValues[4] > 50;
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

void rightTurn(int speed) {
    digitalWrite(AIN2, HIGH);
    digitalWrite(AIN1, LOW);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
    analogWrite(PWMA, speed);
    analogWrite(PWMB, speed);
}

void leftTurn(int speed) {
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

void calibrate() {
    stop();
    rightTurn(80);

    // Calibration for 10 seconds
    for (int i = 0; i < 100; i++) {
        if (i < 25 || i >= 75) {
            leftTurn(80);
        } else {
            rightTurn(80);
        }
        trs.calibrate();
    }

    // Stop after the calibration
    stop();
}

void searchTrack(int iterations) {
    for (int i = 0; i < iterations; i++) {
        delay(1);
        trs.readLine(sensorValues);
        if (onTrack()) {
            trackFound = true;
            //Initialize the PID function. Otherwise, it will rotate at
            //one spot as integral is a hugely large number.
            error_prior = 0;
            integral = 0;
            return;
        }
    }
}

void setup() {
    Serial.begin(115200); // Serial communication begins with 115200 bauds.
    Wire.begin();         // Communication with the joystick.

    while (value != 0xEF) {                 // If the joystick button is not pressed,
        PCF8574Write(0x1F | PCF8574Read()); // Waits until the press is detected.
        value = PCF8574Read() | 0xE0;       // 0xEF = 0b11101111, the button pressed.
    }

    // L-Motor Setup
    pinMode(PWMA, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(AIN1, OUTPUT);

    // R-Motor Setup
    pinMode(PWMB, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);

    calibrate();

    // reset joystick input
    value = 0;

    // Wait until the joystick button is pressed.
    while (value != 0xEF) {
        PCF8574Write(0x1F | PCF8574Read());
        value = PCF8574Read() | 0xE0;
    }
    position = trs.readLine(sensorValues) / 200;
    delay(100);
    forward(80);
}

void loop() {
    // Read the sensor values for every loop.
    trs.readLine(sensorValues);

    //All the sensors read bright
    if (derailed()) {
        trackFound = false;
        stop();
        // Move backward slightly to check the last position on the line.
        backward(60);
        delay(100);
        // Read the last position.
        position = trs.readLine(sensorValues);
    }

    // If the last position was the same as the desired position
    if (!trackFound && position == 2000) {
        // move forward with searching every 1 millisecond for the next line.
        forward(180);

        //Path searching for 100 ms.
        searchTrack(100);
    }

    // If the robot was supposed to go to the right before derailing,
    // turn right slightly and move forward to search.
    if (!trackFound && 2000 < position) {
        rightTurn(90);
        delay(100);
        forward(100);

        //Searching right
        searchTrack(40);

        // If the robot cannot find the line by forward searching,
        // begin to search by move circularly because it can find the line as the rail
        // was broken somewhere at the right of the last position.
        if (!trackFound) {
            forward(10, 130);
            searchTrack(300);
        }
    }

    //If the robot was supposed to go to the left,
    // turn left and do the forward searching for a moment.
    if (!trackFound && position < 2000) {
        leftTurn(90);
        delay(100);
        forward(100);

        //Searching left
        searchTrack(40);

        //if the path not found, circular search
        if (!trackFound) {
            forward(130, 10);
            searchTrack(300);
        }
    }

    //Decide position to run when the robot finds the line.
    position = trs.readLine(sensorValues);

    if (trackFound) {
        stop();
        int error, derivative, m_control;

        error = (int) position - 2000;                   //Error feedback.
        integral += error;
        derivative = error - error_prior;
        error_prior = error;

        //PID: Kp, Ki, and Kd values obtained by some trials of tuning.
        m_control = KP * error + KI * integral + KD * derivative;

        //PID control function may result in hugely high or low value, so we have to convert it to the maximum speed value.
        if (m_control > MAX_SPEED) {
            m_control = MAX_SPEED;
        }
        if (m_control < -MAX_SPEED) {
            m_control = -MAX_SPEED;
        }

        /*
         * While following the path, there may be some distracts, such as a horizontal path across the original path.
         * The original line is 2cm wide, so only the one sensor at the center fully reads the high value.
         */
        if (sensorValues[1] > 900 && sensorValues[2] > 900 && sensorValues[3] > 900) {
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