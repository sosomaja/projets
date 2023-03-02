#include <stdio.h>
#include <cs50.h>
#include <string.h>
int convert(string str);
int main(void)
{
    string num = get_string("string: ");
    printf("number: %i\n", convert(num));
}
int convert(string str)
{
    int len = strlen(str);
    if (len < 1)
        return 0;
    else
    {
        int n = str[len - 1] - '0';
        str[len - 1] = '\0';
        return n + 10 * convert(str);
    }
}