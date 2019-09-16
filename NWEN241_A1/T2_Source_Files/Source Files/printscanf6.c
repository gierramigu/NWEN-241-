/*
 * Tutorial for printf() and scanf() functions
 */

#include <stdio.h>

int main (void)
{
    unsigned int a;
    
    printf("Please enter a number: ");
    scanf("%u", &a);
    
    printf("In decimal           : %u\n", a);
    printf("In decimal (6 digits): %6u\n", a);
    printf("In decimal (6 digits): %06u\n", a);
    printf("In hex (small)       : %x\n", a);
    printf("In hex (caps)        : %X\n", a);
    printf("In octal             : %o\n", a);
}
