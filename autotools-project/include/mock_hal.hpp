#ifndef MOCK_HAL_HPP
#define MOCK_HAL_HPP

#include <cstdint>


// Mocks für die Hardware-Definitionen vom STM32
#define LEDPIN_GPIO_Port "GPIOB"
#define LEDPIN_Pin 3

// Wir mappen die STM-Namen auf unsere Mock-Funktionen
uint32_t HAL_GetTick();
void HAL_Delay(uint32_t ms);
void HAL_GPIO_WritePin(const char* port, int pin, int state);

#define GPIO_PIN_SET 1
#define GPIO_PIN_RESET 0

#endif