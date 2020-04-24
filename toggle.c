/* This code is inteded to toggle the RED and GREEN LEDS */

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include <unistd.h>

#define GPIO_RED_LED  GPIO_Pin_14
#define GPIO_GN_LED   GPIO_Pin_13

int main(){
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE);
	GPIO_InitTypeDef GPIO_InitDef; 

	GPIO_InitDef.GPIO_Pin = GPIO_RED_LED;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT; 
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_Speed = GPIO_High_Speed;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL; 
	GPIO_Init(GPIOI, &GPIO_InitDef);

	while(1){
		GPIO_ToggleBits(GPIOI, GPIO_RED_LED); 
		sleep(1);
	}
}
