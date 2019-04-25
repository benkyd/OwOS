#include "terminal.h"

#include <kernel/kernio.h>

static const int TERMINAL_WIDTH = 80;
static const int TERMINAL_HEIGHT = 24;

static VGAChar_t* frameBuffer = (VGAChar_t*)0xB8000;

static char clearColour = 0x0;
static char bgColour    = 0x0; 
static char fgColour    = 0xF;

Cursor cursor;

void cls() {
    for (uint8_t x = 0; x < TERMINAL_WIDTH; x++)
        for (uint8_t y = 0; y < TERMINAL_HEIGHT; y++)
            puts(x, y, ' ', fgColour, clearColour);

    cursor.x = 0; cursor.y = 0;
    updateCursor(cursor);
}

void puts(char input) {
    if (cursor.x + 1 > TERMINAL_WIDTH) {
        nline();
    }
    if (input == '\n') {
        nline();
    } else {
        puts(cursor.x, cursor.y, input, fgColour, bgColour);
        cursor.x++;
    }
    updateCursor(cursor);
}

void puts(int x, int y, char c, char foreground, char background) {
    frameBuffer[(y * TERMINAL_WIDTH) + x].c = c;
    frameBuffer[(y * TERMINAL_WIDTH) + x].foreground = foreground;
    frameBuffer[(y * TERMINAL_WIDTH) + x].background = background;
}

void write(char* input) {
    for (uint32_t i = 0; i < strlen(input); i++) {
        if (cursor.x + 1 > TERMINAL_WIDTH) {
            nline();
        }
        if (input[i] == '\n') {
            nline();
        } else {
            puts(cursor.x, cursor.y, input[i], fgColour, bgColour);
            cursor.x++;
        }
    }
    updateCursor(cursor);
}

void writeln(char* input) {
    write(input);
    nline();
}

void nline() {
    cursor.y++;
    cursor.x = 0;
    updateCursor(cursor);
}

void setClearColour(char col) {
    clearColour = col;
}

void setFGColour(char col) {
    fgColour = col;
}

void setBGColour(char col) {
    bgColour = col;
}

void showCursor() {
    outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | 0x0); // Cursor start top
 
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | 0xF); // Cursor start bottom
}

void hideCursor() {
    outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}

void updateCursor(Cursor c) {
    uint16_t pos = c.y * TERMINAL_WIDTH + c.x;
 
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void setCursorPosition(int x, int y) {
    cursor.x = x; cursor.y = y;
    updateCursor(cursor);
}

uint8_t getVGACol(char f, char b) {
    return f | b << 4;
}
