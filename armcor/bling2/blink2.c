#include <LPC17xx.H>
main()
{
LPC_SC->CLKSRCSEL=0x00;
LPC_SC->PLL0CON=0x00;

LPC_PINCON->PINSEL0=0x00000000;
LPC_PINCON->PINSEL1=0x00000000;
LPC_PINCON->PINSEL2=0x00000000;
LPC_PINCON->PINSEL3=0x00000000;

LPC_GPIO0->FIODIR=0xFFFFFFFF;
LPC_GPIO1->FIODIR=~(1<<0);

LPC_GPIO0->FIOPIN=0x00000000;

while(1)
{
if((LPC_GPIO1->FIOPIN&(1<<0))==0)
{
while((LPC_GPIO1->FIOPIN&(1<<0))==0);
LPC_GPIO0->FIOPIN^=0xFFFFFFFF;
}
}
}