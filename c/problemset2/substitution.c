#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void cipher(string plain, string key);
int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        string text = get_string("plain text:  ");
        cipher(text, argv[1]);
        return 0;
    }
}
void cipher(string plain, string key)
{
    char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        char cha = plain[i];
        int flag = 0;
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                flag++;
                cha = tolower(plain[i]);
            }
            for (int j = 0; j < 26; j++)
            {
                if (cha == alpha[j])
                {
                    if (flag == 1)
                    {
                        cha = toupper(key[j]);
                    }
                    else
                    {
                        cha = tolower(key[j]);
                    }
                    break;
                }
            }
        }
        printf("%c", cha);
    }
    printf("\n");
}
