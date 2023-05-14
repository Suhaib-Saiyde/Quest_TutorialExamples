#include<avr/io.h>
#include<util/delay.h>

void main()
{
int i,j;   

    DDRB=~(1<<0); 
    DDRE=0xFF;
    while(1)
    {
     for(i=0;;i++)
     {
         PORTE=1<<i;
         _delay_ms(400);
         if((PINB&(1<<0))==0)
         {
             while((PINB&(1<<0))==0);
             for(j=i-1;;j--)
             {
                 PORTE=1<<j;
                 _delay_ms(400);
                 if((PINB&(1<<0))==0)
                 {
                     while((PINB&(1<<0))==0);
                     i=j;
                     break;
                 }
                 if(j==0)
                 {
                     j=8;
                 }
               
             }
         }
         if(i==7)
         {
             i=-1;
         }
     }
    }
}
