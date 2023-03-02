#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void red(void);
void green(void);
void yellow(void);
void reset(void);
void check(string str, string ans, int size);
int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./wordle wordsize");
        return 1;
    }
    else if (atoi(argv[1]) < 5 || atoi(argv[1]) > 8)
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8");
        return 1;
    }
    else
    {
        int wordsize = atoi(argv[1]);
        string answer, guess;
        switch (wordsize)
        {
        case 5:
            answer = "heart";
            break;
        case 6:
            answer = "wordle";
            break;
        case 7:
            answer = "planets";
            break;
        default:
            answer = "hospital";
            break;
        }
        int tries = 6;
        printf("This is WORDLE50\nYou have 6 tries to guess the %i-letter word I'm thinking of\n\n", wordsize);
        while (tries > 0)
        {
            do
            {
                guess = get_string("Enter guess of %i letters, (%i) tries left: ", wordsize, tries);
            } while (strlen(guess) != wordsize);
            check(guess, answer, wordsize);
            if (strcmp(guess, answer) == 0)
            {
                printf("Congrats!!, you guessed it in %i tries!\n", 7 - tries);
                return 0;
            }
            tries--;
        }
        printf("game over, you ran out of tries, the correct word was ");
        green();
        printf("%s\n", answer);
        return 0;
    }
}
void red(void)
{
    printf("\033[1;31m");
}
void green(void)
{
    printf("\033[1;32m");
}
void yellow(void)
{
    printf("\033[1;33m");
}
void reset(void)
{
    printf("\033[0m");
}
void check(string str, string ans, int size)
{
    for (int i = 0; i < size; i++)
    {
        int close = 0;
        str[i] = tolower(str[i]);
        if (str[i] == ans[i])
        {
            green();
            printf("%c", str[i]);
        }
        else
        {
            for (int j = 0; j < size; j++)
            {
                if (str[i] == ans[j])
                {
                    yellow();
                    printf("%c", str[i]);
                    close++;
                    break;
                }
            }
            if (close == 0)
            {
                red();
                printf("%c", str[i]);
            }
        }
    }
    reset();
    printf("\n");
}
