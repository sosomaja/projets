#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
void cipher(string plain, int key);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage:./caeser key\n");
        return 1;
    }
    else if (atoi(argv[1]) == 0)
    {
        printf("Usage:./caeser key\n");
        return 1;
    }
    else
    {
        int dec = atoi(argv[1]);
        string text = get_string("plain text:  ");
        cipher(text, dec);
        return 0;
    }
}
void cipher(string plain, int key)
{
    const int n = strlen(plain);
    printf("cipher text: ");
    for (int i = 0; i < n; i++)
    {
        int cout;
        if (isalpha(plain[i]))
        {
            int x;
            if (islower(plain[i]))
            {
                x = 97;
            }
            else
            {
                x = 65;
            }
            cout = (plain[i] - x + key) % 26 + x;
        }
        else
        {
            cout = plain[i];
        }
        printf("%c", cout);
    }
    printf("\n");
}