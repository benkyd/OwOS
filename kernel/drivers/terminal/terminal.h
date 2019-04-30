#pragma once

#include <lib/stdint.h>

enum {
    VGA_BLACK          = 0x0,
    VGA_BLUE           = 0x1,
    VGA_GREEN          = 0x2,
    VGA_CYAN           = 0x3,
    VGA_RED            = 0x4,
    VGA_MAGENTA        = 0x5,
    VGA_BROWN          = 0x6,
    VGA_GREY           = 0x7,
    VGA_DARK_GREY      = 0x8,
    VGA_BRIGHT_BLUE    = 0x9,
    VGA_BRIGHT_GREEN   = 0xA,
    VGA_BRIGHT_CYAN    = 0xB,
    VGA_BRIGHT_RED     = 0xC,
    VGA_BRIGHT_MAGENTA = 0xD,
    VGA_YELLOW         = 0xE,
    VGA_WHITE          = 0xF,
};

struct VGAChar_t {
    char c;
    char foreground:4;
    char background:4;
}__attribute__((packed));

struct Cursor {
    uint8_t x;
    uint8_t y;
} __attribute__((packed));

static const int TERMINAL_WIDTH = 80;
static const int TERMINAL_HEIGHT = 24;

void Cls();

void Puts(char input);
void Puts(int x, int y, char c, char foreground, char background);

void Nline();

void Write(char* input);
void Writeln(char* input);

void SetClearColour(char col);
void SetFGColour(char col);
void SetBGColour(char col);
void ResetTermColours();

void ShowCursor();
void HideCursor();

void UpdateCursor(Cursor c);
void SetCursorPosition(int x, int y);
Cursor GetCursorPosition();
