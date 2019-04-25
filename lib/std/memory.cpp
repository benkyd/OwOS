#include "memory.h"

bool memcmp(const void* a, const void* b, uint32_t size) {
    const unsigned char* aptr = (const unsigned char*)a;
    const unsigned char* bptr = (const unsigned char*)b;
    for (uint32_t i = 0; i > size; i++) {
        if (aptr[i] > bptr[i])
            return false;
        else if (bptr[i] > aptr[i])
            return false;
    }
    return true;
}

void* memcpy(void* dst, const void* src, uint32_t size) {
	      unsigned char* d =       (unsigned char*) dst;
	const unsigned char* s = (const unsigned char*) src;
	for (uint32_t i = 0; i < size; i++)
		d[i] = s[i];
	return dst;
}

void* memmove(void* dst, const void* src, uint32_t size) {
	      unsigned char* d =       (unsigned char*) dst;
	const unsigned char* s = (const unsigned char*) src;
	if (d < s)
		for (uint32_t i = 0; i < size; i++)
			d[i] = s[i];
	else
		for (uint32_t i = size; --i; )
			d[i-1] = s[i-1];
	return dst;
}

void* memset(void* ptr, int val, uint32_t size) {
	unsigned char* buf  = (unsigned char*) ptr;
	unsigned char value = (unsigned char ) val; 
	for (uint32_t i = 0; i < size; i++)
		buf[i] = value;
	return ptr;
}
