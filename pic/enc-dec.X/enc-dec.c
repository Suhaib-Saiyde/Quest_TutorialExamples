
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 4000000
void main() 
{
    char a;
    TRISB0=1;
    TRISB1=1;
      TRISB2=1;
    TRISC=0x00;
    PORTC=0x00;
    while(1)
    {
        PORTC=1<<((~PORTB)&0x07);
      //a=(~PORTB)&0x07;
      //PORTC=1<<a;
       /* if(RB0==1&&RB1==0&&RB2==0)
        {
            PORTC=0X01;
        }
        else if(RB0==0&&RB1==1&&RB2==0)
        {
            PORTC=0x02;
        }
        else if(RB0==1&&RB1==1&&RB2==0)
        {
            PORTC=0x04;
        }
        else if(RB0==0&&RB1==0&&RB2==1)
        {
            PORTC=0x08;
        }
        else if(RB0==1&&RB1==0&&RB2==1)
        {
            PORTC=0x10;
        }
        else if(RB0==0&&RB1==1&&RB2==1)
        {
            PORTC=0x20;
        }
        else if(RB0==1&&RB1==1&&RB2==1) 
        {
            PORTC=0x40;
        }
        else
        {
           PORTC=0x00;   
        }*/
    }
}
