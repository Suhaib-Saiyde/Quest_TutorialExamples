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
    TRISC2=0;
    T2CON=0x05;
    CCP1CON=0x0F;
    PR2=249;
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    int i=127;
    char a;
    while(1)
    {
        CCPR1L=i;
        while(RCIF==0);
        a=RCREG;
        if(a=='+')
        {
            
        
            i=i+20;
            if(i>=255)
            {
                i=255;
            }
            //__delay_ms(20);
        
        }
        
        if(a=='-')
        {
        
        
            i=i-20;
            if(i<=0)
            {
                i=0;
            }
            //__delay_ms(20);
        
        }
    }
}