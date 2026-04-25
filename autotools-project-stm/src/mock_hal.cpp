#include "mock_hal.hpp"

uint32_t HAL_GetTick() { return 0; }
void HAL_Delay(uint32_t ms) { (void)ms; }
void HAL_GPIO_WritePin(const char* port, int pin, int state) { 
    (void)port; (void)pin; (void)state; 
}
void NVIC_SystemReset() { while(1); }