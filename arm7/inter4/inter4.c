#include <LPC214X.H>

__irq void timer()
{
if(T0IR==4)	   
{
   IOPIN0^=0xFFFFFFFF;
  
   T0IR=4;
}

	 if(T0IR==1)
{						  	
   IOPIN1^=0xFFFFFFFF;
   T0TC=0;
   T0IR=1;
}
VICVectAddr=0;
}
main()
{
PINSEL0=0x00000000;
PINSEL1=0x00000000;
PINSEL2=0x00000000;

IODIR0=0xFFFFFFFF;
IODIR1=0xFFFFFFFF;
IOPIN0=0x00000000;
IOPIN1=0xFFFFFFFF;

T0PC=0;
T0TC=0;
T0PR=14999;
T0MR2=500;
T0MR0=1000;
T0MCR=(1<<6)|(1<<0);

T0TCR=2;
T0TCR=1;

VICIntSelect=0;
VICIntEnable=(1<<4);
VICDefVectAddr=(unsigned)timer;


while(1);
}
