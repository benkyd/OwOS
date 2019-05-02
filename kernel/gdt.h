#pragma once

#include <lib/stdint.h>

#define GDT_ACCESS_PRESENT  0x90
#define GDT_ACCESS_PR_TSS   0x80
#define GDT_ACCESS_PRIV_3   0x60
#define GDT_ACCESS_PRIV_2   0x40
#define GDT_ACCESS_PRIV_1   0x20
#define GDT_ACCESS_EXEC     0x08
#define GDT_ACCESS_DIR_D    0x04
#define GDT_ACCESS_RW       0x02
#define GDT_ACCESS_ACCESSED 0x01

#define GDT_FLAG_GR_PAGE    0x08
#define GDT_FLAG_SZ_32B     0x04

extern "C" {
    extern void SEGMENTS_RELOAD(void);
}

void GDT_Init();
void GDT_Set_Gate(uint32_t index, uint32_t baseAddr, uint32_t limitAddr, uint8_t accessLvl, uint8_t flags);
