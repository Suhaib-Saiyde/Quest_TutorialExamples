#include <LPC214X.H>

__irq void ext1()
{

IOPIN1=0x0000FFFF;
EXTINT=1;

VICVectAddr=0;
}

__irq void  ext2()
{

IOPIN1=0xFFFF0000;
EXTINT=2;

VICVectAddr=0;
}


main()
{
PINSEL0=(1<<2)|(1<<3)|(1<<6)|(1<<7);
PINSEL2=0x00000000;

IODIR1=0xFFFFFFFF;
IOPIN1=0x00000000;

VICIntSelect=0;
VICIntEnable=(1<<14)|(1<<15);

VICVectCntl0=0x2E;
VICVectAddr0=(unsigned)ext1;

VICVectCntl1=0x2F;
VICVectAddr1=(unsigned)ext2;

EXTMODE=3;
EXTPOLAR=3;

while(1);
}
