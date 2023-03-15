#include <Wire.h>
#define I2C_SLAVE_ADDRESS 11
#define L1 2
void setup()
{
    pinMode(L1, OUTPUT); // set L1 as output LED
    Wire.begin(I2C_SLAVE_ADDRESS);
/*  Serial.begin(9600);
Serial.println("--- view of the slave ---");*/
    delay(1000);
    Wire.onRequest(requestEvents);
    Wire.onReceive(receiveEvents);
}
void loop(){}
int n = 0;
void requestEvents()
{
// the slave can respond to a request
/*Serial.println(F("---> recieved request"));
Serial.print(F("sending value : "));
Serial.println(n);*/
    Wire.write(n);
}
void receiveEvents(int numBytes)
{
//Serial.println(F("---> recieved events"));
    n = Wire.read();
/*Serial.print(numBytes);
Serial.println(F("bytes recieved"));
Serial.print(F("recieved value : "));
Serial.println(n);*/
    if (n==1){
        digitalWrite(L1,HIGH);
    } else {
        digitalWrite(L1,LOW);
    }
}