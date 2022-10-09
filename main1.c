/*
 * PULL_UP_DOWN.c
 *
 * Created: 8.10.2022 21:31:11
 * Author : erenz
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>

#define PIN_HIGH		(PINB & (1<<0))
#define PIN_LOW			(!PIN_HIGH)
int main(void)
{
	DDRD  = 0xFF; // D portu çýkýþ alýndý
	DDRB  = 0x00; // B portu giriþ alýndý 
	PORTD = 0x00; // D portu sýfýrlandý
	PORTB = 0xFF; // B portu HÝGH yapýldý
    while (1) 
    {
		if (PIN_HIGH)
		{
			PORTD = 0xF0;
		}else {
			PORTD = 0x0F;
		}
    }
}

