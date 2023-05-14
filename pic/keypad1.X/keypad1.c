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

void init()
{
    command(0x02);
    command(0x0C);
    command(0x28);
    command(0x01);
    command(0x80);
}

char keypad()
{
    while(1)
    {
        __delay_ms(100);
        RB0=0;
        RB1=RB2=RB3=1;
        if(RB4==0)
        {
            while(RB4==0);
            return'7';
        }
        if(RB5==0)
        {
            while(RB5==0);
            return'8';
        }
        if(RB6==0)
        {
            while(RB6==0);
            return'9';
        }
        if(RB7==0)
        {
            while(RB7==0);
            return'/';
        }
    
        RB1=0;
        RB0=RB2=RB3=1;
        if(RB4==0)
        {
            while(RB4==0);
            return'4';
        }
        if(RB5==0)
        {
            while(RB5==0);
            return'5';
        }
        if(RB6==0)
        {
            while(RB6==0);
            return'6';
        }
        if(RB7==0)
        {
            while(RB7==0);
            return'*';
        }
        RB2=0;
        RB0=RB1=RB3=1;
        if(RB4==0)
        {
            while(RB4==0);
            return'1';
        }
        if(RB5==0)
        {
            while(RB5==0);
            return'2';
        }
        if(RB6==0)
        {
            while(RB6==0);
            return'3';
         }
        if(RB7==0)
        {
             while(RB7==0);
            return'-';
        }
        RB3=0;
        RB0=RB1=RB2=1;
        if(RB4==0)
        {
            while(RB4==0);
            return'c';
        }
        if(RB5==0)
        {
            while(RB5==0);
            return'0';
        }
        if(RB6==0)
        {
            while(RB6==0);
            return'=';
        }
        if(RB7==0)
        {
            while(RB7==0);
            return'+';
        }
    }
}

void lcd(char *a)
{
    int i;
    for(i=0;a[i];i++)
    {
        data(a[i]);
    }
}
void main()
{
    TRISC=0x00;
    TRISB=0xF0;
    init();
    int i,operand1,operand2;      
    char a[12],b[12],operator,ans[10],c;
    while(1)
    {
        for(i=0;;i++)
        {
            b[i]=keypad();
            data(b[i]);
            if(b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/')
            {
                operator=b[i];
                b[i]='\0';
                break;
            }
        }
        for(i=0;;i++)
        {
            a[i]=keypad();
            data(a[i]);
            if(a[i]=='=')
            {
                command(0xC0);
                a[i]='\0';
                break;
            }
        }
        
        operand1=atoi(b);
        operand2=atoi(a);
        
        switch(operator)
        {
            case '+':
                sprintf(ans,"%d",(operand1+operand2));
                lcd(ans);
                break;
            case '-':
                sprintf(ans,"%d",(operand1-operand2));
                lcd(ans);
                break;
            case '*':
                sprintf(ans,"%d",(operand1*operand2));
                lcd(ans);
                break;
            case '/':
                sprintf(ans,"%d",(operand1/operand2));
                lcd(ans);
                break;
            default:
                data('c');
        }
        c=keypad();
        if(c=='c')
        {
            command(0x01);
            
        }
    }
}
