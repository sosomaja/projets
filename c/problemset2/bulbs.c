#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
void bulbs(string code);
int main(void)
{
    string str = get_string("Message: ");
    bulbs(str);
    return 0;
}
void bulbs(string code)
{
    for (int i = 0, n = strlen(code); i < n; i++)
    {
        int arr[8];
        int n = code[i];
        int x;
        for (int j = 7; j >= 0; j--)
        {
            if (n % 2 == 0)
            {
                arr[j] = 0;
            }
            else if (n % 2 != 0)
            {
                arr[j] = 1;
            }
            n /= 2;
        }
        for (int k = 0; k < 8; k++)
        {
            if (arr[k] == 0)
            {
                printf("⚫ ");
            }
            else
            {
                printf("🟡");
            }
        }
        printf("\n");
    }
}