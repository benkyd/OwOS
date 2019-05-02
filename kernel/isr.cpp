
#include <kernel/drivers/terminal/terminal.h>
#include <kernel/panic.h>
#include <kernel/kernio.h>

struct Regs_t {
    unsigned int gs, fs, es, ds;      /* pushed the segs last */
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
    unsigned int int_no, err_code;    /* our 'push byte #' and ecodes do this */
    unsigned int eip, cs, eflags, useresp, ss;   /* pushed by the processor automatically */ 
};

char *PanicMessage[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Break Point",
    "Into Detect Overflow",
    "Out of bounds Exception",
    "Invalid Opcode",
    "No Coprocessor",
    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS Exception",
    "Segment not present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",
    "Coprocessor Fault",
    "Alignement Check Exception",
    "Machine Check Exception",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

extern "C" {

void DEFAULT_ISR() {
    Write("SMH \n");
    outb(0x20,0x20);
}

void KeyboardHandler() {
    Write("Keyboard Pressed! \n");
    outb(0x20,0x20);
}

void FaultHandler(struct Regs_t *r) {
    uint32_t val;
    asm volatile ( "mov %%cr2, %0" : "=r"(val) );
    PanicKernel(val, PanicMessage[r->int_no]);
    for (;;)
        asm("hlt");
}

}
