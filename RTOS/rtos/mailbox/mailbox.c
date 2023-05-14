#include<includes.h>

#include<stdio.h>

OS_STK s1[128],s2[128],s3[128];
OS_EVENT *maildata1,*maildata2;
int *err;
void adc1();

void adc2();
void uart();

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
	OSTaskCreate(uart,0xFF,&s3[127],6);
	
	maildata1=OSMboxCreate(1);
	maildata2=OSMboxCreate(1);
	OSStart();

}

void adc1()

{

	int a;
	char b[20];
	while(1)

	{

		ADMUX=0x00;

		ADCSRA|=1<<6;

		while((ADCSRA&(1<<4))==0);

		a=ADCL|(ADCH<<8);

		sprintf(b,"result1=%d   \r",a);
		OSMboxPost(maildata1,b);
		OSTimeDlyHMSM(0,0,1,0);
	}

}

void adc2()

{

	 int c;
	char d[20];
	while(1)

	{

		ADMUX=0x01;

		ADCSRA|=1<<6;

		while((ADCSRA&(1<<4))==0);

		c=ADCL|(ADCH<<8);

		sprintf(d,"result2=%d    \r",c);
		OSMboxPost(maildata2,d);
		OSTimeDlyHMSM(0,0,1,0);
		

	}

}
void uart()
{
	int i;
	char *out1,*out2;
	while(1)
	{
		out1=OSMboxPend(maildata1,0,err);
		for(i=0;out1[i]!='\0';i++)
		{
			UDR0=out1[i];
			while((UCSR0A&(1<<5))==0);
		}
		out2=OSMboxPend(maildata2,0,err);
		for(i=0;out2[i]!='\0';i++)
		{
			UDR0=out2[i];
			while((UCSR0A&(1<<5))==0);
		}
		OSTimeDlyHMSM(0,0,1,0);
	}
}