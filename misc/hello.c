#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("changed this\n");
    char name[] = "Korenx";
    printf("Size: %d\n", sizeof(name));
    printf("Address: %x\n", name);
    printf("Array: %s\n", name);
    char *same_as_name = name;
    printf("Address: %x\n", same_as_name);
    printf("%s\n", same_as_name);
    int age = 20;
    int* age_ptr = &age;
    printf("Size of pointer: %ld", sizeof(age_ptr));
    //int *addr = &ages; 
    //printf("%x", addr);

}