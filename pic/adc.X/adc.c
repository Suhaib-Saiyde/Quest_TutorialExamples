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
#include<string.h>
#define _XTAL_FREQ 4000000
void tx(char *x)
{
    int i;
    for(i=0;x[i]!='\0';i++)
    {
        TXREG=x[i];
        while(TRMT==0);
    }
}
void main() 
{
    int x;
    char a[20];
    ADCON0=0x41;
    ADCON1=0x80;
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    while(1)
    {
        CHS2=0;CHS1=0;CHS0=0;
        GO=1;
        while(GO==1);
        x=(ADRESH<<8)|ADRESL;
        sprintf(a,"ADC1=%d\r\n",x);
        tx(a);
        __delay_ms(300);
      
        
        //multiple channel configuration
        
        
        /*CHS2=0;CHS1=0;CHS0=1;
        GO=1;
        while(GO==1);
        x=(ADRESH<<8)|ADRESL;
        sprintf(a,"ADC2=%d\r\n",x);
        tx(a);
        __delay_ms(300);
        
        CHS2=0;CHS1=1;CHS0=0;
        GO=1;
        while(GO==1);
        x=(ADRESH<<8)|ADRESL;
        sprintf(a,"ADC3=%d\r\n",x);
        tx(a);
        __delay_ms(300);*/
    }
}
