#include <stdio.h>
int main(void)
{
    int s;
    do
    {
        printf("Enter positive int\n");
        scanf("%i", &s);
    } while (s > 8 || s < 1);
    for (int i = 1; i <= s; i++)
    {
        for (int k = 0; k < s - i; k++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
