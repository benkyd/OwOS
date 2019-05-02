#include <kernel/multiboot.h>

#include <kernel/drivers/terminal/terminal.h>

#include <kernel/kernio.h>
#include <kernel/panic.h>
#include <kernel/pic.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>

#include <lib/std/stdlib.h>
#include <lib/std/memory.h>
#include <lib/kernel/logger/logger.h>

extern "C" {
	extern void INIT_FPU(void);
}

extern "C"

int kernel_main(uint32_t magic, MultibootInfo_t* multiboot) {
    Cls();
    ShowCursor();
	SetFGColour(VGA_GREEN);
	Writeln("OwOS V0.2 Starting Up...");
	SetFGColour(VGA_WHITE);
	Nline();

	// Init systems

	GDT_Init();
	loggerOK("GDT Init");
	
	PIC_Default_Remap();
	loggerOK("PIC Remapped");

	IDT_Init();
	loggerOK("IDT Init");

	Nline(); Nline();	
	Write("OwO, What's This?");
	SetFGColour(VGA_BRIGHT_MAGENTA);
	Write(" *notices ");
	Write(itoa(multiboot->mem_upper / 1024));
	Writeln("mb of ram*");
	SetFGColour(VGA_WHITE);
	Nline(); 

	SetFGColour(VGA_YELLOW);
	Writeln("Welcome to OwOS");
	SetFGColour(VGA_BRIGHT_MAGENTA);
    Write("~#");

	// PanicKernel(0x00, "Self Triggered Panic", "kernel.cpp:48", "kernel_main(uint32_t magic, MultibootInfo_t* multiboot)");

    for (;;)
        asm("hlt");
        
}
