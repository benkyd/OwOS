#include <lib/std/string.h>
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

void cls();

void putchar(char input);
void putchar(int x, int y, char c, char foreground, char background);

void write(char* input);
void writeln(char* input);

void nline();

void setClearColour(char col);
void setFGColour(char col);
void setBGColour(char col);

void showCursor();
void hideCursor();

void updateCursor(Cursor c);
void setCursorPosition(int x, int y);
