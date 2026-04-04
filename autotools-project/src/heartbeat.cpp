#include "../include/utils.hpp"
#include <iostream>

void Watchdog::init(uint32_t t_ms) {
    last = t_ms;
    std::cout << "Watchdog initialisiert mit: " << last << " ms\n";
}

void Watchdog::feed() {
    std::cout << "Watchdog gefuettert\n";
}
