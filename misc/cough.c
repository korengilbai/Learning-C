#include <stdio.h>

void cough(int times);

int main(void){
    cough(5);
    float x = 12e-2;
    printf("%.2f", x);
    printf("The memory address of x is: %x", &x);
}

void cough(int times)
{
    for(int i = 0; i<times; i++)
    {
        printf("cough \n");
    }
}
