bool LED_STATE1 = true;
bool LED_STATE2 = true;
int T2_index = 1;

void setup() {
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    cli(); // stop interrupts for till we make the settings
    // Timer 1 (interrupt each 100ms)
    TCCR1A = 0; // Reset entire TCCR1A to 0
    TCCR1B = 0; // Reset entire TCCR1B to 0
    TCCR1B |= B00000101; // Set CS12 to 1 so we get prescalar 1024
    TIMSK1 |= B00000010; // Set OCIE1A to 1 so we enable compare match A
    OCR1A = ?????; // Finally we set compare register A to this value
    // interrupt time = 1/(16 MHz/Prescalar) * ????
    sei(); // Enable back the interrupts
}
