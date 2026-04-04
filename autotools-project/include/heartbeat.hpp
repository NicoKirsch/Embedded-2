#ifndef HEARTBEAT_HPP
#define HEARTBEAT_HPP

#include<cstdint>

class Heartbeat{
private:
    uint32_t: last;
    bool: s;
    uint8: p;

public:
    void init(uint32_t t_ms);
    void tick();
};

