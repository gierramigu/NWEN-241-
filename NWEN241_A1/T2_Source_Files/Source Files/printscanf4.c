/*
 * Tutorial for printf() and scanf() functions
 */

#include <stdio.h>

int main (void)
{
    unsigned int a;
    
    printf("Please enter a number: ");
    scanf("%u", &a);
    
    printf("You entered: %u!\n", a);
}
