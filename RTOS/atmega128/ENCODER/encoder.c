#include<avr/io.h>
#include<util/delay.h>

void main()
{
int i,count=0;
char a;

DDRE=0xFF;
DDRB=0x00;

PORTE=0xFF;
while(1)
{
a=(~PINB)&0xFF;
for(i=a;i!=0;i=i>>1)
{
count++;
}
PORTE=count;
count=0;
}

}
