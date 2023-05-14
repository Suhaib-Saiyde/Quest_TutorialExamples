#include<includes.h>
OS_STK s1[128];
OS_STK s2[128];

void bling()
{
while(1)
{
PORTA=0xFF;
OSTimeDlyHMSM(0,0,0,500);
PORTA=0x00;
OSTimeDlyHMSM(0,0,0,250);

OSTaskResume(5);
}
}

void uart()
{
char b[20]="qwerty";
int i;
while(1)
{

for(i=0;b[i];i++)
{
UDR0=b[i];
while((UCSR0A&(1<<5))==0);
}
OSTimeDlyHMSM(0,0,0,500);
OSTaskResume(6);
OSTaskSuspend(5);
}
}

void main()
{
DDRA=0xFF;

UCSR0A=0;
UCSR0B=0x18;
UCSR0C=0x06;
UBRR0L=103;

TIMSK=0x01;
TCCR0=0x07;

OSInit();
OSTaskCreate(bling,0xFF,&s1[127],6);
OSTaskCreate(uart,0xFF,&s2[127],5);
OSStart();
}