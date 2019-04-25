#include <kernel/drivers/terminal/terminal.h>

extern "C"

int kernel_main() {

    cls();
    showCursor();
    
    writeln("Okay, this is pretty epic");

    for (;;)
        asm("hlt");
        
}
