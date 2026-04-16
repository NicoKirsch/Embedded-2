#include "heartbeat.hpp"
#include "stm32l4xx_hal.h"

int main() {
    HAL_Init();
    
    Heartbeat heart;
    
    // Watchdog initialisieren
    // Beispiel: 1s
    heart.init(1000);

    int loopCounter = 0; // Zähler für die Anzahl der Schleifendurchläufe
    int Pinx = 13; // Beispiel Pin für LED
    // watchdog parallel zum Hauptprogramm laufen lassen

    while (true) {
        HAL_GPIO_WritePin(GPIOC, (1 << Pinx), GPIO_PIN_SET); // digitalWrite(Pinx,1);
        HAL_Delay(1);
        
        // Watchdog füttern
        heart.tick();

        HAL_GPIO_WritePin(GPIOC, (1 << Pinx), GPIO_PIN_RESET); //  digitalWrite(Pinx,0);
        HAL_Delay(1);

        //Watchdog füttern
        heart.tick();

        loopCounter++;
        if (loopCounter == 10) { // Nach 10 Schleifendurchläufen den Watchdog nicht mehr füttern
            HAL_Delay(2000); // Simuliere eine Verzögerung, die den Watchdog auslöst
        }
    }

    return 0;
}