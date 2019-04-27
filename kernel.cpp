#include <lib/std/stdlib.h>
#include <kernel/multiboot.h>
#include <lib/kernel/logger/logger.h>
#include <kernel/drivers/terminal/terminal.h>

extern "C" {
	extern void ASM_INIT_FPU(void);
}

extern "C"

int kernel_main(uint32_t magic, multibootInfo_t* multiboot) {
    cls();
    showCursor();
	setFGColour(VGA_GREEN);
	write("OwOS V0.2 ");
	writeln("Starting Up...");
	setFGColour(VGA_WHITE);
	nline();


	write("OwO, What's This? ");
	write("*notices ");
	write(itoa(multiboot->mem_upper / 1024));
    write("mb of ram*");
	setFGColour(VGA_BRIGHT_MAGENTA);
	nline(); nline(); nline();


    ASM_INIT_FPU();


    write("~#");

    for (;;)
        asm("hlt");
        
}
