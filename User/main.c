#include "stm32wbxx.h"                  // Device header
#include "sys.h"
#include "delay.h"

int main(void){
	HAL_Init();
	SystemClock_Config();
	PeriphCommonClock_Config();
	delay_init();
    while(1){
     
        delay_ms(1000);
		delay_us(1000);
    }
}
