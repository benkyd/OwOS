#include <kernel/multiboot.h>

#include <kernel/drivers/terminal/terminal.h>
#include <kernel/kernio.h>
#include <kernel/gdt.h>

#include <lib/std/stdlib.h>
#include <lib/std/memory.h>
#include <lib/kernel/logger/logger.h>

extern "C" {
	extern void INIT_FPU(void);
}

extern "C"

int kernel_main(uint32_t magic, multibootInfo_t* multiboot) {
    cls();
    showCursor();
	setFGColour(VGA_GREEN);
	writeln("OwOS V0.2 Starting Up...");
	setFGColour(VGA_WHITE);
	nline();

	// Init systems

	initGDT();
	loggerOK("GDT Loaded");



	nline(); nline();	
	write("OwO, What's This?");
	setFGColour(VGA_BRIGHT_MAGENTA);
	write(" *notices ");
	write(itoa(multiboot->mem_upper / 1024));
	writeln("mb of ram*");
	setFGColour(VGA_WHITE);
	nline(); 

	setFGColour(VGA_YELLOW);
	writeln("Welcome to OwOS");
	setFGColour(VGA_BRIGHT_MAGENTA);
    write("~#");

    for (;;)
        asm("hlt");
        
}
