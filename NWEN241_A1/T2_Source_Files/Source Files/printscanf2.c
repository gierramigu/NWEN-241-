/*
 * Tutorial for printf() and scanf() functions
 */

#include <stdio.h>

int main (void)
{
    char name1[100], name2[100];
    
    printf("Please enter your name: ");
    scanf("%s%s", name1, name2);
    
    printf("Hello %s %s!\n", name1, name2);
}
