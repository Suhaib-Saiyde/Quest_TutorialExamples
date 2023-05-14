#include<includes.h>
#include<stdio.h>
OS_STK s1[128];
OS_STK s2[128];
void adc1();
void adc2();
char a[30];
int i;
int main()
{
	UCSR0A=0;
	UCSR0B=0x18;
	UCSR0C=0x06;
	UBRR0L=103;
	ADCSRA=0x87;
	TCCR0=0x07;
	TIMSK=0x01;
	OSInit();
	OSTaskCreate(adc1,0xFF,&s1[127],4);
	OSTaskCreate(adc2,0xFF,&s2[127],5);
	OSStart();
}
void adc1()
{
	long int result1;
	while(1)
	{
		ADMUX=0x00;
		ADCSRA|=1<<6;
		while((ADCSRA&(1<<4))==0);
		result1=ADCL|(ADCH<<8);
		sprintf(a,"result1=%ld   \r",result1);
		for(i=0;a[i];i++)
		{
			UDR0=a[i];
			while((UCSR0A&(1<<5))==0);
		}
		OSTimeDly(61);
	}
}
void adc2()
{
	long int result2;
	while(1)
	{
		ADMUX=0x01;
		ADCSRA|=1<<6;
		while((ADCSRA&(1<<4))==0);
		result2=ADCL|(ADCH<<8);
		sprintf(a,"result2=%ld    \r",result2);
		for(i=0;a[i];i++)
		{
			UDR0=a[i];
			while((UCSR0A&(1<<5))==0);
		}
		OSTimeDly(61);
	}
}
