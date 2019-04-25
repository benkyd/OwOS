#pragma once 

#include <lib/stdint.h>

bool  memcmp(const void* a, const void* b, uint32_t size);
void* memcpy(void* dst, const void* src, uint32_t size);
void* memmove(void* dst, const void* src, uint32_t size);
void* memset(void* ptr, int val, uint32_t size);
