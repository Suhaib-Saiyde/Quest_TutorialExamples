#include<includes.h>
char a[]="hello aow are you alphabets a b c d e f g h\r";
char b[]="aaaaaaaaaaaaaaaaaaaaaaaa\r";
OS_STK s1[128],s2[128];
OS_EVENT *maildata1;
void *err;
void uart1();
void uart2();
int main()
{
	UCSR0A=0;

	UCSR0B=0x18;

	UCSR0C=0x06;

	UBRR0L=103;

	TCCR0=0x07;

	TIMSK=0x01;

	OSInit();

	OSTaskCreate(uart1,a,&s1[127],4);

	OSTaskCreate(uart2,b,&s2[127],5);
	maildata1=OSSemCreate(0);
	OSStart();

}
void uart1(char *p)
{
	int i;
	while(1)
	{
		//OSSemPend(maildata1,0,err);
		for(i=0;p[i];i++)
		{
			UDR0=p[i];
			while((UCSR0A&(1<<5))==0);
		}
		OSTimeDly(1);
	}
}
void uart2(char *p)
{
	int i;
	while(1)
	{
		for(i=0;p[i];i++)
		{
			UDR0=p[i];
			while((UCSR0A&(1<<5))==0);
		}
		//OSSemPost(maildata1);
	}
}
