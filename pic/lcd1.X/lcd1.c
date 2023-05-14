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
#define RS RC0
#define RW RC1
#define E RC2

void command(char a)
{
    char b;
    RS=0;
    RW=0;
    b=a&0xF0;
    PORTC=PORTC&0x0F;
    PORTC=PORTC|b;
    E=1;
    __delay_ms(25);
    E=0;
   
    b=a&0x0F;
    PORTC=PORTC&0x0F;
    PORTC=PORTC|b<<4;
    E=1;
    __delay_ms(25);
    E=0;
    
    
}

void data(char a)
{
    char b;
    RS=1;
    RW=0;
    b=a&0xF0;
    PORTC=PORTC&0x0F;
    PORTC=PORTC|b;
    E=1;
    __delay_ms(25);
    E=0;
    
    b=a&0x0F;
    PORTC=PORTC&0x0F;
    PORTC=PORTC|b<<4;
    E=1;
    __delay_ms(25);
    E=0;
    
    
}
void main() 
{
    TRISC=0x00;
    command(0x02);
    command(0x0C);
    command(0x28);
    command(0x01);
    command(0x80);
    int i;
    char a[]="qwerty";
    while(1)
    {
        for(i=0;a[i]!='\0';i++)
        {
        data(a[i]);
        
        }
        command(0x80);
    }
}
