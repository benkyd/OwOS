#define TERM_WIDTH 80
#define TERM_HEIGHT 25

struct VGAChar_t {
    char c;
    char foreground:4;
    char background:4;
}__attribute__((packed));

void putchar(int x, int y, char c, char foreground, char background);
