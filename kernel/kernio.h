#pragma once

#include <lib/stdint.h>

inline void outb(uint16_t port, uint8_t b) {
    asm("outb %0, %1" : : "a"(b), "Nd"(port));
}

inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    asm ( "inb %1, %0"
        : "=a"(ret)    // Output
        : "Nd"(port)); // Input
    return ret;
}

