#include "gdt.h"

#include <kernel/kernio.h>
#include <lib/std/memory.h>

struct SegmentDescriptor_t {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity0:4;
    uint8_t granularity1:4;
    uint8_t base_high;
} __attribute__((packed));

struct GDT_t {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

SegmentDescriptor_t _GDT[5];
GDT_t               _GDTptr;

void lgdt(void* base, uint16_t size) {
    struct {
        uint16_t length;
        void*    base;
    } __attribute__((packed)) GDTR = { size, base };
 
    asm ( "lgdt %0" : : "m"(GDTR) );}

void initGDT() {
    #define BochsBreak() outw(0x8A00,0x8A00); outw(0x8A00,0x08AE0);
    _GDTptr.limit = (sizeof(SegmentDescriptor_t) * 5) - 1;
    _GDTptr.base  = (uint32_t)&_GDT;

    // Null segment
    setGDTGate(0, 0, 0, 0, 0);
    // Code   Base 0      limit 32    Access EXEC + RW
    setGDTGate(1, 0x00000000, 0xFFFFFFFF, GDT_ACCESS_PRESENT | GDT_ACCESS_EXEC | GDT_ACCESS_RW,  GDT_FLAG_GR_PAGE | GDT_FLAG_SZ_32B);
    // Data   Base 0      Limit 32    Access RW
    setGDTGate(2, 0x00000000, 0xFFFFFFFF, GDT_ACCESS_PRESENT | GDT_ACCESS_RW,                    GDT_FLAG_GR_PAGE | GDT_FLAG_SZ_32B);

    lgdt(&_GDT, sizeof(_GDT));
    BochsBreak();
    SEGMENTS_RELOAD();
}

void setGDTGate(uint32_t index, uint32_t baseAddr, uint32_t limitAddr, uint8_t accessLvl, uint8_t flags) {
    if (index > 5) return;
    _GDT[index].base_low    = (baseAddr & 0xFFFF);
    _GDT[index].base_middle = (baseAddr >> 16) & 0xFF;
    _GDT[index].base_high   = (baseAddr >> 24) & 0xFF;

    _GDT[index].limit_low   = (limitAddr >> 0) & 0xFFFF;
    _GDT[index].granularity0 = (limitAddr >> 16) & 0x0F;
    
    _GDT[index].granularity1 = flags & 0x0F;
    _GDT[index].access      = accessLvl;
}

