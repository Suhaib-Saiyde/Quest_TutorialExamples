#include<avr/io.h>
#include<util/delay.h>
void main()
{
DDRA=0xFF;
DDRB=0xFF;
DDRC=0xFF;
DDRD=0xFF;
DDRE=0xFF;
DDRF=0xFF;
DDRG=0xFF;
while(1)
{
PORTA=0xFF;
PORTB=0xFF;
PORTC=0xFF;
PORTD=0xFF;
PORTE=0xFF;
PORTF=0xFF;
PORTG=0xFF;
_delay_ms(300);

PORTA=0x00;
PORTB=0x00;
PORTC=0x00;
PORTD=0x00;
PORTE=0x00;
PORTF=0x00;
PORTG=0x00;
_delay_ms(300);

}
}