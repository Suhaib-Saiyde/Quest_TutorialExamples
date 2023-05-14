#include <LPC17xx.H>
main()
{
int i,j,k;
LPC_SC->CLKSRCSEL=0x00;
LPC_SC->PLL0CON=0x00;

LPC_PINCON->PINSEL0=0x00000000;
LPC_PINCON->PINSEL1=0x00000000;
LPC_PINCON->PINSEL2=0x00000000;

LPC_GPIO0->FIODIR=0xFFFFFFFF;
LPC_GPIO1->FIODIR=~(1<<0);

LPC_GPIO0->FIOPIN=0x00000000;
while(1)
{
if((LPC_GPIO1->FIOPIN&(1<<0))==0)
{
while((LPC_GPIO1->FIOPIN&(1<<0))==0);
for(i=0;;i++)
{
LPC_GPIO0->FIOPIN=1<<i;
 for(k=0;k<50000;k++);
  if((LPC_GPIO1->FIOPIN&(1<<0))==0)
  {
  	  while((LPC_GPIO1->FIOPIN&(1<<0))==0);
		 for(j=i-1;;j--)
		 {
		LPC_GPIO0->FIOPIN=1<<j;
		   for(k=0;k<50000;k++);
			 if((LPC_GPIO1->FIOPIN&(1<<0))==0)
			 {
			 	   while((LPC_GPIO1->FIOPIN&(1<<0))==0);
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
