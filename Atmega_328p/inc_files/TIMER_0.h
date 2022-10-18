/*
0x24 (0x44) COM0A1 COM0A0 COM0B1 COM0B0 – – WGM01 WGM00
0x25 (0x45) FOC0A FOC0B – – WGM02 CS02 CS01 CS00 TCCR0B

CS02 CS01 CS00 Description
0 0 0 No clock source (Timer/Counter stopped)
0 0 1 clkI/O/(No prescaling)
0 1 0 clkI/O/8 (From prescaler)
0 1 1 clkI/O/64 (From prescaler)
1 0 0 clkI/O/256 (From prescaler)
1 0 1 clkI/O/1024 (From prescaler)
1 1 0 External clock source on T0 pin. Clock on falling edge.
1 1 1 External clock source on T0 pin. Clock on rising edge
*/

#ifndef _328P_TIMER0_H_
#define _328p_TIMER0_H_

#define REG_ADDR_TCCRO				0x44
#define _REG_TCCR0					(*(volatile uint16_t*)REG_ADDR_TCCRO)

#define REG_ADDR_TCNT0				0x46
#define _REG_TCNT0					(*(volatile uint8_t*)REG_ADDR_TCNT0)

#define REG_ADDR_TIMSK0				0x6E
#define _REG_TIMSK0				    (*(volatile uint8_t*)REG_ADDR_TIMSK0)

#define REG_ADDR_TIFR0				0x35
#define _REG_TIFR0					(*(volatile uint8_t)REG_ADDR_TIFR0)

typedef struct
{
	uint8_t wgmA			:2;
	uint8_t reversed		:2;
	uint8_t com0B			:2;
	uint8_t com0A			:2;
	uint8_t clock_select	:3;
	uint8_t wgmB			:1;
	uint8_t reversedB		:2;
	uint8_t foc0B			:1;
	uint8_t foc0A			:1;
}tccr0_t,*tccr0_ptr_t;

typedef union{
	tccr0_t bits;
	volatile uint8_t value;
}tccr0_t,*tccr0_ptr_t;

#define REG_TCCR0_UNION							(*(tccr0_ptr_t)REG_ADDR_TCCRO)
#define TIMER0_MODE_SELECTION				    REG_TCCR0_UNION.bits.wgmA
#define TIMER0_mode_normal			            0
#define TIMER0_mode_CTC				            2

#define TIMER0_CLOCK_SELECTION					REG_TCCR0_UNION.bits.clock_select 
#define TIMER0_no_clock_source					0
#define TIMER0_no_prescaling					1
#define TIMER0_prescaling_8						2 
#define TIMER0_prescaling_64					3
#define TIMER0_prescaling_256					4
#define TIMER0_prescaling_1024					5
#define TIMER0_ext_clock_falling_edge           6
#define TIMER0_ext_clock_rising_edge            7

#define TIMER0_mode_NORMAL_no_prescaling()		do{REG_TCCR0_UNION.value = 0x0100;} while(0) //0000 0001 0000 0000
#define TIMER0_mode_CTC_no_prescaling()			do{REG_TCCR0_UNION.value = 0x0102;} while(0) //0000 0001 0000 0010

typedef struct
{
	uint8_t value:8;
}tcnt0_t, *tcnt0_ptr_t;

typedef struct
{
	uint8_t toie0:1;
	uint8_t ocie0A:1;
	uint8_t ocie0B:1;
	uint8_t reversed:5;	
}_timsk0_t, *_timsk0_ptr_t;

typedef union
{
	_timsk0_t bits;
	volatile uint8_t value;
}timsk0_t, *timsk0_ptr_t;

#define REG_TCNT0								(*(tccr0_ptr_t)REG_ADDR_TCCRO)
#define TIMER0_counter							REG_TCNT0.value

typedef union
{
	_timsk0_t bits;
	volatile uint8_t value;
}timsk0_t,*timsk0_ptr_t;

typedef struct
{
	uint8_t tov0:1;
	uint8_t ocf0a:1;
	uint8_t ocf0b:1;
	uint8_t reversed:5;
}tifr0_t,*tifr0_ptr_t;

#define REG_TIFR0				(*(tifr0_ptr_t)REG_ADDR_TIFRO)
#define TIMER0_flag_overflow	REG_TIFR0.tov0
#define TIMER0_flag_comp_A		REG_TIFR0.ocf0a
#define TIMER0_flag_comp_B		REG_TIFR0.ocf0b
#define reset_FLAG				1
#define set_FLAG				0

#endif //** TİMER0_H **// 

  