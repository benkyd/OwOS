#include "stdlib.h"

#include "string.h"

void swap(int* x, int* y) {
	int* t = x;
	x = y;
	y = t;
}

void reverse(char *s) {
   int length, c;
   char *begin, *end, temp;
 
   length = strlen(s);
   begin  = s;
   end    = s;
 
   for (c = 0; c < length - 1; c++)
      end++;
 
   for (c = 0; c < length/2; c++) {
      temp   = *end;
      *end   = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}


char* itoa(int n, char s[]) {
    int i = 0; 
    bool isNegative = false; 
  
    if (n == 0) { 
        s[i++] = '0'; 
        s[i] = '\0'; 
        return s;
    } 
  
	if (n < 0) { 
        isNegative = true; 
        n = -n; 
    } 
    
    while (n != 0) { 
        s[i++] = n % 10 + '0'; 
        n /= 10; 
    } 
  
    if (isNegative) 
        s[i++] = '-'; 
  
    s[i] = '\0';
	
	reverse(s);
    return s;
}
