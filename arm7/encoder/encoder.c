#include <LPC214X.H>
main()
{
char a;
int i;
int count=0;
PINSEL0=0x00000000;
PINSEL1=0x00000000;
PINSEL2-0x00000000;

IODIR0=0xffffffff;
IODIR1=0xff00ffff;

IOPIN0=0x00000000;


while(1)
{	  
a=(((~IOPIN1)&(0x00FF0000))>>16);

for(i=a;i!=0;i=i>>1)
{
count++;
}
IOPIN0=count;
count=0;
}
}