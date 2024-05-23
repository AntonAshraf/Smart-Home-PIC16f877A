// This code is for the flame sensor, it will turn on the buzzer when the sensor detects a flame
// The code is written for PIC16F877A, the flame sensor is connected to PORTD.B0 and the buzzer is connected to PORTE.B0

void main(void)
{
    // Initialize the input pin on PORTD.B0 as low
    PORTD.B0 = 0;
    
    // Configure PIN NUMBER 1 (PORTD.B0) as an input
    TRISD.B0 = 1; // PIN NUMBER 1 IS DECLARED AS AN INPUT
    
    // Initialize the output pin on PORTE.B0 as low
    PORTE.B0 = 0;
    
    // Configure PIN NUMBER 1 (PORTE.B0) as an output
    TRISE.B0 = 0; // PIN NUMBER 1 IS DECLARED AS AN OUTPUT
    
    while(1) { // Start of an endless loop
        // Check if input pin (PORTD.B0) is in high state (logic level 1)
        if (PORTD.B0 == 1) {
            // If fire is detected, turn on the buzzer by setting the output pin (PORTE.B0) to high
            PORTE.B0 = 1; // It will make the buzzer on
        } else {
            // If no fire is detected, turn off the buzzer by setting the output pin (PORTE.B0) to low
            PORTE.B0 = 0; // It will make the buzzer off
        }
    } // End of the endless loop
}