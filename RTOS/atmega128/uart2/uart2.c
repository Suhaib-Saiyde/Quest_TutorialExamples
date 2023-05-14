#include<avr/io.h>
#include<util/delay.h>
#include<string.h>

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
UCSR0A=0;
UCSR0B=0x18;
UCSR0C=0x06;
UBRR0L=103;

int i;
char a[]="ENTER THE PASSWORD\r\n",b[]="password",c[15],d[]="\r\nACCESS GRANTED\r\n",e[]="\r\nTRY AGAIN\r\n";

while(1)
{
tx(a);

for(i=0;;i++)
{
	while((UCSR0A&(1<<7))==0);
	c[i]=UDR0;
	if(c[i]=='\r')
	{
		c[i]='\0';
		break;
	}
	else
	{
		UDR0='*';
		while((UCSR0A&(1<<5))==0); 
	}
}+++
if(strcmp(b,c)==0)
{
	tx(d);         
}
else
{
	tx(e);   
}
}
}
