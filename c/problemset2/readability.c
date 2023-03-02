#import <stdio.h>
#import <cs50.h>
#import <string.h>
#import <ctype.h>
#import <math.h>
int inde(char *text);
int main(void)
{
    char *x = get_string("Text: ");
    int t = inde(x);
    if (t < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (t > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n",t);
    }
    return 0;
}
int inde(char *text)
{
    int word = 1, sentence = 0, letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == '.')
        {
            sentence++;
        }
        else if (isspace(text[i]))
        {
            word++;
        }
    }
    printf("letters: %i words: %i sentences: %i\n", letters, word, sentence);
    float avglet = letters / (word - 0.0) * 100, avgsent = sentence / (word - 0.0) * 100;

    int idx = round(0.0588 * avglet - 0.296 * avgsent - 15.8);
    return idx;
}