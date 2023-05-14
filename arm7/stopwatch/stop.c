#include <LPC214X.H>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void tx(char *x)
{
int i;
for(i=0;x[i];i++)
    {
        U0THR=x[i];
        while((U0LSR&(1<<6))==0);		
    }
}

void tx1()
{
    int i;
    for(i=0;i<10;i++)
   {
           U0THR='\b';
        while((U0LSR&(1<<6))==0);	
    }
}

main()
{
	 int i,a=0,s=0,m=0,j,l1=0,l2=0;
    char x[10];

   PINSEL0=(1<<0)|(1<<2);
   PINSEL2=0x00000000;
   IODIR1=(0<<16)|(0<<17);

   U0LCR=0x83;
   U0DLL=97;
   U0LCR=0x03;

   T0PC=0;
   T0TC=0;
   T0PR=14999;
   T0MR0=1;
   T0MCR=2;
   T0TCR=2;
   T0TCR=1;

  
    sprintf(x,"%d:%d:%d\r",m,s,a);
    tx(x);
    
	  while(1)
    {
        if((IOPIN1&(1<<16))==0)
        {
         while((IOPIN1&(1<<16))==0) ; 

            
           for(j=0;;j++)
           {
               tx1();
               while(T0TC!=T0MR0) ;
      		   T0TC=0;

            a++;
            if(a==100)
            {
             s++;
             a=0;
             if(s==60)
             {
                 m++;
                 s=0;
             }
            }
           if((IOPIN1&(1<<16))==0)
            {
                 while((IOPIN1&(1<<16))==0) ; 
                break;
            }
            sprintf(x,"%d:%d:%d\r",m,s,a);
           
			tx(x);

			}
			  
            
           
        }
         
        
         if((IOPIN1&(1<<17))==0)
        {
           while((IOPIN0(1<<17))==0) ; 
            a=0;
            s=0;
            m=0;
            sprintf(x,"%d:%d:%d\r",m,s,a);
//			l1=strlen(x);
//			if(l1<l2)
//			{
//			tx1();
//			}
//			l2=l1;
            tx(x);
        }
   
    }
}