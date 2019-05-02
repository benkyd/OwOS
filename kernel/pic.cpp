#include "pic.h"

#include <kernel/kernio.h>

void PIC_Default_Remap() {
	outb(0x20, 0x11);
	io_wait();
    outb(0xA0, 0x11);
	io_wait();
    outb(0x21, 0x20);
	io_wait();
    outb(0xA1, 0x28);
	io_wait();
    outb(0x21, 0x04);
	io_wait();
    outb(0xA1, 0x02);
	io_wait();
    outb(0x21, 0x01);
	io_wait();
    outb(0xA1, 0x01);
	io_wait();
    outb(0x21, 0x0);
	io_wait();
    outb(0xA1, 0x0);
}

void PIC_Remap(int offset1, int offset2) {
	unsigned char a1, a2;
 
	a1 = inb(PIC1_DATA);                        // save masks
	a2 = inb(PIC2_DATA);
 
	outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);  // starts the initialization sequence (in cascade mode)
	io_wait();
	outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
	io_wait();
	outb(PIC1_DATA, offset1);                 // ICW2: Master PIC vector offset
	io_wait();
	outb(PIC2_DATA, offset2);                 // ICW2: Slave PIC vector offset
	io_wait();
	outb(PIC1_DATA, 4);                       // ICW3: tell Master PIC that there is a slave PIC at IRQ2 (0000 0100)
	io_wait();
	outb(PIC2_DATA, 2);                       // ICW3: tell Slave PIC its cascade identity (0000 0010)
	io_wait();
 
	outb(PIC1_DATA, ICW4_8086);
	io_wait();
	outb(PIC2_DATA, ICW4_8086);
	io_wait();
 
	outb(PIC1_DATA, a1);   // restore saved masks.
	outb(PIC2_DATA, a2);
}
