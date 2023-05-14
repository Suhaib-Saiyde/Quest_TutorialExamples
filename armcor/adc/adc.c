#include <LPC17xx.H>
#include<stdio.h>

void tx(char *p)
{
int i;
for(i=0;p[i];i++)
 {
 LPC_UART0->THR=p[i];
 while((LPC_UART0->LSR&(1<<6))==0);
 }
}

main()
{
int i;
char a[15];

LPC_SC->CLKSRCSEL=0x00;
LPC_SC->PLL0CON=0x00;
LPC_SC->PCONP=(1<<3)|(1<<12);
LPC_SC->PCLKSEL0=(1<<6)|(1<<24);

LPC_PINCON->PINSEL0=(1<<4)|(1<<6)|(1<<14);

LPC_UART0->LCR=0x83;
LPC_UART0->DLL=26;
LPC_UART0->LCR=0x03;

LPC_ADC->ADCR=0x00200001;
while(1)
{
LPC_ADC->ADCR|=1<<24;
while((LPC_ADC->ADGDR&(1<<31))==0);
i=(LPC_ADC->ADGDR>>4)&(0x00000FFF);
sprintf(a,"ADC0=%d",i);
tx(a);
}

}
