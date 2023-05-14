#include <LPC214X.H>
#include<stdio.h>
#include<string.h>

void tx(char *p)
{
int i;
for(i=0;p[i];i++)
{
U0THR=p[i];
while((U0LSR&(1<<6))==0);
}
}

void delay(int n)
{
int i;
for(i=0;i<n;i++)
{
while(T0TC!=T0MR0) ;
T0TC=0;
}
}

void esp(int x)
{
int len;
char a[10]="AT\r\n";
char b[20]="AT+CWLAP\r\n";
char c[90]="AT+CWJAP=\"redmi 9i\",\"subi98147\"\r\n";
char d[90]="AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n";
char e[90],f[50];

sprintf(e,"GET https://api.thingspeak.com/update?api_key=5TWV9W1JTRZWUKO3&field1=%d\r\n",x);
len=strlen(e);
sprintf(f,"AT+CIPSEND=%d\r\n",len);

tx(a);
delay(5);
tx(b);
delay(10);
tx(c);
delay(10);
tx(d);
delay(10);
tx(f);
delay(10);
tx(e);
delay(10);
}

main()
{
PINSEL0=(1<<0)|(1<<2);
U0LCR=0x83;
U0DLL=97;
U0LCR=0x03;

T0PC=0;
T0TC=0;
T0PR=14999;
T0MR0=1000;
T0MCR=2;
T0TCR=2;
T0TCR=1;

esp(30);

while(1);
}
