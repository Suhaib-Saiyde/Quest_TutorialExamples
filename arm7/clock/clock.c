#include <LPC214X.H>
#include<stdio.h>
#include<stdlib.h>

void tx(char *x)
{
int i;
for(i=0;x[i];i++)
    {
        U0THR=x[i];
        while((U0LSR&(1<<6))==0);		
    }
	
}


int rx()
{
    char x[5];
    int i,y;
    for(i=0;;i++)
    {
         while((U0LSR&(1<<0))==0);
        x[i]=U0RBR;
		U0THR=x[i];
         while((U0LSR&(1<<6))==0);
		 
        
        if(x[i]=='\r')
        {
            x[i]='\0';
            break;
        }
		
    }
	
    y=atoi(x);
    return y;
}


main()
{
    int h,m,s;
    char a[20],b[]="ENTER THE HOUR\r\n",d[]="ENTER THE MINUTE\r\n",c[]="ENTER THE SECOND\r\n";
    

   PINSEL0=(1<<0)|(1<<2);
   U0LCR=0x83;
   U0DLL=97;
   U0LCR=0x03;

   T0PC=0;
   T0TC=0;
   T0PR=14999;
   T0MR0=1000;
   T0MCR=2;
   T0TCR=2;
   T0TCR=1;

    
    tx(b);
    h=rx();  
    tx(d);
    m=rx();
    tx(c);
    s=rx();
     

   while(1)
   {
   	   while(T0TC!=T0MR0) ;
       T0TC=0;

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
            
           
        sprintf(a,"%d:%d:%d\r",h,m,s);
        tx(a);
   }
}