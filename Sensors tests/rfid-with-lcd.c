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

char cardnumber[14];
int i;
void main() {
    uart1_init(9600);
    Delay_ms(100); // Wait for UART module to stabilize
    Lcd_Init(); // Initialize LCD
    Lcd_Cmd(_LCD_CURSOR_OFF); // Cursor off
    Lcd_Out(1, 1, "RFID Scanner");


    while (1) {
        if (UART1_Data_Ready()) {
            UART1_Read_Text(cardnumber, ".",14);
            Lcd_Cmd(_LCD_CLEAR);
            Lcd_Out(1, 1, "RFID Scanner");
            Lcd_Out(2, 1, "TAG:");
            Lcd_Out(2,5,cardnumber); // Print RFID number on LCD

            // Clean the card number by resetting the array
            memset(cardnumber, 0, sizeof(cardnumber));
        }
    }
}
