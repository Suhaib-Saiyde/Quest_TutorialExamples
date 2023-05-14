#include <LPC214X.H>																																 #include <LPC214X.H>
main()
{
int i,j;
char a[10]="abcde " ;
	  PINSEL0=(1<<0)|(1<<2);
	  U0LCR=0x83;
	  U0DLL=97;
	  U0LCR=0x03;
	  while(1)
	  {
	  for(i=0;a[i]!='\0';i++)
	  {
	  U0THR=a[i];
	  while((U0LSR&(1<<6))==0);
	  }
	  for(j=0;j<500000;j++);
	  }
}