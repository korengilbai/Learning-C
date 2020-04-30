#include <stdio.h>

void print_questions(void);

int main(void)
{
    char name;
    name = scanf("%[^\n]%*c", name);
    printf("Hello, %s", name);
}

void print_questions(void)
{
    int n = 3;
    /*
    do
    {
        printf("?");
    } while (/* );
    */
}