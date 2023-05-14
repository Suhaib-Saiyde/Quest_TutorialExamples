#include <LPC214X.H>
#include<stdio.h>

void tx(char *p)
{
int i;
	for(i=0;p[i];i++)

	  {

	  U0THR=p[i];

	  while((U0LSR&(1<<6))==0);

	  }

	  


}
main()
{
int x,j;
char a[15];
PINSEL0=(1<<0)|(1<<2)|(1<<10)|(1<<11)|(1<<8)|(1<<9);
U0LCR=0x83;
U0DLL=97;
U0LCR=0x03;


while(1)
{
AD0CR=0x00200380;
AD0CR|=(1<<24);
while((AD0GDR&(1<<31))==0);
x=(AD0GDR>>6)&(0x000003FF);
sprintf(a,"ADC0=%d\r",x);
tx(a);
  for(j=0;j<500000;j++);


AD0CR=0x00200340;
AD0CR|=(1<<24);
while((AD0GDR&(1<<31))==0);
x=(AD0GDR>>6)&(0x000003FF);
sprintf(a,"ADC2=%d\r",x);
tx(a);
  for(j=0;j<500000;j++);

}
}