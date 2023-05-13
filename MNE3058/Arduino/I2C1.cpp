#include <Wire.h>
#define I2C_SLAVE1_ADDRESS 11
#define B1 2
bool Mem_B1=false;
bool ON_OFF=false;
int n=0;
void setup()
{
    pinMode(B1, INPUT); // B1 gets the user input from the button
    Wire.begin();
    Serial.begin(9600);
//Request value of n to slave
    Wire.requestFrom(I2C_SLAVE1_ADDRESS, 1);
    n = Wire.read();
/*Serial.print(F("recieved value : "));
Serial.println(n);*/
}
void loop()
{
    Mem_B1 = digitalRead(B1);
    if (Mem_B1){
        Wire.beginTransmission(I2C_SLAVE1_ADDRESS);
        if (ON_OFF){
            ON_OFF = false;
            Wire.write(1);
        } else {
            ON_OFF = true;
            Wire.write(0);
        }
/*Serial.print(F("sending value : "));
Serial.println(1);*/
        Wire.endTransmission();
        delay(1000);
    }
    delay(100);
}