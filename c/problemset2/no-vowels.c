#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>
string replace(string str);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please make sure to write one word to convert to leetcode.\n");
        return 1;
    }
    else
    {
        printf("%s\n", replace(argv[1]));
        return 0;
    }
}
string replace(string str)
{
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        switch (str[i])
        {
        case 'a':
            str[i] = '6';
            break;
        case 'e':
            str[i] = '3';
            break;
        case 'i':
            str[i] = '1';
            break;
        case 'o':
            str[i] = '0';
            break;
        default:
            break;
        }
    }
    return str;
}