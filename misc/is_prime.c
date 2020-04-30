#include<stdio.h>
#include <math.h>

int main()
{
    int min, max;
    printf("Enter min and max numbers to find all primes between them...\n");
    scanf("%d %d", &min, &max);
    for(int i=min; i<= max; i++)
    {
        //int square= sqrt(i);
        //printf("%d", square);
        char found = 'N';
        for(int divisor=2; divisor <= i / 2; ++divisor)
        {
            if(i % divisor == 0)
            {
                found = 'Y';
                break;
            }
        }
        if(found == 'N'){
            printf("Prime number: %d\n", i);
        }
    }
}