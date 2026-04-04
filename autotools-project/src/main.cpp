#include <iostream>
#include <unistd.h> 
#include "heartbeat.hpp"

int main() {
    Heartbeat heart;
    
    // Watchdog initialisieren
    // Beispiel: 1s
    heart.init(1000);

    while (true) {
        digitalWrite(Pinx,HIGH);
        delay_ms(1);
        
        // Watchdog füttern
        heart.tick();
        
        digitalWrite(Pinx,LOW);
        delay(ms);

        //Watchdog füttern
        heart.tick();
    }

    return 0;
}