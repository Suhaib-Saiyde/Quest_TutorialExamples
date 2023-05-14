#include <LPC17xx.H>
#include<stdio.h>
#include<stdlib.h>
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

int rx()
{
char x[5];
int i,y;
for(i=0;;i++)
{
while((LPC_UART0->LSR&(1<<0))==0);
x[i]=LPC_UART0->RBR;
LPC_UART0->THR=x[i];
while((LPC_UART0->LSR&(1<<6))==0);
if(x[i]=='\r')
{
x[i]='\0';
break;
}
}
y=atoi(x);
return y;
}

main()
{

int h,m,s;
char a[20],b[]="ENTER THE HOUR\r\n",d[]="ENTER THE MINUTE\r\n",c[]="ENTER THE SECOND\r\n";

LPC_SC->CLKSRCSEL=0x00;
LPC_SC->PLL0CON=0x00;
LPC_SC->PCONP=(1<<1)|(1<<3);
LPC_SC->PCLKSEL0=(1<<2)|(1<<6);

LPC_PINCON->PINSEL0=(1<<4)|(1<<6);

LPC_UART0->LCR=0x83;
LPC_UART0->DLL=26;
LPC_UART0->LCR=0x03;

LPC_TIM0->PC=0;
LPC_TIM0->TC=0;
LPC_TIM0->PR=3999;
LPC_TIM0->MR0=1000;
LPC_TIM0->MCR=2;
LPC_TIM0->TCR=2;
LPC_TIM0->TCR=1;

tx(b);
h=rx();  
tx(d);
m=rx();
tx(c);
s=rx();

while(1)
{
while(LPC_TIM0->TC!=LPC_TIM0->MR0);
LPC_TIM0->TC=0;

s++;
if(s==60)
{
m++;
s=0;
if(m==60)
{
h++;
if(h==24)
{
h=0;
m=0;
s=0;
}
m=0;
s=0;
}
}
sprintf(a,"%d:%d:%d\r",h,m,s);
tx(a);
}
}
