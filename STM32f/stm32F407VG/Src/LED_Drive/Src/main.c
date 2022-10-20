/*
 * 006spi_tx_testing.c
 *
 *  Created on: Feb 10, 2019
 *      Author: admin
 */

#include<string.h>
#include "stm32f407xx.h"

uint32_t volatile *pClkReg          =   (uint32_t*)0x40023830;
uint32_t volatile *pPortDModeReg    =   (uint32_t*)0x40020C00;
uint32_t volatile *pPortDOutReg 	   =   (uint32_t*)0x40020C14;

uint32_t volatile *pPortAModeReg    =   (uint32_t*)0x40020000;
uint32_t volatile *pPortAInReg      =   (uint32_t*)0x40020010;


int main(void)
{

	// Clock Activate
 	*pClkReg              |=   (1<<3);	// D
 	*pClkReg              |=   (1<<0);	// A
	// Enable Output Mode
	*pPortDModeReg        &=  ~(3<<24);
	*pPortDModeReg        |=   (1<<24);
	 //*pPortDModeOutReg   |= (1<<12);
	// Port D Enable
	while(1){
		uint8_t pinStatus = (uint8_t)(*pPortAInReg & 0x1);
		if(pinStatus){
			*pPortDOutReg ^= (1<<12);
		}
		else{
			*pPortDOutReg |= ~(1<<12);
		}
	}


	return 0;

}
