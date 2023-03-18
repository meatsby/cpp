
Page
1
of 2
/*MASTER SPI-like protocol
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
const long eFREC = 200;  // microseconds, clock rate is 1/(2*eFREC)
byte byteTx = 0;
byte byteRx = 0;
void setup()
{
    Serial.begin(9600);
    pinMode(eMOSI, OUTPUT);
    pinMode(eMISO, INPUT);
    pinMode(eSCK,  OUTPUT);
    pinMode(eSS,   OUTPUT);
    digitalWrite(eMOSI,LOW);
    digitalWrite(eSCK,LOW);
    digitalWrite(eSS,HIGH);
}
void loop()
{
    delay(1000);
    byteRx = eWR_Master(byteTx);
    infoTxRx(byteTx,byteRx);
    byteTx++;
}
byte eWR_Master(byte mbTx)
{
    byte mbRx;
    digitalWrite(eSS,LOW);
    for (int i=7 ; i>-1; i--)
    {
        digitalWrite(eMOSI,bitRead(mbTx,i));
        delayMicroseconds(eFREC);
        digitalWrite(eSCK,HIGH);
        delayMicroseconds(100);
        bitWrite(mbRx,i,digitalRead(eMISO));
        delayMicroseconds(eFREC-100);
        digitalWrite(eSCK,LOW);
    }
    digitalWrite(eMOSI,LOW);
    digitalWrite(eSS,HIGH);
    return mbRx;
}
void infoTxRx(byte bTx,byte bRx)
{
    Serial.print("Tx = ");
    Serial.print(bTx);
    Serial.print("  Rx = ");
    Serial.println(bRx);
}
