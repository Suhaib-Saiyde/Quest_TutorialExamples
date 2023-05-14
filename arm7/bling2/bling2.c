#include <LPC214X.H>
main()
{
int i;
PINSEL0=0x00000000;
PINSEL1=0x00000000;
PINSEL2=0x00000000;

IODIR0=(1<<21);

while(1)
{
			 IOSET0=1<<21;
			 for(i=0;i<500000;i++);
			 IOCLR0=(1<<21);
			 for(i=0;i<500000;i++);
}
}