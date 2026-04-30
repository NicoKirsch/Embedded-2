#include "heartbeat.hpp"
#include "hal.hpp"
#include <iostream>

void Heartbeat::init(uint32_t t_ms) {
    p = t_ms;               // initialisieren des Watchdog (nach wievielen Sekunden wird der Watchdog zurueckgesetzt)
    s = false;              // Watchdog nicht ausgeloest
    last = hal::millis();   // aktueller Zeitpunkt in ms
}

void Heartbeat::tick() {
    //ueberpruefen, ob der Watchdog zurueckgesetzt werden muss
    auto now = hal::millis();   // aktueller Zeitpunkt in ms
    
    if (now - last >= p) {      // wenn mehr als p ms vergangen ist, loese Watchdog aus
        
        s = true;               // Watchdog ausgeloest
        std::cout << "Watchdog ausgeloest!" << std::endl;    
        NVIC_SystemReset();     // Systemneustart triggern
    }
    last = now;                 // aktueller Zeitpunkt in ms
}