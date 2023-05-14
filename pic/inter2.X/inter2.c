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
#include<stdio.h>
#define _XTAL_FREQ 4000000

int count=0;
void main() 
{
    TRISB=0x00;
    PORTB=0x00;
    GIE=1;
    TMR1IE=1;
    PEIE=1;
    T1CON=0x21;
    TMR1=65286;
    while(1)
    {
        if(count==1000)
        {
            PORTB^=0xFF;
            count=0;
        }
    }
}

void interrupt ISR()
{
    GIE=0;
   
    count++;
    TMR1=65286;
    TMR1IF=0;
    GIE=1;
 
}