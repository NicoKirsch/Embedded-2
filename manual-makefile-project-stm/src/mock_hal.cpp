#include "mock_hal.hpp"

// Bare-metal STM32L432 HAL Mock Implementation
// Keine C++ Standard Library Dependencies

// Simple tick counter (in real hardware: from SysTick timer)
static volatile uint32_t tick_count = 0;

// For bare-metal: simple busy-wait delay function
static void busyWaitMs(uint32_t ms) {
    // Very simple: loop-based delay
    // In real hardware: use timer interrupt
    for (uint32_t i = 0; i < ms * 1000; i++) {
        __asm volatile("nop");  // No operation
    }
}

uint32_t HAL_GetTick() {
    // In real STM32: return SysTick counter value
    // This is a simplified version - increment manually if needed
    return tick_count;
}

void HAL_Delay(uint32_t ms) {
    // Bare-metal delay without threads
    busyWaitMs(ms);
    tick_count += ms;
}

void HAL_GPIO_WritePin(const char* port, int pin, int state) {
    // In real STM32: write to GPIO registers
    // For bare-metal simulation: just record the state
    (void)port;   // unused
    (void)pin;    // unused  
    (void)state;  // unused
    // No output possible without libc (no stdout on bare-metal anyway)
}

void NVIC_SystemReset() {
    // In real STM32: write to AIRCR register
    // For bare-metal: infinite loop
    while(1) {
        __asm volatile("nop");
    }
}