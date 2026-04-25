#include "mock_hal.hpp"

// Mock HAL - leere Implementierung für Cross-Compilation Demo
// In echter Hardware: Hier würde die echte STM32 HAL oder Treiber kommen

uint32_t HAL_GetTick() {
    return 0;
}

void HAL_Delay(uint32_t ms) {
    (void)ms;  // unused
}

void HAL_GPIO_WritePin(const char* port, int pin, int state) {
    (void)port;
    (void)pin;
    (void)state;
}

void NVIC_SystemReset() {
    // Endless loop
    while(1);
}