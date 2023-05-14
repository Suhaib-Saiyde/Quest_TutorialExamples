#include <LPC214X.H>

main()
{
int i,j,k;
PINSEL0=0x00000000;
PINSEL1=0x00000000;
PINSEL2=0x00000000;

IODIR1=~(1<<16);
IODIR0=0xFFFFFFFF;

IOPIN0=0x00000000;
while(1)
{
if((IOPIN1&(1<<16))==0)
{
while((IOPIN1&(1<<16))==0) ; 
for(i=0;;i++)
{
IOPIN0=1<<i;
 for(k=0;k<500000;k++);
  if((IOPIN1&(1<<16))==0)
  {
  	  while((IOPIN1&(1<<16))==0) ;
		 for(j=i-1;;j--)
		 {
		 IOPIN0=1<<j;
		   for(k=0;k<500000;k++);
			 if((IOPIN1&(1<<16))==0)
			 {
			 	  while((IOPIN1&(1<<16))==0) ;
				  i=j;
				  break;
			 }
		   if(j==-1)
		   {
		   j=31;
		   }
		 }
  }
if(i==32)
{
i=0;
}
}
}
}
}