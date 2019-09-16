/*
 * Tutorial for printf() and scanf() functions
 */

#include <stdio.h>

int main (void)
{
    char a, b, c;
    
    printf("Please enter 3 characters: ");
    scanf("%c %c %c", &a, &b, &c);
    
    printf("Characters inputted are: %c %c %c!\n", a, b, c);
}
