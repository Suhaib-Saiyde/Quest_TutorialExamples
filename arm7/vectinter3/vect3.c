#include <LPC214X.H>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int x,h=0,m=0,s=0,j=0;
char a[15],b[15],c[10]="data" ,d[10];

void tx(char *p)
{
int i;
for(i=0;p[i];i++)

	  {
U1THR=p[i];
while((U1LSR&(1<<6))==0);
	  }
}

void tx1(char *y)
{
int i;
for(i=0;y[i];i++)

	  {
U0THR=y[i];
while((U0LSR&(1<<6))==0);
	  }
}

__irq void uart()
{
  d[j]=U0RBR;
  if(d[j]=='\r')
  {
  d[j]='\0';
  j=0;
  if(strcmp(d,c)==0)
  {
  sprintf(b,"ADC=%d    %d:%d:%d\r\n",x,h,m,s);
   tx1(b);
  }
  }
  else
  {
  j++;
  }
  VICVectAddr=0;
}

__irq void timer()
{
s++;
if(s==60)
  {
       m++;
       s=0;
       if(m==60)
       {
          h++;
          if(h==24)
         {
            h=0;
            m=0;
            s=0;
         }
         m=0;
       }
   }
            
           
sprintf(b,"%d:%d:%d\r",h,m,s);
tx(b);
T0IR=1;
T0TC=0;
VICVectAddr=0;
}


main()
{
PINSEL0=(1<<0)|(1<<2)|(1<<10)|(1<<11)|(1<<16)|(1<<18);
PINSEL2=0x00000000;

U0LCR=0x83;
U0DLL=97;
U0LCR=0x03;
U0IER=1;

U1LCR=0x83;
U1DLL=97;
U1LCR=0x03;


AD0CR=0x00200380;
T0PC=0;
T0TC=0;
T0PR=14999;
T0MR0=1000;
T0MCR=1;
T0TCR=2;
T0TCR=1;

VICIntSelect=0;
VICIntEnable=(1<<4)|(1<<6);

VICVectCntl0=0x26;
VICVectAddr0=(unsigned)uart	;

VICVectCntl1=0x24;
VICVectAddr1=(unsigned)timer;



while(1)
{
   AD0CR|=1<<24;
   while((AD0GDR&(1<<31))==0);
   x=(AD0GDR>>6)&(0x3FF);
}

}
