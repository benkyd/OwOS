#include <kernel/drivers/VGA/vga.h>
#include <kernel/drivers/terminal/terminal.h>

extern "C"

int kernel_main() {

    cls();
    showCursor();

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
