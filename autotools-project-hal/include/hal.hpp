#pragma once
#include <stdint.h>
#include <stddef.h>

namespace hal {

    // ---------- time ----------
uint32_t millis();              // must be provided by platform
void delay_ms(uint32_t ms);     // must be provided by platform

// ---------- gpio ----------
enum class PinMode { Input, Output, InputPullup };
void pinMode(uint8_t pin, PinMode mode);
void digitalWrite(uint8_t pin, bool level);
bool digitalRead(uint8_t pin);

// ---------- adc ----------
void adc_init();
uint16_t adc_read(uint8_t channel); // returns raw ADC units

// ---------- pwm ----------
void pwm_init(uint8_t pin, uint32_t freq_hz);
void pwm_set_duty(uint8_t pin, float duty_0_1);

// ---------- uart ----------
void uart_init(uint32_t baud);
bool uart_available();
char uart_read();
void uart_write(char c);
void uart_write_str(const char* s);

// ---------- i2c ----------
void i2c_init(uint32_t freq_hz);
bool i2c_probe(uint8_t addr);
bool i2c_write(uint8_t addr, const uint8_t* data, size_t n);
bool i2c_read(uint8_t addr, uint8_t* data, size_t n);

// ---------- eeprom ----------
bool eeprom_read(uint16_t addr, void* dst, size_t n);
bool eeprom_write(uint16_t addr, const void* src, size_t n);

// ---------- watchdog ----------
void wdt_enable(uint32_t timeout_ms);
void wdt_kick();

// ---------- sleep ----------
void sleep_enable();
void sleep_now();
} // namespace hal