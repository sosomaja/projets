#include <stdio.h>
#include <cs50.h>
void prime(int min, int max);
int main(void)
{
    int min, max;
    printf("Enter min: ");
    scanf("%i", &min);
    printf("Enter max: ");
    scanf("%i", &max);
    prime(min, max);
}

void prime(int min, int max)
{
    for (int i = min; i <= max; i++)
    {
        int flag = 0;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag++;
                break;
            }
        }
        if (flag == 0)
        {
            printf("%i\n", i);
        }
    }
}