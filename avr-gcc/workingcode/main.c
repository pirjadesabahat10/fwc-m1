#include <avr/io.h>

int main(void)
{
    DDRD |= 0b11111100;
    DDRB |= 0b00000001;

    PORTD = 0b11100100;
    PORTB |= (1 << PB0);

    while (1)
    {
    }
}

