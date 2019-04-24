#define TERM_WIDTH 80
#define TERM_HEIGHT 25

struct VGAChar_t {
    char c;
    char foreground:4;
    char background:4;
}__attribute__((packed));

VGAChar_t* framebuffer = (VGAChar_t*)0xB8000;

void putcar(int x, int y, char c, char foreground, char background) {
    framebuffer[(y * TERM_WIDTH) + x].c = c;
    framebuffer[(y * TERM_WIDTH) + x].foreground = foreground;
    framebuffer[(y * TERM_WIDTH) + x].background = background;
}

extern "C"

int kernel_main() {

    for (int x = 0; x < TERM_WIDTH; x++)
        for (int y = 0; y < TERM_HEIGHT; y++)
            putcar(x, y, ' ', 0x00, 0x00);

    putcar(0, 0, 'H', 0x01, 0x07);
    putcar(1, 0, 'A', 0x01, 0x07);
    putcar(2, 0, 'H', 0x01, 0x07);
    putcar(3, 0, 'A', 0x01, 0x07);
    putcar(4, 0, '!', 0x01, 0x07);
    putcar(5, 0, ' ', 0x01, 0x07);
    putcar(6, 0, 'P', 0x01, 0x07);
    putcar(7, 0, 'E', 0x01, 0x07);
    putcar(8, 0, 'N', 0x01, 0x07);
    putcar(9, 0, 'I', 0x01, 0x07);
    putcar(10, 0, 'S', 0x01, 0x07);
    putcar(11, 0, '!', 0x01, 0x07);
    
    for (;;)
        asm("hlt");
}
