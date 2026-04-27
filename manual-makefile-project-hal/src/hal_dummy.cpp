#include "hal.hpp"
#include <chrono>
#include <iostream>
#include <cstdlib>

namespace hal {
static uint32_t wdt_timeout = 0;
static uint32_t wdt_last_kick = 0;

static auto t0 = std::chrono::steady_clock::now();

uint32_t millis() {
auto now = std::chrono::steady_clock::now();
return (uint32_t)std::chrono::duration_cast<std::chrono::milliseconds>(now - t0).count();
}
void delay_ms(uint32_t ms) { auto end = millis()+ms; while(millis()<end){} }

// void pinMode(uint8_t, PinMode) {}
void digitalWrite(uint8_t, bool) {}
// bool digitalRead(uint8_t) { return false; }

// void adc_init() {}
// uint16_t adc_read(uint8_t) { return 0; }

// void pwm_init(uint8_t, uint32_t) {}
// void pwm_set_duty(uint8_t, float) {}

// void uart_init(uint32_t) {}
// bool uart_available(){ return false; }
// char uart_read(){ return 0; }
// void uart_write(char){ }
// void uart_write_str(const char*){}

// void i2c_init(uint32_t){}
// bool i2c_probe(uint8_t){ return false; }
// bool i2c_write(uint8_t,const uint8_t*, size_t){ return false; }
// bool i2c_read(uint8_t,uint8_t*, size_t){ return false; }

// bool eeprom_read(uint16_t, void*, size_t){ return false; }
// bool eeprom_write(uint16_t, const void*, size_t){ return false; }

void wdt_enable(uint32_t timeout_ms) {
    wdt_timeout = timeout_ms;
    wdt_last_kick = millis();
}
void wdt_kick() {
    wdt_last_kick = millis();
}
void wdt_check() {
    if (wdt_timeout > 0) {
        if (millis() - wdt_last_kick > wdt_timeout) {
            std::cout << "[HAL] Watchdog RESET!" << std::endl;
            std::exit(1);
        }
    }
}

// void sleep_enable() {}
// void sleep_now() {}
} // namespace hal