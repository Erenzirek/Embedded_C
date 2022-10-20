/*
 * GPIO_DRIVER.h
 *
 *  Created on: Oct 21, 2022
 *      Author: erenz
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

// Where is the LED Connected?
// PORT: A
// PIN:  5
#define PERIPH_BASE  	   (0x40000000UL)
#define AHB1PERIPH_OFFSET  (0x00020000UL)
#define AHB1PERIPH_BASE    (PERIPH_BASE+AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET 	   (0x0000U)
#define GPIOA_BASE         (AHB1PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET		   (0x3800U)
#define RCC_BASE		   (AHB1PERIPH_BASE + RCC_OFFSET)

#define AHB1EN_R_OFFSET	   (0x30UL)
#define RCC_AHB1EN_R	   (*(volatile unsigned int*)(RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET	   (0x00UL)
#define GPIOA_MODE_R	   (*(volatile unsigned int*)(GPIOA_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET		   (0x14UL)
#define GPIOA_OD_R		   (*(volatile unsigned int*)(GPIOA_BASE + OD_R_OFFSET))


#define GPIOB_OFFSET 	   (0x0400U)
#define GPIOB_BASE		   (*(volatile unsigned int*)(AHB1PERIPH_BASE + GPIOB_OFFSET))


#define GPIOC_OFFSET 	   (0x0800U)
#define GPIOC_BASE		   (*(volatile unsigned int*)(AHB1PERIPH_BASE + GPIOC_OFFSET))


#define GPIOD_OFFSET 	   (0x0C00U)
#define GPIOD_BASE		   (*(volatile unsigned int*)(AHB1PERIPH_BASE + GPIOD_OFFSET))


#define GPIOE_OFFSET 	   (0x1000U)
#define GPIOE_BASE		   (*(volatile unsigned int*)(AHB1PERIPH_BASE + GPIOE_OFFSET))


#define GPIOF_OFFSET 	   (0x1400U)
#define GPIOF_BASE		   (*(volatile unsigned int*)(AHB1PERIPH_BASE + GPIOF_OFFSET))


#define GPIOG_OFFSET 	   (0x1800U)
#define GPIOG_BASE		   (*(volatile unsigned int*)(AHB1PERIPH_BASE + GPIOG_OFFSET))


#define GPIOH_OFFSET 	   (0x1C00U)
#define GPIOH_BASE		   (*(volatile unsigned int*)(AHB1PERIPH_BASE + GPIOH_OFFSET))

#define GPIOI_OFFSET 	   (0x2000U)
#define GPIOI_BASE		   (*(volatile unsigned int*)(AHB1PERIPH_BASE + GPIOI_OFFSET))

#define GPIOJ_OFFSET 	   (0x2400U)
#define GPIOJ_BASE		   (*(volatile unsigned int*)(AHB1PERIPH_BASE + GPIOJ_OFFSET))

#define GPIOK_OFFSET 	   (0x2800U)
#define GPIOK_BASE		   (*(volatile unsigned int*)(AHB1PERIPH_BASE + GPIOK_OFFSET)


#define GPIOAEN 		   (1U<<0)
#define PIN5 			   (1U<<5)
#define LED_PIN			    PIN5

#endif /* GPIO_DRIVER_H_ */
