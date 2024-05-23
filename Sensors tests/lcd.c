// This code is for testing the LCD display
// The code is written for PIC16F877A, the LCD is connected to PORTB

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


void main() 
{
    char txt[] = "Hi";
    char txt2[20];
    int counter = 0;

    Lcd_Init();
    Lcd_Out(1, 1, "Hello!");
    delay_ms(500);

    while(TRUE)
    {
        Lcd_Cmd(_LCD_CLEAR);
        Lcd_Out(1, 1, txt);
        sprintl(txt2, "%d", counter);
        Lcd_Out(2, 1, txt2);
        delay_ms(200);
        counter++;
    }

}