#include "terminal.h"

#include <kernel/kernio.h>

static const int TERMINAL_WIDTH = 80;
static const int TERMINAL_HEIGHT = 24;

static char* frameBuffer = (char*)0xB8000;

static char clearColour = 0x0;
static char bgColour    = 0x0;
static char fgColour    = 0xF;

struct Cursor {
    uint8_t x;
    uint8_t y;
} __attribute__((packed));

Cursor cursor;

void cls() {
    for (uint8_t x = 0; x < TERMINAL_WIDTH; x++) {
        for (uint8_t y = 0; y < TERMINAL_HEIGHT; y++) {
            frameBuffer[x + TERMINAL_WIDTH * y] = 0;
        }
    }

    moveCursor(0,0);
}

void putchar(char input) {

}

void write(char* input) {

}

void writeln(char* input) {
    write(input);
    nline();
}

void nline() {

}

void setClearColour(char col) {
    clearColour = col;
}

void showCursor() {
    outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | 1);
 
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | 1);
}

void hideCursor() {
    outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}

void moveCursor(int x, int y) {
    uint16_t pos = y * TERMINAL_WIDTH + x;
 
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}
