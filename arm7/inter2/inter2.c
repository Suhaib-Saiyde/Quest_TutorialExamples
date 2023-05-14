#include <LPC214X.H>
 char a;
__irq void  uart()
{
 if((U0IIR&(1<<2))==4)
 {
a=U0RBR;
U0THR=a;
while((U0LSR&(1<<6))==0);
VICVectAddr=0;
}
}

main()
{
PINSEL0=(1<<0)|(1<<2);
U0LCR=0x83;
U0DLL=97;
U0LCR=0x03;
U0IER=1;
VICIntSelect=0;
VICIntEnable=(1<<6);
VICDefVectAddr=(unsigned) uart;
while(1);
}