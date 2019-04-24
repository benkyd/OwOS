#include <kernel/drivers/VGA/vga.h>

extern "C"

int kernel_main() {

    putchar(0, 0, 'H', 0x01, 0x07);
    putchar(1, 0, 'A', 0x01, 0x07);
    putchar(2, 0, 'H', 0x01, 0x07);
    putchar(3, 0, 'A', 0x01, 0x07);
    putchar(4, 0, '!', 0x01, 0x07);
    putchar(5, 0, ' ', 0x01, 0x07);
    putchar(6, 0, 'P', 0x01, 0x07);
    putchar(7, 0, 'E', 0x01, 0x07);
    putchar(8, 0, 'N', 0x01, 0x07);
    putchar(9, 0, 'I', 0x01, 0x07);
    putchar(10, 0, 'S', 0x01, 0x07);
    putchar(11, 0, '!', 0x01, 0x07);
    
    for (;;)
        asm("hlt");
        
}
