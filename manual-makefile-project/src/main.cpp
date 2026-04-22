#include "heartbeat.hpp"
#include "mock_hal.hpp"

int main() {
    
    Heartbeat heart;
    
    // Watchdog initialisieren
    // Beispiel: 200ms
    heart.init(200);

    int loopCounter = 0; // Zähler für die Anzahl der Schleifendurchläufe
    // watchdog parallel zum Hauptprogramm laufen lassen

    while (true) {
        HAL_GPIO_WritePin(LEDPIN_GPIO_Port, LEDPIN_Pin, GPIO_PIN_SET); // digitalWrite(Pinx,1);
        HAL_Delay(1);
        
        // Watchdog füttern
        heart.tick();

        HAL_GPIO_WritePin(LEDPIN_GPIO_Port, LEDPIN_Pin, GPIO_PIN_RESET); //  digitalWrite(Pinx,0);
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