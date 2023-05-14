#include <LPC214X.H>
#include<string.h>
#include<stdio.h>
void tx(char *a);
void delay(int n);
void espr();

main()
{
PINSEL0=(1<<0)|(1<<2);
U0LCR=0x83;
U0DLL=97;
U0LCR=0x03;

T0PR=14999;
T0MR0=1000;
T0TC=0;
T0PC=0;
T0MCR=2;
T0CTCR=0;
T0TCR=2;
T0TCR=1;

espr();
while(1);

}


void tx(char *a)
{
int i;
for(i=0;a[i]!='\0';i++)
{
U0THR=a[i];
while((U0LSR&(1<<6))==0);
}
}


void delay(int n)
{
int i;
  for(i=0;i<n;i++)
  {
    while(T0TC!=T0MR0);
    T0TC=0;
  }
  
}

void espr()
{
int y,i,count=0,flag=0;
char str[35];
char a[20]="AT\r\n";
char b[35]="AT+CWJAP=\"Redmi4\",\"1029384756\"\r\n";
char c[50]="AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n";
char d[20];
char e[100];
char f;
sprintf(e,"GET https://api.thingspeak.com/channels/1328575/fields/1.json?api_key=QAYQDY4CJVZ5TN3E&results=1\r\n");
y=strlen(e);
sprintf(d,"AT+CIPSEND=%d\r\n",y);

tx(a);
delay(1);
tx(b);
delay(10);
tx(c);
delay(10);
tx(d);
delay(10);
tx(e);

while(1)
{
while((U0LSR&(1<<0))==0);
f=U0RBR;
if(f==':')
{
count++;
}
if(count==20)
{
	   for(i=0;;i++)
	   {
	   while((U0LSR&(1<<0))==0);
	   str[i]=U0RBR;
	   if((str[i]=='"')&&flag==0)
	   {
	   i=-1;
	   flag=1;
	   }
	   if((str[i]=='"')&&flag==1)
	   {
	   str[i]='\0';
	   break;
	   }
	   }
break;
}
}
tx(str);
}