/*
 * Tutorial for getchar() and putchar() functions
 */

#include <stdio.h>

int main (void)
{
	char c1, c2;

	c1 = getchar();
    c2 = getchar();

    if(c1 == 'A' && c2 == '\n') {
        putchar(c1);
        putchar(c2);
    }

    
}
