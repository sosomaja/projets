#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
int main(void)
{
    int n = get_int("How many weeks did you take cs50: ");
    int hours[n];
    float sum = 0, avg = 0;
    for (int i = 0; i < n; i++)
    {
        hours[i] = get_int("Week %i HW hours: ", i);
        sum += hours[i];
    }
    char output;
    do
    {
        output = get_char("Enter A for average hours or T for total hours: ");
        output = toupper(output);
    } while (output != 'A' && output != 'T');
    avg = sum / n;
    if (output == 'A')
    {
        printf("Average is %0.1f hours per week\n", avg);
    }
    else
    {
        printf("Total is %0.1f hours across %i week(s)\n", sum, n);
    }
}