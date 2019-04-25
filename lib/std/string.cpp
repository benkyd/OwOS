#include "string.h"

uint32_t strlen(char* str) {
	uint32_t len = 0;
	while (str[len])
		len++;
	return len;
}
