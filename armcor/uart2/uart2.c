#include <LPC17xx.H>
main()
{
 int i;
 char a[20];
LPC_SC->CLKSRCSEL=0x00;
LPC_SC->PLL0CON=0x00;
LPC_SC->PCONP=1<<3;
LPC_SC->PCLKSEL0=1<<6;

LPC_PINCON->PINSEL0=(1<<4)|(1<<6);

 LPC_UART0->LCR=0x83;
 LPC_UART0->DLL=26;
 LPC_UART0->LCR=0x03;

 while(1)
 {
 for(i=0;;i++)
 {
 while((LPC_UART0->LSR&(1<<0))==0);
 a[i]=LPC_UART0->RBR;
 if(a[i]=='\r') 
 {
 a[i]='\0';
 break;
 }
 LPC_UART0->THR=a[i];
 while((LPC_UART0->LSR&(1<<6))==0);
 }
 }
}
