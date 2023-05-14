#include <LPC214X.H>

void command(char a)
{
  
    char b;
    IOCLR1=(1<<24)|(1<<23);
    
    b=a&0xF0;
    IOPIN0&=~(IOPIN0&0x00003C00);
    IOPIN0=IOPIN0|(b<<6);
    IOSET1=(1<<22);
       while(T0TC!=T0MR0) ;
    T0TC=0;
    IOCLR1=(1<<22);
   
    b=a&0x0F;
    IOPIN0&=~(IOPIN0&0x00003C00);
    IOPIN0=IOPIN0|(b<<10);
    IOSET1=(1<<22);
   	 while(T0TC!=T0MR0) ;
    T0TC=0;
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
    while(T0TC!=T0MR0) ;
   T0TC=0;
    IOCLR1=(1<<22);
   
    b=a&0x0F;
    IOPIN0&=~(IOPIN0&0x00003C00);
    IOPIN0=IOPIN0|(b<<10);
    IOSET1=(1<<22);
      while(T0TC!=T0MR0) ;
    T0TC=0;
    IOCLR1=(1<<22);
}
main()
{
    int i;
	 char a[20]="qwerty....";
      PINSEL0=0x00000000;
    PINSEL1=0x00000000;
	PINSEL2=0x00000000;

	IODIR0=(1<<10)|(1<<11)|(1<<12)|(1<<13);
    IODIR1=(1<<24)|(1<<23)|(1<<22);

	T0PC=0;
    T0TC=0;
    T0PR=14999;
    T0MR0=25;
    T0MCR=2;
    T0TCR=2;
    T0TCR=1;
    command(0x02);
    command(0x0C);
    command(0x28);
    command(0x01);
    command(0x80);
    
   
    while(1)
    {
        for(i=0;a[i]!='\0';i++)
        {
        data(a[i]);
        
        }
        command(0x80);
    }
}
