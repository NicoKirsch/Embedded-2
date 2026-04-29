#include "heartbeat.hpp"
#include "mock_hal.hpp"

void Heartbeat::init(uint32_t t_ms) {
    p = t_ms;   // initialisieren des Watchdog (nach wievielen Sekunden wird der Watchdog getriggerd)
    s = false;  // Watchdog nicht ausgelöst
    last = HAL_GetTick(); // aktueller Zeitpunkt in ms
}

void Heartbeat::tick() {
    // Überprüfen, ob Watchdog innerhalb der Zeit getriggert
    auto now = HAL_GetTick();   // aktueller Zeitpunkt in ms
    if (now - last >= p) {      // wenn mehr als p ms vergangen ist, Watchdog auslösen
        // stm32 Watchdog auslösen
        s = true;               // Watchdog ausgelöst    
        NVIC_SystemReset();
    }
    last = now;                 //aktueller Zeitpunkt in ms
}