#include <LPC214X.H>

__irq void  intr()
{
if(EXTINT==2)
{
IOPIN1^=0xFFFFFFFF;
EXTINT=2;
}

if(EXTINT==4)
{
IOPIN0^=0xFFFFFFFF;
EXTINT=4;
}

VICVectAddr=0;
}
main()
{
	PINSEL0=(1<<6)|(1<<7)|(1<<14)|(1<<15);
	PINSEL1=0x00000000;
	PINSEL2=0x00000000;
	IODIR0=0xFFFFFFFF;
	IODIR1=0xFFFFFFFF;
	IOPIN0=0x00000000;
	IOPIN1=0x00000000;

	VICIntEnable=(1<<15)|(1<<16);
	VICDefVectAddr=(unsigned) intr;
	EXTMODE=6;
	EXTPOLAR=6;

	while(1);
}