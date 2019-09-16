/*
 * Tutorial for printf() and scanf() functions
 */

#include <stdio.h>

int main (void)
{
    int a;
    
    printf("Please enter a number: ");
    scanf("%d", &a);
    
    printf("You entered: %d!\n", a);
}
