#include <LPC214X.H>
main()
{	

		 int i,j;
	char a[10];
	  PINSEL0=(1<<0)|(1<<2);
	  U0LCR=0x83;
	  U0DLL=97;
	  U0LCR=0x03;
	  while(1)
	  {
	  for(i=0;;i++)
	  {
	  	  	 while((U0LSR&(1<<0))==0);
			   	 a[i]=U0RBR;
				 if(a[i]=='\r')
				 {
				 a[i]='\0';
				 break;
				 }
	  }


	  for(i=0;a[i];i++)
	  {
	  U0THR=a[i];
	  while((U0LSR&(1<<6))==0);
	  }
	
	  }
}