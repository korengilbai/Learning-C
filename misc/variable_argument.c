#include <stdio.h>
#include <stdarg.h>
 
double average(double first, ...);

int main(void)
{
    double avg = average(100, 200, 300);
    printf("Average: %.2f", avg);

}

double average(double first, ...)
{
    va_list nums;
    va_start(nums, first);
    double sum = first;
    int count = 1;

    while(1 == 1){
        double next_arg = va_arg(nums, double);
        if((int)next_arg == 0)
            break;
        else
        {
            sum += next_arg;
            count++;
        }
    }


    va_end(nums);
    double res = sum / count;
    return res;
}