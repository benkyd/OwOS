#include <lib/stdint.h>

int memcmp(const void* a, const void* b, uint32_t sze);
void* memcpy(const void* dst, const void* src, uint32_t sze);
void* memmove(void* dst, const void* src, uint32_t sze);
void* memset(void* ptr, int val, uint32_t sze);
