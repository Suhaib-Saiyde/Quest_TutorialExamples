#include <LPC214X.H>
#include<stdio.h>
#include<string.h>
main()
{
	int i;
    char a[30]="ENTER THE PASSWORD\r\n",b[12]="password",c[12],d[20]="\r\nACCESS GRANTED\r\n",e[20]="\r\nTRY AGAIN\r\n";

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
        for(i=0;;i++)
        {
			 while((U0LSR&(1<<0))==0);
			   	 c[i]=U0RBR;
				 if(c[i]=='\r')
				 {
				 c[i]='\0';
				 break;
				 }
              else
                {
                    U0THR='*';
                      while((U0LSR&(1<<6))==0);
                }
          }
     if(strcmp(b,c)==0)
     {
         for(i=0;d[i]!='\0';i++)
         {
             U0THR=d[i];
              while((U0LSR&(1<<6))==0);
         }
         
     }
     else
     {
         for(i=0;e[i]!='\0';i++)
         {
          U0THR=e[i];
              while((U0LSR&(1<<6))==0);
         }
     }
    }
}