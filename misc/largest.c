#include <stdio.h>

int main()
{
    printf("Enter 3 numbers to find the largest one...\n");
    double num1, num2, num3; 
    scanf("%lf %lf %lf", &num1, &num2, &num3);
    double b = (num1 > num2) ? num1: num2;
    double max = (num3 > b) ? num3: b;
    printf("Largest number: %.2lf", max);

}
