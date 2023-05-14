#include<avr/io.h>
#include<util/delay.h>

void main()
{
UCSR0A=0;
UCSR0B=0x18;
UCSR0C=0x06;
UBRR0L=103;
char b[20];
int i;
while(1)
{
for(i=0;;i++)
{
while((UCSR0A&(1<<7))==0);
b[i]=UDR0;

if(b[i]=='\r')
{
b[i]='\0';
break;
}
}
for(i=0;b[i];i++)
{
UDR0=b[i];
while((UCSR0A&(1<<5))==0);
}
_delay_ms(500);
}
}