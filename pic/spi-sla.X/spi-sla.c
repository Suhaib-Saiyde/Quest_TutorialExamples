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
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    SSPCON=0x25;
    SSPSTAT=0x00;
    char a[12];
    TRISC5=0;
    TRISC4=1;
    TRISC3=1;
    int i;
    //TRISB=0x00;
    while(1)
    {
        for(i=0;;i++)
        {
            while(SSPIF==0);
            SSPIF=0;
            a[i]=SSPBUF;
            if(a[i]=='\r')
            {
             a[i]='\0';   
             break;
            }
        }
     for(i=0;a[i]!='\0';i++)
     {
         TXREG=a[i];
        while(TRMT==0);
     }
     //PORTB=~a;
        
    }
}