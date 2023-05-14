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


void main() 
{ 
    TXSTA=0x24;
    RCSTA=0x90;
    SPBRG=25;
    int i;
    char a[]="ENTER THE PASSWORD\r\n",b[]="password",c[],d[]="\r\nACCESS GRANTED\r\n",e[]="\r\nTRY AGAIN\r\n";
    while(1)
    {
     for(i=0;a[i]!='\0';i++)
     {
        TXREG=a[i];
         while(TRMT==0);
     }
        for(i=0;;i++)
        {
            while(RCIF==0);
             c[i]=RCREG;
            if(c[i]=='\r')
             {
              c[i]='\0';
              break;
             }
              else
                {
                    TXREG='*';
                    while(TRMT==0); 
                }
          }
     if(strcmp(b,c)==0)
     {
         for(i=0;d[i]!='\0';i++)
         {
             TXREG=d[i];
             while(TRMT==0);
         }
         
     }
     else
     {
         for(i=0;e[i]!='\0';i++)
         {
             TXREG=e[i];
             while(TRMT==0);
         }
     }
    }
}
