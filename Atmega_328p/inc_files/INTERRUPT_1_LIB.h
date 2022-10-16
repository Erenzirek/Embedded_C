#ifndef _328P_E_INTERRUPT_H
#define _328P_E_INTERRUPT_H

#define REG_ADDR_EIMSK					0x3D
#define _REG_EIMSK						(*(volatile uint8_t*)REG_ADDR_EIMSK)
#define REG_ADDR_EICRA					0x69
#define _REG_EICRA						(*(volatile uint8_t*)REG_ADDR_EICRA)
#define REG_ADDR_EIFR					0x3C
#define _REG_EIFR						(*(volatile uint8_t*)REG_ADDR_EIFR)

typedef struct
{
	uint8_t int0:1;
	uint8_t int1:1;
	uint8_t reserved:6;
}eimsk_t,*eimsk_ptr_t;

#define REG_EIMSK						((eimsk_ptr_t)REG_ADDR_EIMSK)
#define INT_ENABLE						1
#define INT_DISABLE						0

typedef struct
{
	uint8_t int0_mode:2;
	uint8_t int1_mode:2;
	uint8_t reserved:4;	
}eicra_t,*eicra_ptr_t;

#define REG_EICRA						((eicra_ptr_t)REG_ADDR_EICRA)
#define INT_MODE_LOW_LEVEL				0
#define INT_MODE_ANY_LOG_CHANGE			1
#define INT_MDOE_FALLING_EDGE			2
#define INT_MODE_RISING_EDGE			3

#endif /*_328P_E_INTERRUPT_H */
