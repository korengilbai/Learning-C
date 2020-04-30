#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 16

void reverse(char word[]);

int main(void)
{
    printf("Enter a string to get it reversed...\n");
    char word[MAX]; 
    scanf("%s", word);
    reverse(word);
}

void reverse(char word[])
{
    for(int i = 0; i < strlen(word) / 2; i++)
    {
        char temp = word[i];
        word[i] = word[strlen(word) - i - 1];
        word[strlen(word) - i - 1] = temp;
    }
    
    printf("%s", word);
}