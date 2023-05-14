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
    TRISB=0x00;
   //OPTION_REG=0x02;
   T1CON=0x11;
   // T2CON=0x05;
   //PR2=250; //LIMIT THE LAST VALUE OF TIMER REGISTER
    PORTB=0x00;
    int i;
    while(1)
    {
     
           PORTB^=0xFF;
           //TIMER0 1:4
         /* for(i=0;i<500;i++)
        {
            while(TMR0<=250);
            TMR0=0;
            
        } */
           //TIMER0 USING INTERUPT
        /*for(i=0;i<500;i++)
        {
            while(TMR0IF==0);
            TMR0=5;
            
        }*/
           //TIMER1 1:2
           /*for(i=0;i<1000;i++)
        {
            while(TMR1<=500);
            TMR1=0;
            
        }*/
           //TIMER1 USING INTERUPT
           for(i=0;i<1000;i++)
        {
            while(TMR1IF==0);
            TMR1=65036;
            TMR1IF=0;
            
        }
           //TIMER2 1:4
           /*for(i=0;i<1000;i++)
        {
            while(TMR2<=250);
            TMR2=0;
            
        }*/
           //TIMER2 USING INTERUPT
          /*for(i=0;i<1000;i++)
        {
            while(TMR2IF==0);
            TMR2=0;
            TMR2IF=0;
            
        }*/
    }
}
