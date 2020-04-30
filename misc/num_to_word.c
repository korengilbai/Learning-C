#include <stdio.h>
#include <math.h>

int main(void){
    printf("Enter a number...\n");
    int num;
    scanf("%i", &num);
    int len = ((int) log10(num)); // length - 1
    do
    {
        
        int left_most = ((int) (num / (pow(10, len))))  % 10; 
        len -= 1;
        switch (left_most)
        {
        case 1:
            printf("one ");
            break;
        case 2:
            printf("two ");
            break;
        case 3:
            printf("three ");
            break;
        case 4:
            printf("four ");
            break;
        case 5:
            printf("five ");
            break;
        case 6:
            printf("six ");
            break;
        case 7:
            printf("seven ");
            break;
        case 8:
            printf("eight ");
            break;
        case 9:
            printf("nine ");
            break;
        default:
            break;
        }
    } while (len >= 0);

}