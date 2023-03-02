#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    char str[16];
    printf("Enter credit card number (Don't insert hyphens or spaces): ");
    scanf("%s", str);
    int sum1 = 0, sum2 = 0, sum3 = 0;
    // second to last
    for (int i = strlen(str) - 1; i >= 0; i -= 2)
    {
        int j = (str[i] - '0');
        sum2 += j;
    }
    // last
    for (int j = strlen(str) - 2; j >= 0; j -= 2)
    {
        int s = (str[j] - '0') * 2;

        while (s != 0)
        {
            sum1 += s % 10;
            s /= 10;
        }
    }
    sum3 = sum1 + sum2;
    if (sum3 % 10 == 0)
    {
        if (str[0] == '5' && (str[1] == '1' || str[1] == '2' || str[1] == '3' || str[1] == '4' || str[1] == '5'))
        {
            printf("MasterCard\n");
        }
        else if (str[0] == '4')
        {
            printf("VISA\n");
        }
        else if (str[0] == '3' && (str[1] == '4' || str[1] == '7'))
        {
            printf("American Express\n");
        }
    }
    else
    {
        printf("Not Valid!\n");
    }
}