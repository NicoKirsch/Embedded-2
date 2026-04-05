#include "../include/heartbeat.hpp"
#include <iostream>

void Heartbeat::init(uint32_t t_ms) {
    last = t_ms; //initialisieren des Watchdog (nach wievielen Sekunden wird der Watchdog zurückgesetzt)
}

void Heartbeat::feed() {
    //Rückmeldung an den Watchdog
}
