#include <stdio.h>
#include <stdlib.h>

void alter(int age);

int main(int argc, char *argv[])
{
	
	if(32 == 0x20)
		printf("true\n");
	
	printf("argc = %i, argv[0] = %s\n", argc, argv[0]);

	int age = 20;
	int *age_ptr = &age;
	*age_ptr = 21;
	printf("Value of var age: %d\n", age);

	for(int i = 0; i < 5; i++)
	{
		if(i % 2 == 0)
		{
			continue;
		}
		for(int j = 0; j < 2; j++)
		{
			printf("\ngot here j: %i\n", j);
		}
		printf("got here: %i\n", i);
	}
	
	/*
	char * ptr = "Testing char poitners";
	printf("Address: %p\n", ptr);
	while(*ptr != '\0')
	{
		printf("Address: %x\nFirst char: %c\n\n", ptr, *ptr);
		ptr++;	
	}
	*/
}

