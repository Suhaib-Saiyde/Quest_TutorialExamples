#include <LPC214X.H>
 char a;
__irq void uart()
{
a=U0RBR;
U0THR=a;
while((U0LSR&(1<<6))==0);
VICVectAddr=0;
}

__irq void timer()
{
IOPIN1^=0xFFFFFFFF;
T0IR=1;
T0TC=0;
VICVectAddr=0;
}

main()
{
PINSEL0=(1<<0)|(1<<2);
PINSEL2=0x00000000;

IODIR1=0xFFFFFFFF;
IOPIN1=0X00000000;

U0LCR=0x83;
U0DLL=97;
U0LCR=0x03;
U0IER=1;

T0PC=0;
T0TC=0;
T0PR=14999;
T0MR0=500;
T0MCR=1;
T0TCR=2;
T0TCR=1;

VICIntSelect=0;
VICIntEnable=(1<<6)|(1<<4);
VICVectCntl0=0x26;
VICVectAddr0=(unsigned)uart;

VICVectCntl1=0x24;
VICVectAddr1=(unsigned)timer;


while(1);

}
