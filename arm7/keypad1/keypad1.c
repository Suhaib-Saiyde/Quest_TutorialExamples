#include <LPC214X.H>
#include<stdio.h>
#include<stdlib.h>

void delay(int n)
{
int i;
for(i=0;i<n;i++)
{
   while(T0TC!=T0MR0) ;
    T0TC=0;
}
}

void command(char a)
{
  
    char b;
    IOCLR1=(1<<24)|(1<<23);
    
    b=a&0xF0;
    IOPIN0&=~(IOPIN0&0x00003C00);
    IOPIN0=IOPIN0|(b<<6);
    IOSET1=(1<<22);
      delay(25);
    IOCLR1=(1<<22);
   
    b=a&0x0F;
    IOPIN0&=~(IOPIN0&0x00003C00);
    IOPIN0=IOPIN0|(b<<10);
    IOSET1=(1<<22);
   	 delay(25);
    IOCLR1=(1<<22);
    
    
}

void data(char a)
{
  
    char b;
    IOSET1=(1<<24);
	IOCLR1=(1<<23);
    
    b=a&0xF0;
    IOPIN0&=~(IOPIN0&0x00003C00);
    IOPIN0=IOPIN0|(b<<6);
    IOSET1=(1<<22);
     delay(25);
    IOCLR1=(1<<22);
   
    b=a&0x0F;
    IOPIN0&=~(IOPIN0&0x00003C00);
    IOPIN0=IOPIN0|(b<<10);
    IOSET1=(1<<22);
       delay(25);
    IOCLR1=(1<<22);
}

void init()
{
    command(0x02);
    command(0x0C);
    command(0x28);
    command(0x01);
    command(0x80);
}

void lcd(char *a)
{
    int i;
    for(i=0;a[i];i++)
    {
        data(a[i]);
    }
}

char keypad()
{
while(1)
{

   delay(50);
IOCLR1=(1<<16);
IOSET1=(1<<17)|(1<<18)|(1<<19);
if((IOPIN1&(1<<28))==0)
{
	 while((IOPIN1&(1<<28))==0) ; 
	  return'7';
}

if((IOPIN1&(1<<29))==0)
{
	 while((IOPIN1&(1<<29))==0) ; 
	  return'8';
}

if((IOPIN1&(1<<30))==0)
{
	 while((IOPIN1&(1<<30))==0) ; 
	  return'9';
}

if((IOPIN1&(1<<31))==0)
{
	 while((IOPIN1&(1<<31))==0) ; 
	  return'/';
}

   IOCLR1=(1<<17);
IOSET1=(1<<16)|(1<<18)|(1<<19);
if((IOPIN1&(1<<28))==0)
{
	 while((IOPIN1&(1<<28))==0) ; 
	  return'4';
}

if((IOPIN1&(1<<29))==0)
{
	 while((IOPIN1&(1<<29))==0) ; 
	  return'5';
}

if((IOPIN1&(1<<30))==0)
{
	 while((IOPIN1&(1<<30))==0) ; 
	  return'6';
}

if((IOPIN1&(1<<31))==0)
{
	 while((IOPIN1&(1<<31))==0) ; 
	  return'*';
}

IOCLR1=(1<<18);
IOSET1=(1<<17)|(1<<16)|(1<<19);
if((IOPIN1&(1<<28))==0)
{
	 while((IOPIN1&(1<<28))==0) ; 
	  return'1';
}

if((IOPIN1&(1<<29))==0)
{
	 while((IOPIN1&(1<<29))==0) ; 
	  return'2';
}

if((IOPIN1&(1<<30))==0)
{
	 while((IOPIN1&(1<<30))==0) ; 
	  return'3';
}

if((IOPIN1&(1<<31))==0)
{
	 while((IOPIN1&(1<<31))==0) ; 
	  return'-';
}

IOCLR1=(1<<19);
IOSET1=(1<<17)|(1<<18)|(1<<16);
if((IOPIN1&(1<<28))==0)
{
	 while((IOPIN1&(1<<28))==0) ; 
	  return'c';
}

if((IOPIN1&(1<<29))==0)
{
	 while((IOPIN1&(1<<29))==0) ; 
	  return'0';
}

if((IOPIN1&(1<<30))==0)
{
	 while((IOPIN1&(1<<30))==0) ; 
	  return'=';
}

if((IOPIN1&(1<<31))==0)
{
	 while((IOPIN1&(1<<31))==0) ; 
	  return'+';
}

}

}

main()
{
   
   
    int i,operand1,operand2;      
    char a[12],b[12],operator,ans[10],c;

	 PINSEL0=0x00000000;
    PINSEL1=0x00000000;
	PINSEL2=0x00000000;

	IODIR0=(1<<10)|(1<<11)|(1<<12)|(1<<13);
    IODIR1=0x0FFFFFFF;

	T0PC=0;
    T0TC=0;
    T0PR=14999;
    T0MR0=1;
    T0MCR=2;
    T0TCR=2;
    T0TCR=1;

		 init();
    while(1)
    {
        for(i=0;;i++)
        {
            b[i]=keypad();
            data(b[i]);
            if(b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/')
            {
                operator=b[i];
                b[i]='\0';
                break;
            }
        }
        for(i=0;;i++)
        {
            a[i]=keypad();
            data(a[i]);
            if(a[i]=='=')
            {
                command(0xC0);
                a[i]='\0';
                break;
            }
        }
        
        operand1=atoi(b);
        operand2=atoi(a);
        
        switch(operator)
        {
            case '+':
                sprintf(ans,"%d",(operand1+operand2));
                lcd(ans);
                break;
            case '-':
                sprintf(ans,"%d",(operand1-operand2));
                lcd(ans);
                break;
            case '*':
                sprintf(ans,"%d",(operand1*operand2));
                lcd(ans);
                break;
            case '/':
                sprintf(ans,"%d",(operand1/operand2));
                lcd(ans);
                break;
            default:
                data('c');
        }
        c=keypad();
        if(c=='c')
        {
            command(0x01);
            
        }
    }
}