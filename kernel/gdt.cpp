#include "gdt.h"

#include <kernel/kernio.h>
#include <lib/std/memory.h>

struct SegmentDescriptor_t {
    uint16_t limit_0;
    uint16_t base_0;
    uint8_t base_1;
    uint8_t access;
    uint8_t limit_1:4;
    uint8_t flags:4;
    uint8_t base_2;
} __attribute__((packed));

SegmentDescriptor_t _GDT[256];

void lgdt(void* GDT, uint16_t size) {
    struct {
        uint16_t size;
        void*    GDT;
    } __attribute__((packed)) GDTR = { size, GDT };
 
    asm ( "lgdt %0" : : "m"(GDTR) );
}

void initGDT() {
    memset(&_GDT, 0, sizeof(_GDT));

    // Leave 0 blank for null segment
    // Code   Base 0      limit 32    Access EXEC + RW
    setGDT(1, 0x00000000, 0xFFFFFFFF, GDT_ACCESS_PRESENT | GDT_ACCESS_EXEC | GDT_ACCESS_RW,  GDT_FLAG_GR_PAGE | GDT_FLAG_SZ_32B);
    // Data   Base 0      Limit 32    Access RW
    setGDT(2, 0x00000000, 0xFFFFFFFF, GDT_ACCESS_PRESENT | GDT_ACCESS_RW,                    GDT_FLAG_GR_PAGE | GDT_FLAG_SZ_32B);

    lgdt(&_GDT, sizeof(_GDT));
    SEGMENTS_RELOAD();
}

void setGDT(uint32_t index, uint32_t baseAddr, uint32_t limitAddr, uint8_t accessLvl, uint8_t flags) {
    if (index > 256) return;
    _GDT[index].base_0 = (baseAddr >> 0) & 0xFFFF;
    _GDT[index].base_1 = (baseAddr >> 16) & 0xFF;
    _GDT[index].base_2 = (baseAddr>> 24) & 0xFF;
    _GDT[index].limit_0 = (limitAddr >> 0) & 0xFFFF;
    _GDT[index].limit_1 = (limitAddr >> 16) & 0x0F;
    _GDT[index].access = accessLvl;
    _GDT[index].flags = flags & 0x0F;
}

