#include <lib/std/string.h>
#include <lib/stdint.h>

enum {
    BLACK          = 0x0,
    BLUE           = 0x1,
    GREEN          = 0x2,
    CYAN           = 0x3,
    RED            = 0x4,
    MAGENTA        = 0x5,
    BROWN          = 0x6,
    GREY           = 0x7,
    DARK_GREY      = 0x8,
    BRIGHT_BLUE    = 0x9,
    BRIGHT_GREEN   = 0xA,
    BRIGHT_CYAN    = 0xB,
    BRIGHT_RED     = 0xC,
    BRIGHT_MAGENTA = 0xD,
    YELLOW         = 0xE,
    WHITE          = 0xF,
};

void cls();

void putchar(char input);

void write(char* input);
void writeln(char* input);

void nline();

void setClearColour(char col);

void showCursor();
void hideCursor();

void moveCursor(int x, int y);
