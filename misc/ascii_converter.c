#include <stdio.h>

int main()
{
    char c = 'x'; 
    while(c != ' ')
    {
        printf("Enter a character to find its ASCII value...\n\n");
        scanf("%c", &c);
        printf("ASCII value: %d\n\n", c);
    }
}