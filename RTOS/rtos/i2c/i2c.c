#include<includes.h>
OS_STK s1[128];
OS_STK s2[128];
OS_STK s3[128];

 char d[10];
 char hr,sec,min,temp;
char a[20]="Enter hour\r\n",b[20]="Enter minute\r\n",c[20]="Enter second\r\n";

void tx(char *p)
{
int i;
for(i=0;p[i];i++)
{
UDR0=p[i];
while((UCSR0A&(1<<5))==0);
}
}
char rx()
{
char x[5],a;
int i;
while(1)
{
for(i=0;;i++)
{
while((UCSR0A&(1<<7))==0);
x[i]=UDR0;
if(x[i]=='\r')
{
x[i]='\0';
break;
}
}
a=(x[1]-48)|((x[0]-48)<<4);
return a;
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


void uart()
{
int i;

while(1)
{

for(i=0;d[i];i++)
{
UDR0=d[i];
while((UCSR0A&(1<<5))==0);
}
OSTimeDlyHMSM(0,0,0,500);
OSTaskResume(7);
OSTaskSuspend(6);

}
}

void write()
{
char s,m,h;
while(1)
{

tx(a);
h=rx();
tx("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
tx(b);
m=rx();
tx("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
tx(c);
s=rx();
tx("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");

START();
SEND(0xD0);
SEND(0x00);
SEND(s);
SEND(m);
SEND(h);

STOP();

OSTimeDlyHMSM(0,0,0,500);
OSTaskResume(7);
OSTaskSuspend(5);
}
}

void read()
{
while(1)
{
OSTimeDlyHMSM(0,0,0,500);
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
OSTimeDlyHMSM(0,0,0,500);
OSTaskResume(6);
OSTaskSuspend(7);
}

}

void main()
{
UCSR0A=0;
UCSR0B=0x18;
UCSR0C=0x06;
UBRR0L=103;

TCCR0=0x07;
TIMSK=0x01;

TWBR=18;

OSInit();
OSTaskCreate(write,0xFF,&s1[127],5);
OSTaskCreate(uart,0xFF,&s2[127],6);
OSTaskCreate(read,0xFF,&s3[127],7);
OSStart();

}
