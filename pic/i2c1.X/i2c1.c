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
void init()
{
SSPCON=0x28;
SSPSTAT=0x80;
SSPADD=9;
TXSTA=0x24;
RCSTA=0x90;
SPBRG=25;
TRISC4=1;
TRISC3=1;
}

void start()
{
    SEN=1;
    while(SSPIF==0);
    SSPIF=0;
}

int send(char a)
{
    SSPBUF=a;
    while(SSPIF==0);
    SSPIF=0;
    return(ACKSTAT);
}

void stop()
{
    PEN=1;
    while(SSPIF==0);
    SSPIF=0;
}

void restart()
{
    RSEN=1;
    while(SSPIF==0);
    SSPIF=0;
}

char read()
{
    RCEN=1;
    while(SSPIF==0);
    SSPIF=0;
    return(SSPBUF);
}

void ack()
{
    ACKDT=0;
    ACKEN=1;
    while(SSPIF==0);
    SSPIF=0;
}

void nack()
{
    ACKDT=1;
    ACKEN=1;
    while(SSPIF==0);
    SSPIF=0;
}
void main() 
{
    int i;
    init();
    char sec,min,hr;
    char a[15];
    start();
    while(send(0xD0))
    {
        start();
    }
    send(0x00);
    send(0x20);
    send(0x30);
    send(0x07);
    stop();
    while(1)
    {
        start();
        while(send(0xD0))
        {
            start();
        }
        send(0x00);
        restart();
        send(0xD1);
        sec=read();
        ack();
        min=read();
        ack();
        hr=read();
        nack();
        stop();
        sprintf(a,"%x:%x:%x\r",hr,min,sec);
        for(i=0;a[i];i++)
        {
        TXREG=a[i];
        while(TRMT==0);
        }
        __delay_ms(1000);
        
    }
}
