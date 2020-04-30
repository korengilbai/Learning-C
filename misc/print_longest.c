#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 64

int get_length(char str[]);

int main(void)
{
    int longest_len = 0;
    char longest_line[MAX_LENGTH]; 
    char line[MAX_LENGTH];
    char* line_ptr = line;

    do
    {
        printf("Enter a sentence...\n");
        fgets(line, MAX_LENGTH, stdin);
        int current_len = get_length(line_ptr);

        if(current_len > longest_len)
        {
            longest_len = current_len;
            strcpy(longest_line, line); 
        }

    } while (strcmp(line, "stop\n") != 0);
    
    printf("---------------------------\n\nLongest line: %sLength: %i", longest_line, longest_len);
}

int get_length(char* ptr)
{
    int len = 0;
    while(*ptr != '\n')
    {
        len++;
        ptr++;
    }
    return len; 
    /*
    int length = 0;
    for(int i = 0; i < MAX_LENGTH; ++i )
    {
        if(*ptr  == '\n') // end of character array - \0
        {
            break;
        } 
        else
        {
            length += 1;
            ptr++;
        }
    }
    return length;
    */
}
