#pragma once

#include <lib/stdint.h>

#define IDT_ATTR_PRESENT    0x80
#define IDT_ATTR_PRIV_3     0x60
#define IDT_ATTR_PRIV_2     0x40
#define IDT_ATTR_PRIV_1     0x20
#define IDT_INT_GATE        0x0E
#define IDT_TRAP_GATE       0x0F
#define IDT_TASK_GATE       0x15


void IDT_Init();
void IDT_Set_Gate();

#define ISR_DEF(id) extern void ISRid(void)

extern "C" {
    extern void ISR_DEFAULT(void);
    extern void ISR_KBD(void);

    extern void ISR0(void);
    extern void ISR1(void);
    extern void ISR2(void);
    extern void ISR3(void);
    extern void ISR4(void);
    extern void ISR5(void);
    extern void ISR6(void);
    extern void ISR7(void);
    extern void ISR8(void);
    extern void ISR9(void);
    extern void ISR10(void);
    extern void ISR11(void);
    extern void ISR12(void);
    extern void ISR13(void);
    extern void ISR14(void);
    extern void ISR15(void);
    extern void ISR16(void);
    extern void ISR17(void);
    extern void ISR18(void);
    extern void ISR19(void);
    extern void ISR20(void);
    extern void ISR21(void);
    extern void ISR22(void);
    extern void ISR23(void);
    extern void ISR24(void);
    extern void ISR25(void);
    extern void ISR26(void);
    extern void ISR27(void);
    extern void ISR28(void);
    extern void ISR29(void);
    extern void ISR30(void);
    extern void ISR31(void);
}
