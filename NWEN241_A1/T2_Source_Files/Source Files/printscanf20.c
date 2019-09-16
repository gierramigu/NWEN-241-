/*
 * Tutorial for printf() and scanf() functions
 */

#include <stdio.h>

int main (void)
{
    char name[100];

    printf("Please enter your name: ");
    scanf("%[^\n]%*c", name);

    printf("Hello %s!\n", name);
}
