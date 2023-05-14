#include <LPC214X.H>
#include<stdio.h>
#include<string.h>

	int i,j=0,f=0,x;
	char test[20];
    char a[30]="ENTER THE PASSWORD\r\n",b[12]="password",c[12],d[20]="\r\nACCESS GRANTED\r\n",e[20]="\r\nTRY AGAIN\r\n";

__irq void uart()
{			
c[j]=U0RBR;
if(c[j]=='\r')
{
c[j]='\0';
f=2;
j=0;
}
else if(c[j]=='\b')
{
U0THR=c[j];
while((U0LSR&(1<<6))==0);
j--;
}
else
{
U0THR=c[j];
while((U0LSR&(1<<6))==0);
j++;
}
VICVectAddr=0;
}

void tx(char *a)
{

 for(i=0;a[i]!='\0';i++)
     {
        U0THR=a[i];
          while((U0LSR&(1<<6))==0);
     }

}

main()
{
	  PINSEL0=(1<<0)|(1<<2);
	  U0LCR=0x83;
	  U0DLL=97;
	  U0LCR=0x03;
	  U0IER=1;
	  VICIntSelect=0;
	  VICIntEnable=(1<<6);
	  VICDefVectAddr=(unsigned) uart;
	  while(1)
	  {
	  if(f==0)
	  {
	 tx(a);
	 f=1;
	 }
	   	 if(f==2)
		 {
	   if((strcmp(b,c))==0)
     {
	 tx(d);         
     }
	  else
     {
         tx(e);
	 }
	 f=0;
	 }
	  }
}