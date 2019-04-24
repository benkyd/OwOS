#include "vga.h"

VGAChar_t* framebuffer = (VGAChar_t*)0xB8000;

void putchar(int x, int y, char c, char foreground, char background) {
    framebuffer[(y * TERM_WIDTH) + x].c = c;
    framebuffer[(y * TERM_WIDTH) + x].foreground = foreground;
    framebuffer[(y * TERM_WIDTH) + x].background = background;
}
