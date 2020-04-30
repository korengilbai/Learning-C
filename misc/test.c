#include <stdio.h>

int main(void)
{
	int age = 20;
	int *ptr = &age;
	printf("Value of var: %i\nValue of ptr: %p", age, ptr);
	printf("Address of var: %x\nValue of ptr: %x", &age, ptr);
	printf("Reference ptr: %i", *ptr);
}

