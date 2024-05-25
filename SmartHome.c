// Label: RFID with LCD
// Description: This code reads RFID card number from UART and displays it on LCD

// LCD pin definitions
sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D7 at RB3_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D4 at RB0_bit;

// Pin direction
sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D7_Direction at TRISB3_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D4_Direction at TRISB0_bit;

// initailzations
char cardnumber[14];
int i;
void Rotation0();
void Rotation180();
void Rotation90();
void init_home();
void AlertBuzzer();
void defualtLCD();

void main() {

    init_home();

    while (1) {

        // Scan RFID card (Phase 1)
        if (UART1_Data_Ready()) {
           // memset(cardnumber, 0, sizeof(cardnumber));
            UART1_Read_Text(cardnumber, ".",14);
            Lcd_Out(1, 1, " Card Detected!");
            Lcd_Out(2,4,cardnumber); // Print RFID number on LCD
            delay_ms(2000);
            if (cardnumber[0] == '1'){
                Lcd_Out(2, 1, " Welcome Home!");
                PORTD.B7 = 1;
                PORTD.B4 = 1;
                delay_ms(1000);
                PORTD.B4 = 0;
                PORTD.B3 = 0;
                Rotation180() ;
                delay_ms(2000);
                Rotation90();

            } else if (cardnumber[0] == '2'){
                Lcd_Out(2, 1, " Access Denied!");
                PORTD.B7 = 0;
                PORTD.B6 = 1;
                AlertBuzzer();
                PORTD.B6 = 0;
            }
                delay_ms(1000);

            // Clean the card number by resetting the array
            memset(cardnumber, 0, sizeof(cardnumber));
            Lcd_Cmd(_LCD_CLEAR);
            defualtLCD();
        }

        // Fire Alarm (Phase 2)
        if (PORTB.B6 == 1) {
            // Turn on the LED
            PORTD.B5 = 1;
            // Turn on Fan
            PORTD.B3 = 1;

            Lcd_Cmd(_LCD_CLEAR);
            Lcd_Out(1, 1, "Fire Alarm!");
            Lcd_Out(2, 1, "Evacuate Now!");
            // Turn on the buzzer
            PORTD.B4 = 1;
            delay_ms(1000);
            PORTD.B4 = 0;


            Lcd_Cmd(_LCD_CLEAR);
            defualtLCD();
        } else {
            // Turn off the LED
            PORTD.B5 = 0;
            // Turn off Fan
            PORTD.B3 = 0;
        }
    }
}

void init_home(){
    // set port D as output
    TRISD = 0x00;
    PORTD = 0x00;
    TRISB.B6 = 1;
    uart1_init(9600);
    Delay_ms(100);              // Wait for UART module to stabilize
    Rotation0();
    Lcd_Init();                 // Initialize LCD
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);   // Cursor off
    Lcd_Out(1, 1, "  Happy House");
    // print heart in second row
//    Lcd_Chr(2, 1, 0);
 ////    Rotation0();
}

void AlertBuzzer(){
    for (i = 0; i < 4;i++){
        PORTD.B4 = 1;
        Delay_ms(50);
        PORTD.B4 = 0;
        Delay_ms(50);

    }
}

void defualtLCD(){
    PORTD = 0x00;
    Lcd_Out(1, 1, "  Happy House");
}

void Rotation0() // 0 Degree
{
    unsigned int i;
    for (i = 0; i < 50; i++)
    {
        PORTD.B2 = 1;
        Delay_us(1000);  // pulse of 800us
        PORTD.B2 = 0;
        Delay_us(19000);
    }
}
void Rotation90() // 180 Degree
{
    unsigned int i;
    for (i = 0; i < 50; i++)
    {
        PORTD.B2 = 1;
        Delay_us(1500);  // pulse of 2200us
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
        Delay_us(2000);  // pulse of 2200us
        PORTD.B2 = 0;
        Delay_us(18000);
    }
}