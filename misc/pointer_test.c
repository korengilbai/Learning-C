#include <stdio.h>

int main(void)
{

    int ages[6] = {10, 18, 20, 23, 49, 52};
    int *array_pointer = ages;
    for(int i=0; i<8; i++)
    {
        printf("Address: %x     Content: %d\n", array_pointer, *array_pointer);
        array_pointer++;
    }
}


/*
    int age = 20;
    int *my_pointer;
    my_pointer =  &age;

    char name[] = "koren";
    char *string_pointer = name;
    for(int i=0; i< 6; i++, string_pointer++){
        printf("The value of the pointer: %x\n", string_pointer);
        printf("The value in the memory address of the pointer: %d\n", *string_pointer);
    }
    
    //printf("The value of the pointer: %x\n", string_pointer);
    //printf("The value in the memory address of the pointer: %d\n", *string_pointer);
    printf("%s", name);
*/