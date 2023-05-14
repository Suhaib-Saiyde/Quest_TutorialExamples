#include<avr/io.h>
#include<util/delay.h>

void main()
{
DDRE=0xFF;
DDRB=0xF8;

PORTE=0xFF;

while(1)
{
PORTE=1<<((~PINB)&0x07);
}
}
