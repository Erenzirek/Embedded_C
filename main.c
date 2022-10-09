/*
 * void_pointers_button.c
 *
 * Created: 8.10.2022 23:03:11
 * Author : erenz
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>

#define INIT_PORTS()				do {DDRD = 0xFF; DDRB = 0x00; PORTD = 0x00;} while (0)
#define BTN_PRESSED					(PINB & (1<<0))
#define DEBOUNCE_TIME				50
#define LOOP_TIME					300
uint8_t state();
uint8_t state(){
	
	if(BTN_PRESSED){
		_delay_ms(DEBOUNCE_TIME);
		if (BTN_PRESSED)
		{
			return 1;
		}
	}
	return 0;
}
	
int main(void)
{
	
    INIT_PORTS();
	uint8_t led_no = 1;
    while (1) 
    {
		if (state())
		{
			switch(led_no)
			{
				case 1: 
					PORTD ^= (1<<0);
					PORTD ^= (1<<7);
					break;				
				case 2:
					PORTD ^= (1<<1);
					PORTD ^= (1<<6);
					break;
				case 3:
					PORTD ^= (1<<2);
					PORTD ^= (1<<5);
					break;
				case 4:
					PORTD ^= (1<<3);
					PORTD ^= (1<<4);
					led_no = 0;
					break;
			}
		led_no++;
		_delay_ms(LOOP_TIME);
		}
		}
	return(0);

}


