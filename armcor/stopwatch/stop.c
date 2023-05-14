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

void tx1()
{
int i;
for(i=0;i<10;i++)
{
LPC_UART0->THR='\b';
while((LPC_UART0->LSR&(1<<6))==0);
}
}

main()
{

int a=0,s=0,m=0,j;
char x[10];

LPC_SC->CLKSRCSEL=0x00;
LPC_SC->PLL0CON=0x00;
LPC_SC->PCONP=(1<<1)|(1<<3);
LPC_SC->PCLKSEL0=(1<<2)|(1<<6);

LPC_PINCON->PINSEL0=(1<<4)|(1<<6);
LPC_PINCON->PINSEL3=0x00000000;

LPC_GPIO1->FIODIR=0xFFFCFFFF;

LPC_UART0->LCR=0x83;
LPC_UART0->DLL=26;
LPC_UART0->LCR=0x03;

LPC_TIM0->PC=0;
LPC_TIM0->TC=0;
LPC_TIM0->PR=3999;
LPC_TIM0->MR0=1;
LPC_TIM0->MCR=2;
LPC_TIM0->TCR=2;
LPC_TIM0->TCR=1;

sprintf(x,"%d:%d:%d\r",m,s,a);
tx(x);

while(1)
{
if((LPC_GPIO1->FIOPIN&(1<<16))==0)
{
while((LPC_GPIO1->FIOPIN&(1<<16))==0) ; 

for(j=0;;j++)
{
tx1();
while(LPC_TIM0->TC!=LPC_TIM0->MR0);
LPC_TIM0->TC=0;
a++;
if(a==100)
{
s++;
a=0;
if(s==60)
{
m++;
s=0;
}
}
if((LPC_GPIO1->FIOPIN&(1<<16))==0)
{
while((LPC_GPIO1->FIOPIN&(1<<16))==0) ; 
break;
}
sprintf(x,"%d:%d:%d\r",m,s,a);
tx(x);
}
			  
}

if((LPC_GPIO1->FIOPIN&(1<<17))==0)
{
while((LPC_GPIO1->FIOPIN&(1<<17))==0) ; 
a=0;
s=0;
m=0;
sprintf(x,"%d:%d:%d\r",m,s,a);
tx(x);
}
}
}
