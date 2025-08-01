#include <LPC17xx.H>
main()
{
LPC_SC->CLKSRCSEL=0x00;
LPC_SC->PLL0CON=0x00;
LPC_SC->PCONP=1<<1;
LPC_SC->PCLKSEL0=(1<<2);

LPC_PINCON->PINSEL0=0x00000000;
LPC_PINCON->PINSEL1=0x00000000;

LPC_GPIO0->FIODIR=0xFFFFFFFF;
LPC_GPIO0->FIOPIN=0x00000000;

LPC_TIM0->PC=0;
LPC_TIM0->TC=0;
LPC_TIM0->PR=3999;
LPC_TIM0->MR0=1000;
LPC_TIM0->MCR=2;
LPC_TIM0->TCR=2;
LPC_TIM0->TCR=1;

while(1)
{
while(LPC_TIM0->TC!=LPC_TIM0->MR0);
LPC_TIM0->TC=0;
LPC_GPIO0->FIOPIN^=0xFFFFFFFF;
}
}