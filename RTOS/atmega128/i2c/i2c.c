#include<avr/io.h>
#include<util/delay.h>
#include<stdio.h>
#include<string.h>

char temp;
void tx(char *p)
{
int i;
	for(i=0;p[i];i++)
	{
	UDR0=p[i];
	while((UCSR0A&(1<<5))==0);
	}
}

void START()
{
	TWCR=((1<<TWSTA)|(1<<TWEN)|(1<<TWINT));
	while((TWCR&(1<<TWINT))==0);
}

void STOP()
{
	TWCR=((1<<TWSTO)|(1<<TWINT)|(1<<TWEN));
}

void SEND(char a)
{
	TWDR=a;
	TWCR=((1<<TWINT)|(1<<TWEN));
	while((TWCR&(1<<TWINT))==0);
}

void ACK()
{
	TWCR=((1<<TWEA)|(1<<TWEN)|(1<<TWINT));
	while((TWCR&(1<<TWINT))==0);
	temp=TWDR;
}

char NACK()
{
	TWCR=((1<<TWEN)|(1<<TWINT));
	while((TWCR&(1<<TWINT))==0);
	temp=TWDR;
}

void main()
{
char d[10];
char sec,min,hr;

UCSR0B=0x18;
UCSR0C=0x06;
UBRR0L=103;

TWBR=18;

START();
SEND(0xD0);
SEND(0x00);
SEND(0x43);
SEND(0x12);
SEND(0x03);

STOP();
while(1)
{
_delay_ms(1000);
tx("\b\b\b\b\b\b\b\b\b\b\b\b");
START();
SEND(0xD0);
SEND(0x00);
START();
SEND(0xD1);

ACK();

sec=temp;
ACK();
min=temp;
NACK();
hr=temp;
STOP();
sprintf(d,"%x:%x:%x\r",hr,min,sec);
tx(d);
}

}








