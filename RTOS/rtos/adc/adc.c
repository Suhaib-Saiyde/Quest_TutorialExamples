#include<includes.h>
OS_STK s1[128];
OS_STK s2[128];

int x;
char a[20];


void uart()
{
int i;

while(1)
{
for(i=0;a[i];i++)
{
UDR0=a[i];
while((UCSR0A&(1<<5))==0);
}
OSTimeDlyHMSM(0,0,0,500);
OSTaskResume(5);
OSTaskSuspend(6);

}
}

void adc()
{

while(1)
{
ADCSRA|=1<<6;
while((ADCSRA&(1<<4))==0);
x=ADCL|(ADCH<<8);
sprintf(a,"ADC=%d\r\n",x);
OSTimeDlyHMSM(0,0,0,500);
OSTaskResume(6);
OSTaskSuspend(5);

}
}

void main()
{

ADCSRA=0X87;
ADMUX=0x00;

UCSR0A=0;
UCSR0B=0x18;
UCSR0C=0x06;
UBRR0L=103;

TCCR0=0x07;
TIMSK=0x01;

OSInit();
OSTaskCreate(adc,0xFF,&s1[127],5);
OSTaskCreate(uart,0xFF,&s2[127],6);
OSStart();


}
