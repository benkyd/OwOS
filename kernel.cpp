#include <lib/std/stdlib.h>
#include <kernel/multiboot.h>
#include <kernel/drivers/terminal/terminal.h>

extern "C"

int kernel_main(uint32_t magic, multibootInfo_t* multiboot) {

    cls();
    showCursor();
    
	write("OwOS ");
	setFGColour(VGA_GREEN);
	write("Starting Up...");
	setFGColour(VGA_WHITE);

	nline();

	write("OwO, What's This? ");
	write("*notices ");
	
	char* ram = "";
	itoa((int)multiboot->mem_upper, ram);

	write(ram);
	write("mb of ram*");
	setFGColour(VGA_BRIGHT_MAGENTA);
	write(" OwO That's a lot of memory");
	setFGColour(VGA_WHITE);
	nline();
	nline();
	nline();


    writeln("Okay, this is pretty epic");

    for (;;)
        asm("hlt");
        
}
