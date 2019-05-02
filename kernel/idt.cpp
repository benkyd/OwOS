#include "idt.h"

#include <kernel/drivers/terminal/terminal.h>
#include <lib/std/stdlib.h>

struct IDT_Descriptor_t {
	uint16_t offset_low;
	uint16_t selector;
	uint8_t zero;
	uint8_t type_attr;
	uint16_t offset_high;
} __attribute__((packed));

struct IDT_t {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));


IDT_Descriptor_t _IDT[256];
IDT_t            _IDTptr;

void lidt(IDT_t IDT) {
	asm("lidt %0" : : "m"(IDT));
}

void IDT_Set_Gate(uint8_t i, uint32_t offset, uint16_t selector, uint8_t attrib);

void IDT_Init() {
    _IDTptr.limit = (sizeof(IDT_Descriptor_t) * 256) - 1;
    _IDTptr.base  = (uint32_t)&_IDT;

	for (uint16_t i = 0; i < 256; i++)
	        IDT_Set_Gate(i, (uint32_t)&ISR_DEFAULT, 0x01, IDT_ATTR_PRESENT | IDT_TRAP_GATE | IDT_ATTR_PRIV_3);

	IDT_Set_Gate(0x00, (uint32_t)&ISR0, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x01, (uint32_t)&ISR1, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x02, (uint32_t)&ISR2, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x03, (uint32_t)&ISR3, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x04, (uint32_t)&ISR4, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x05, (uint32_t)&ISR5, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x06, (uint32_t)&ISR6, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x07, (uint32_t)&ISR7, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x08, (uint32_t)&ISR8, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x09, (uint32_t)&ISR9, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x0A, (uint32_t)&ISR10, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x0B, (uint32_t)&ISR11, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x0C, (uint32_t)&ISR12, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x0D, (uint32_t)&ISR13, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x0E, (uint32_t)&ISR14, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x0F, (uint32_t)&ISR15, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x10, (uint32_t)&ISR16, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x11, (uint32_t)&ISR17, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x12, (uint32_t)&ISR18, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x13, (uint32_t)&ISR19, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x14, (uint32_t)&ISR20, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x15, (uint32_t)&ISR21, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x16, (uint32_t)&ISR22, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x17, (uint32_t)&ISR23, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x18, (uint32_t)&ISR24, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x19, (uint32_t)&ISR25, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x1A, (uint32_t)&ISR26, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x1B, (uint32_t)&ISR27, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x1C, (uint32_t)&ISR28, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x1D, (uint32_t)&ISR29, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x1E, (uint32_t)&ISR30, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);
    IDT_Set_Gate(0x1F, (uint32_t)&ISR31, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);

    IDT_Set_Gate(0x21, (uint32_t)&ISR_KBD, 0x01, IDT_ATTR_PRESENT | IDT_INT_GATE);

	lidt(_IDTptr);
}

void IDT_Set_Gate(uint8_t i, uint32_t offset, uint16_t selector, uint8_t attrib) {
	if (i > 256) return;
    _IDT[i].offset_low  = offset & 0xFFFF;
    _IDT[i].selector    = selector * 8;
    _IDT[i].zero        = 0;
    _IDT[i].type_attr   = attrib;
    _IDT[i].offset_high = (offset & 0xFFFF) >> 16;
}
