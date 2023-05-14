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
#include<stdlib.h>
#define _XTAL_FREQ 4000000
void tx(char *b)
{
    int i;
    for(i=0;b[i]!='\0';i++)
    {
        TXREG=b[i];
        while(TRMT==0);
    }
}

void tx1()
{
    int i;
    for(i=0;i<12;i++)
    {
        TXREG='\b';
        while(TRMT==0);
    }
}



void main() 
{
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    TRISB=0xFF;
    OPTION_REG=0x01;
    
    int i,a=0,s=0,m=0,j;
    char x[10];
    sprintf(x,"%d:%d:%d\r",m,s,a);
    tx(x);
    
    while(1)
    {
        if(RB0==0)
        {
            while(RB0==0);
            
           for(j=0;;j++)
           {
               tx1();
                while(TMR0<=250);
                TMR0=0;
            a++;
            if(a==100)
            {
             s++;
             a=0;
             if(s==60)
             {
                 m++;
                 s=0;
             }
            }
            if(RB0==0)
            {
                while(RB0==0);
                break;
            }
            sprintf(x,"%d:%d:%d\r",m,s,a);
            tx(x);
            
           }
        }
         
        
        if(RB1==0)
        {
            while(RB1==0);
            a=0;
            s=0;
            m=0;
            sprintf(x,"%d:%d:%d\r",m,s,a);
            tx(x);
        }
   
    }
}
