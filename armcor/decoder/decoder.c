#include <LPC17xx.H>
main()
{
LPC_SC->CLKSRCSEL=0x00;
LPC_SC->PLL0CON=0x00;

LPC_PINCON->PINSEL0=0x00000000;
LPC_PINCON->PINSEL1=0x00000000;
LPC_PINCON->PINSEL2=0x00000000;

LPC_GPIO1->FIODIR=0xFFFFFFFF;
LPC_GPIO0->FIODIR=0xFFFFFFF8;

LPC_GPIO1->FIOPIN=0x00000000;
while(1)
{
LPC_GPIO1->FIOPIN=1<<(((~LPC_GPIO0->FIOPIN)&(0x00000007)));
}
}