#include "terminal.h"

#include <kernel/kernio.h>
#include <lib/std/string.h>

static VGAChar_t* frameBuffer = (VGAChar_t*)0xB8000;

static char clearColour = 0x0;
static char bgColour    = 0x0; 
static char fgColour    = 0xF;

Cursor cursor;

void Cls() {
    for (uint8_t x = 0; x < TERMINAL_WIDTH; x++)
        for (uint8_t y = 0; y < TERMINAL_HEIGHT; y++)
            Puts(x, y, ' ', fgColour, clearColour);

    cursor.x = 0; cursor.y = 0;
    UpdateCursor(cursor);
}

void Puts(char input) {
    if (cursor.x + 1 > TERMINAL_WIDTH) {
        Nline();
    }
    if (input == '\n') {
        Nline();
    } else {
        Puts(cursor.x, cursor.y, input, fgColour, bgColour);
        cursor.x++;
    }
    UpdateCursor(cursor);
}

void Puts(int x, int y, char c, char foreground, char background) {
    frameBuffer[(y * TERMINAL_WIDTH) + x].c = c;
    frameBuffer[(y * TERMINAL_WIDTH) + x].foreground = foreground;
    frameBuffer[(y * TERMINAL_WIDTH) + x].background = background;
}

void Nline() {
    cursor.y++;
    cursor.x = 0;
    UpdateCursor(cursor);
}

void Write(char* input) {
	for (uint32_t i = 0; i < strlen(input); i++) {
		if (cursor.x + 1 > TERMINAL_WIDTH) {
			Nline();
		}
		if (input[i] == '\n') {
			Nline();
		}
		else {
			Puts(cursor.x, cursor.y, input[i], fgColour, bgColour);
			cursor.x++;
		}
	}
	UpdateCursor(cursor);
}

void Writeln(char* input) {
	Write(input);
	Nline();
}

void SetClearColour(char col) {
    clearColour = col;
}

void SetFGColour(char col) {
    fgColour = col;
}

void SetBGColour(char col) {
    bgColour = col;
}

void ResetTermColours() {
    bgColour = 0x0;
    fgColour = 0xF;
}

void ShowCursor() {
    outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | 0x0); // Cursor start top
 
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | 0xF); // Cursor start bottom
}

void HideCursor() {
    outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}

void UpdateCursor(Cursor c) {
    uint16_t pos = c.y * TERMINAL_WIDTH + c.x;
 
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void SetCursorPosition(int x, int y) {
    cursor.x = x; cursor.y = y;
    UpdateCursor(cursor);
}

Cursor GetCursorPosition() {
    return cursor;
}

uint8_t getVGACol(char f, char b) {
    return f | b << 4;
}
