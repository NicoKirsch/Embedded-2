#include "mock_hal.hpp"
#include <iostream>
#include <chrono>
#include <thread>

uint32_t HAL_GetTick() {
    // Gibt die Zeit seit Start in Millisekunden zurück
    auto now = std::chrono::steady_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
}

void HAL_Delay(uint32_t ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void HAL_GPIO_WritePin(const char* port, int pin, int state) {
    std::cout << "[HAL] Port: " << port << " Pin: " << pin 
              << " State: " << (state ? "HIGH" : "LOW") << std::endl;
}