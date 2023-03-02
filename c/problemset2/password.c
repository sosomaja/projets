#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>
void check(string str);
int main(void)
{
    string s = get_string("Enter a strong password, it should contain at least a symbol,uppercase letter,lowercase letter and a digit: ");
    check(s);
}
void check(string str)
{
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        if (islower(str[i]))
        {
            c1 = 1;
        }
        else if (isupper(str[i]))
        {
            c2 = 1;
        }
        else if (isdigit(str[i]))
        {
            c3 = 1;
        }
        else if (ispunct(str[i]))
        {
            c4 = 1;
        }
    }
    if (c1 == 1 && c2 == 1 && c3 == 1 && c4 == 1)
    {
        printf("Your password is strong!\n");
    }
    else
    {
        printf("Your password is weak, try again!\n");
    }
}