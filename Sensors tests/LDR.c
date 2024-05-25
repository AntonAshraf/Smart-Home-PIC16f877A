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

float ldr;
char ldr1[5];

void main() {

 Lcd_Init();
 Delay_ms(100);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Delay_ms(10);

 ADC_Init();
 Delay_ms(100);

 TRISC.F0 = 0;
 PORTC.F0 = 0;
 Delay_ms(100);

 while(1)
 {

  ldr = ADC_Read(0);
  Delay_ms(50);
  FloatToStr(ldr, ldr1);
  Delay_ms(50);
  Lcd_Out(1, 1, ldr1);
  Delay_ms(50);

  if ( ldr > 80 )
  {
//    PORTC.F0 = 1;
   Lcd_Out(2, 1, " LED OFF ");
  }
  else if ( ldr < 80 )
  {
//    PORTC.F0 = 0;
   Lcd_Out(2, 1, " LED ON ");
  }



 }
}