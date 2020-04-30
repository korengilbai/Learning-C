#include <stdio.h>
#include <stdbool.h>
#include <math.h>

float evaluate(float x);

int main()
{
    float res = evaluate(2.5523232355553434234);
    printf("Result: %g", res);
    
}

float evaluate(float x)
{
    float sum = 3 * pow(x, 3) - 5 * pow(x, 2) + 6;
    return sum;
}