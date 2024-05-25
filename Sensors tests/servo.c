// The code is written for PIC16F877A, the servo motor is connected to PORTD.B2
// The code rotates the servo motor to 0, 90 and 180 degrees and then back to 0 degrees

void Rotation0() // 0 Degree
{
    unsigned int i;
    for (i = 0; i < 50; i++)
    {
        PORTD.B2 = 1;
        Delay_us(800);  // pulse of 800us
        PORTD.B2 = 0;
        Delay_us(19200);
    }
}

void Rotation90() // 90 Degree
{
    unsigned int i;
    for (i = 0; i < 50; i++)
    {
        PORTD.B2 = 1;
        Delay_us(1500);  // pulse of 1500us
        PORTD.B2 = 0;
        Delay_us(18500);
    }
}

void Rotation180() // 180 Degree
{
    unsigned int i;
    for (i = 0; i < 50; i++)
    {
        PORTD.B2 = 1;
        Delay_us(2200);  // pulse of 2200us
        PORTD.B2 = 0;
        Delay_us(17800);
    }
}

void main()
{
    // Set PORTA to digital output
    // ADCON1 = 0x06;  // Set all PORTA pins as digital I/O (for PIC16F877A)
    TRISD = 0x00;   // Set all PORTA pins as outputs

    while (1)
    {
        Rotation0();    // 0 Degree
        Delay_ms(2000);
        Rotation180();  // 180 Degree
        Delay_ms(2000);
        Rotation90();   // 90 Degree
        Delay_ms(2000);
        Rotation0();    // 0 Degree
    }
}
