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

static inline uint16_t inw(uint16_t port) {
    uint16_t ret;
    asm  ( "inw %1, %0"
         : "=a"(ret)
         : "Nd"(port) );
    return ret;
}

static inline void outw(uint16_t port, uint16_t val) {
    asm ( "outw %0, %1" : : "a"(val), "Nd"(port) );
}

static inline uint32_t inl(uint16_t port) {
    uint32_t ret;
    asm ( "inl %1, %0"
        : "=a"(ret)
        : "Nd"(port) );
    return ret;
}

static inline void outl(uint16_t port, uint32_t val) {
    asm ( "outl %0, %1" : : "a"(val), "Nd"(port) );
}

static inline void io_wait(void) {
    /* TODO: This is probably fragile. */
    asm  ( "jmp 1f\n\t"
           "1:jmp 2f\n\t"
           "2:" );
}
