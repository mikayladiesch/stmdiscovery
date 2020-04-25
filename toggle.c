/* This code is inteded to toggle the RED and GREEN LEDS */

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include <unistd.h>

#define GPIO_RED_LED  GPIO_Pin_14
#define GPIO_GN_LED   GPIO_Pin_13

int main(void){
	GPIO_InitTypeDef GPIO_InitDef;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE); 

	GPIO_InitDef.GPIO_Pin = GPIO_RED_LED;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOI, &GPIO_InitDef);
/*
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
	GPIO_InitDef.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOG, &GPIO_InitDef); 

	volatile uint8_t button_pressed = 1;
*/	while(1){
		/*if (GPIO_ReadInputDataBit(GPIOG, GPIO_Pin_0)) {
			if(!button_pressed){
				button_pressed = 1;
				GPIO_ToggleBits(GPIOI, GPIO_RED_LED);
			}
		}
		else {
			button_pressed = 0;
		}*/
		GPIO_SetBits(GPIOI, GPIO_RED_LED);
	}
}
