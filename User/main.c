#include "stm32wbxx.h"                  // Device header
#include "sys.h"
#include "delay.h"
#include "stm32wbxx_nucleo.h"

int main(void){
	HAL_Init();
	SystemClock_Config();
	PeriphCommonClock_Config();
	delay_init();
	
    while(1){

			
	}
}
