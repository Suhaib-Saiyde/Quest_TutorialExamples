#include<avr/io.h>
#include<util/delay.h>
#include<stdio.h>

void tx(char *p)
{
int i;
for(i=0;p[i];i++)
{
UDR0=p[i];
while((UCSR0A&(1<<5))==0);
}
}

void main()
{
int x;
char a[20];

ADCSRA=0X87;
ADMUX=0x00;

UCSR0A=0;
UCSR0B=0x18;
UCSR0C=0x06;
UBRR0L=103;


while(1)
{
ADCSRA|=1<<6;
while((ADCSRA&(1<<4))==0);
x=ADCL|(ADCH<<8);
sprintf(a,"ADC=%d\r\n",x);
tx(a);
_delay_ms(500);
}
}
