#include <stdio.h>

int get_factorial(int num);

int main(void)
{
    printf("Number:\t\tFactorial:\n");
    printf("-------\t\t----------\n");
    
    for(int num=1; num <= 10; num++)
    {
        long int fact = get_factorial(num);
        printf("%3i\t\t%li\n", num, fact);
    }
}

int get_factorial(int num)
{
    if(num == 1)
    {
        return num;
    }
    else
    {
        return (num * get_factorial(num -1));
    }
}