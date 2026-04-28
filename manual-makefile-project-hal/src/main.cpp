#include "heartbeat.hpp"
#include "hal.hpp"

int main() {
    
    Heartbeat heart;
    
    // Watchdog initialisieren
    // Beispiel: 200ms
    heart.init(200);

    int loopCounter = 0;                // Zaehler fuer die Anzahl der Schleifendurchlaeufe
    // Watchdog parallel zum Hauptprogramm laufen lassen

    while (true) {
        hal::digitalWrite(13, true);    // digitalWrite(Pinx,1);
        hal::delay_ms(1);
        
        // Watchdog Signal senden
        heart.tick();

        hal::digitalWrite(13, false);   // digitalWrite(Pinx,0);
        hal::delay_ms(1);

        // Watchdog Signal senden
        heart.tick();

        loopCounter++;

        if (loopCounter == 10) {        // nach 10 Schleifendurchlaeufen den Watchdog kein Signal mehr senden
            hal::delay_ms(2000);        // Simuliere eine Verzoegerung, die den Watchdog ausloest
        }
    }

    return 0;
}