#include "stdlib.h"

#include "string.h"

void swap(int* x, int* y) {
	int* t = x;
	x = y;
	y = t;
}

void reverse(char s[]) {
	int i;
	int j = strlen(s) - 1;
	char c;

	for (i = 0; i < j; i++) {
		j--;
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(int i, char[] s) {
	int i, sign;

	if ((sign = n) < 0)  /* record sign */
		n = -n;          /* make n positive */
	i = 0;
	do {       /* generate digits in reverse order */
		s[i++] = n % 10 + '0';   /* get next digit */
	} while ((n /= 10) > 0);     /* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
