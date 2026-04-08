#include <iostream>
#include <unistd.h> 
#include "heartbeat.hpp"
// mocking hal functions
void digitalWrite(int pin, bool state) {
}

void delay_ms(int ms) {
    usleep(ms * 1000); // usleep nimmt Mikrosekunden
}

int main() {
    Heartbeat heart;
    
    // Watchdog initialisieren
    // Beispiel: 1s
    heart.init(1000);

    int loopCounter = 0; // Zähler für die Anzahl der Schleifendurchläufe
    int Pinx = 13; // Beispiel Pin für LED
    // watchdog parallel zum Hauptprogramm laufen lassen

    while (true) {
        digitalWrite(Pinx,1);
        delay_ms(1);
        
        // Watchdog füttern
        heart.tick();

        digitalWrite(Pinx,0);
        delay_ms(1);

        //Watchdog füttern
        heart.tick();

        loopCounter++;
        if (loopCounter == 10) { // Nach 10 Schleifendurchläufen den Watchdog nicht mehr füttern
            delay_ms(2000); // Simuliere eine Verzögerung, die den Watchdog auslöst
        }
    }

    return 0;
}