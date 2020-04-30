#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    printf("Enter a number to find the sum of its digits...\n");
    int number;
    scanf("%i", &number);
    int sum = 0;
    while(true)
    {
        sum += number % 10;  // add right most digit to sum
        number = number / 10;      // remove right most digit
        if(number == 0)
            break;
    }
    printf("Sum of the digits: %i", sum);
}