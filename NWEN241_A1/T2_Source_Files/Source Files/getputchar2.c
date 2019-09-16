/*
 * Tutorial for getchar() and putchar() functions
 */

#include <stdio.h>

int main (void)
{
	char c;

	do {
		c = getchar();
		putchar(c);
	} while (c != '\n');
}
