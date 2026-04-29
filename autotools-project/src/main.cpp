#include "heartbeat.hpp"
#include "mock_hal.hpp"

int main() {
    
    Heartbeat heart;
    
    // Watchdog initialisieren (Beispiel: 200ms)
    heart.init(200);

    int loopCounter = 0; // Zähler für Anzahl der Schleifendurchläufe
    // watchdog läuft parallel zum Hauptprogramm

    while (true) {
        HAL_GPIO_WritePin(LEDPIN_GPIO_Port, LEDPIN_Pin, GPIO_PIN_SET); // digitalWrite(Pinx,1);
        HAL_Delay(1);
        
        // Watchdog triggern
        heart.tick();

        HAL_GPIO_WritePin(LEDPIN_GPIO_Port, LEDPIN_Pin, GPIO_PIN_RESET); //  digitalWrite(Pinx,0);
        HAL_Delay(1);

        //Watchdog triggern
        heart.tick();

        loopCounter++;
        if (loopCounter == 10) {    // nach 10 Schleifendurchläufen den Watchdog nicht mehr triggern
            HAL_Delay(2000);        // Verzögerung auslösen; Restart triggern
        }
    }
    return 0;
}