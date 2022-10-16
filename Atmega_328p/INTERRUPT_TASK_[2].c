#ifndef F_CPU
#define F_CPU 16000000UL
#endif

/******LİBRARİES****************************/
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "Library_1.h"
/*****STANDART DEFINITIONS******************/ 
#define REG_ADDR_PCICR			0x68
#define REG_PCICR				((pcicr_ptr_t)REG_ADDR_PCICR)
#define REG_ADDR_PCMSK			0x6B
#define REG_PCMSK    			((pcmsk_ptr_t)REG_ADDR_PCMSK)

#define PCINT_ENABLE			1 // PİN CHANGE İNTERRUPT ENABLE
#define PCINT_DISABLE		    0 // PİN CHANGE İNTERRUPT DISABLE

#define PCINT_PB_vect				PCINT0_vect
#define PCINT_PC_vect				PCINT1_vect
#define PCINT_PD_vect				PCINT2_vect

/**** BOOL STATES *********************************/
#define true					1
#define false					0

#define INIT_PORTS()				do {DDRD = 0xFF; DDRB = 0x00; PORTD = 0x00;PORTB=0x00;} while (0)

#define DEBOUNCE_TIME			50
#define LOOP_TIME_1				100
#define LOOP_TIME_2				500
#define LOOP_TIME_3				1000

#define BTN_PRESSED					(PINB & (1<<0))

#define BTN_ON_1		    (1<<PINB0)
#define BTN_ON_2			(1<<PINB1)
#define BTN_ON_3			(1<<PINB2)

#define BTN_OFF_1		    !(1<<PINB0)
#define BTN_OFF_2			!(1<<PINB1)
#define BTN_OFF_3			!(1<<PINB2)


uint8_t flag_1= false;
uint8_t flag_2= false;
uint8_t flag_3=	false;

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

// FUNCTION DEFINITIONS
void loop1()
{
	
	
}
void loop2()
{
	
	
}
void loop3()
{
	
}
typedef struct{
	uint8_t portB:1;
	uint8_t portC:1;
	uint8_t portD:1;
	uint8_t reversed:5;
}pcicr_t,*pcicr_ptr_t;

typedef struct{
	uint8_t pcint_pb0:1;
	uint8_t pcint_pb1:1;
	uint8_t pcint_pb2:1;
	uint8_t pcint_pb3:1;
	uint8_t pcint_pb4:1;
	uint8_t pcint_pb5:1;
	uint8_t reserved1:2;
	uint8_t pcint_pc0:1;
	uint8_t pcint_pc1:1;
	uint8_t pcint_pc2:1;
	uint8_t pcint_pc3:1;
	uint8_t pcint_pc4:1;
	uint8_t pcint_pc5:1;
	uint8_t pcint_pc6:1;
	uint8_t reversed2:1;
	uint8_t pcint_pd0:1;
	uint8_t pcint_pd1:1;
	uint8_t pcint_pd2:1;
	uint8_t pcint_pd3:1;
	uint8_t pcint_pd4:1;
	uint8_t pcint_pd5:1;
	uint8_t pcint_pd6:1;
	uint8_t pcint_pd7:1;
}pcmsk_t,*pcmsk_ptr_t;

ISR(PCINT_PB_vect)
{
	PORTD_UNION->port = PORT_ALL_HIGH;
	_delay_ms(100);
	PORTD_UNION->port = PORT_ALL_LOW;
	_delay_ms(100);
}

int main(void)
{
  
   //INITIALIZE PORTS
    DDRD_UNION->port=PORT_ALL_OUTPUT;
    REG_PCICR->portB=PCINT_ENABLE;
    REG_PCMSK->pcint_pb0=PCINT_ENABLE;
    sei(); // interrupt initialize
   INIT_PORTS();
   //DEFINE FUNCTION POINTER
   //void(*fun_ptr_arr[])() = {loop1,loop2,loop3};
   while(1)
   {
	
	   
   }
}