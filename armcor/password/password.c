#include <LPC17xx.H>
#include<stdio.h>
#include<string.h>

void tx(char *p)
{
int i;
for(i=0;p[i];p++)
{
LPC_UART0->THR=p[i];
while((LPC_UART0->LSR&(1<<6))==0);
}
}


main()
p{
int i;
char a[30]="ENTER THE PASSWORD\r\n",b[12]="password",c[12],d[20]="\r\nACCESS GRANTED\r\n",e[20]="\r\nTRY AGAIN\r\n";

LPC_SC->CLKSRCSEL=0x00;
LPC_SC->PLL0CON=0x00;
LPC_SC->PCONP=1<<3;
LPC_SC->PCLKSEL0=1<<6;

LPC_PINCON->PINSEL0=(1<<4)|(1<<6);



while(1)
{

tx(a);

for(i=0;;i++)
{
 while((LPC_UART0->LSR&(1<<0))==0);
 c[i]=LPC_UART0->RBR;
 if(c[i]=='\r') 
 {
 c[i]='\0';
 break;
 }
else
{
LPC_UART0->THR='*';
while((LPC_UART0->LSR&(1<<6))==0);
}
}

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
