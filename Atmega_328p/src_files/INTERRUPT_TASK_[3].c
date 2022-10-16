#ifndef F_CPU
#define F_CPU	16000000UL
#endif

#include <avr/interrupt.h>
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "INTERRUPT_1_LIB.h"
#include "GPIO_DRIVER.h"

static void init_gpio();
static void init_external_interrupts();
void loop1();
void loop2();

static void init_gpio()
{
	DDRD_UNION  ->port = PORT_ALL_OUTPUT;
	PORTB_UNION ->port = PORT_ALL_LOW;
	DDRD_UNION  ->pins.pin6 = PIN_OUTPUT;
	DDRD_UNION  ->pins.pin7 = PIN_OUTPUT;	
}

static void init_external_interrupts()
{
	REG_EIMSK->int0 = INT_ENABLE;
	REG_EIMSK->int1 = INT_ENABLE;
	REG_EICRA->int0_mode = INT_MODE_FALLING_EDGE;
	REG_EICRA->int1_mode = INT_MODE_RISING_EDGE;
	sei();
}

volatile uint8_t selection;
uint8_t i = 0;

void loop1()
{
	for (i=0; i<6;i++)
	{
		PORTB_UNION->port ^= (1<<i);
		_delay_ms(100);
	}
	
}

void loop2()
{
	for (i=7; i>0; i--)
	{
		PORTB_UNION->port ^= (1<<(i-1));
		_delay_ms(100);
	}
}
ISR(INT0_vect)
{
	selection = 1;
	PORTD_UNION->pins.pin6 ^= PIN_LOW; 
}

ISR(INT1_vect)
{
	selection = 2;
	PORTD_UNION->pins.pin7 ^= PIN_HIGH; 
}
int main()
{
	init_gpio();
	init_external_interrupts();
	
	selection = 0;
	
    while (1) 
    {
		switch(selection)
		{
			case 1:
					loop2();
					break;
			case 2:
					loop1();
					break;
			default:
					break;
			
		}
    }
}
