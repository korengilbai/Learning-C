#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int assignments;
    printf("Enter the number of assignments thus far...\n");
    scanf("%d", &assignments);
    float *scores = (float*) malloc(400); // dynamically allocate memory for max 100 floats
    float *address_copy = scores;
    printf("%x\n", &scores);
    for(int i=0; i<assignments; i++)
    {
        printf("Enter your score...\n");
        printf("%f\n", *scores);
        scanf("%f", &scores);
        printf("%f\n", *scores);
        scores++;
    }
    printf("First score: %f", *address_copy);

}
