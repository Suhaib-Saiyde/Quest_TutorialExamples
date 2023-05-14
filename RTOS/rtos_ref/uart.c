#include<includes.h>
OS_STK s1[128];
OS_STK s2[128];
void blink();
void uart();
int main()
{
	UCSR0A=0;
	UCSR0B=0x18;
	UCSR0C=0x06;
	UBRR0L=103;
	DDRA=0xFF;
	TCCR0=0x07;
	TIMSK=0x01;
	OSInit();
	OSTaskCreate(blink,0xFF,&s1[127],4);
	OSTaskCreate(uart,0xFF,&s2[127],5);
	OSStart();
}
void blink()
{
	char a=0;
	while(1)
	{
		a=~a;
		PORTA=a;
		OSTimeDly(61);
	}
}
void uart()
{
	while(1)
	{
		UDR0='a';
		while((UCSR0A&(1<<5))==0);
		OSTimeDly(122);
	}
}
