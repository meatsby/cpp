
Page
1
of 2
/*SLAVE protocol similar to SPI
MOSI (Master-out, slave-in) for communication from master to slave.
MISO (Master-in, slave-out) for communication from the slave to the
master.
SCK (Clock) clock signal sent by the master
SS (Slave Select) When the master wants to establish communication with
the slave, it sets the corresponding SS line to LOW.
On each pulse of the clock signal, normally on the rising edge, the
master device sends one bit from the slave
and at the same time it receives a bit from the selected slave.
*/
const int eMOSI = 5;
const int eMISO = 4;
const int eSCK  = 2;
const int eSS   = 7;
const long eFREC = 200;  // half period in microseconds
volatile bool eRising = false;
byte byteRx;
byte byteTx = 0;
void setup()
{
    Serial.begin(9600);
    pinMode(eMOSI, INPUT);
    pinMode(eMISO, OUTPUT);
    pinMode(eSS,   INPUT);
    pinMode(eSCK,  INPUT);
    digitalWrite(eMISO,LOW);
    attachInterrupt(digitalPinToInterrupt(eSCK), eISR, RISING);
}
void loop()
{
    if (digitalRead(eSS) == LOW)
    {
        byteRx = eWR_Slave(byteTx);
        Serial.print("Rx = ");
        Serial.print(byteRx);
        Serial.print(" Tx = ");
        Serial.println(byteTx);
        byteTx = byteRx;
        delay(10);
    }
}
byte eWR_Slave(byte bTx)
{
    byte bRx;
    int cRx = 0;
    int cTx = 0;
    while (cRx < 8)
    {
        if (eRising)
        {
            bitWrite(bRx,7-cRx,digitalRead(eMOSI));
            digitalWrite(eMISO,bitRead(bTx,7-cTx));
            eRising = false;
            cRx++;
            cTx++;
        }
        if (cRx == 8)
        {
            delayMicroseconds(eFREC);
            digitalWrite(eMISO,LOW);
        }
    }
    return bRx;
}
void eISR()
{
    eRising = true;
}
