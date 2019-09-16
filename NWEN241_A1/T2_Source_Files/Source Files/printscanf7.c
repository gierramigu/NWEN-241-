/*
 * Tutorial for printf() and scanf() functions
 */

#include <stdio.h>

int main (void)
{
    float a;
    
    printf("Please enter a floating point number: ");
    scanf("%f", &a);
    
    printf("Default                : %f\n", a);
    printf("Up to 3 decimal places : %0.3f\n", a);
}
