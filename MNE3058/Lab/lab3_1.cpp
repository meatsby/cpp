#include "../TRSensors.h"

#define NUM_SENSORS 5

TRSensors trs = TRSensors();
unsigned int sensorValues[NUM_SENSORS];

void setup() {
    Serial.begin(115200);
    for (int i = 0; i < 400; i++) {
        trs.calibrate();
    }
    Serial.println("calibrate done");
    delay(500);
}

void loop() {
    unsigned int position = trs.readLine(sensorValues);

    for (unsigned char i = 0; i < NUM_SENSORS; i++) {
        Serial.print(sensorValues[i]);
        Serial.print('\t');
    }
    Serial.println(position);
    delay(250);
}
