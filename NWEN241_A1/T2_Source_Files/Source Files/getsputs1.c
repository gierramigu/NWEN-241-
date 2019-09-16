/*
 * Tutorial for gets() and puts() functions
 *
 * Note: gets() is deprecated because it is dangerous
 */

#include <stdio.h>

int main (void)
{
  char str[16];

	gets(str);
	puts(str);
}
