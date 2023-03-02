#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
int score(string str);
void winner(int score1, int score2);
int main(void)
{
    string str1 = get_string("Player 1 enter your word: ");
    string str2 = get_string("Player 2 enter your word: ");
    winner(score(str1), score(str2));
    return 0;
}
int score(string str)
{
    int num[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int sum = 0;
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        str[i] = tolower(str[i]);
        for (int j = 0; j < 26; j++)
        {
            if (str[i] == alpha[j])
            {
                sum += num[j];
            }
        }
    }
    return sum;
}
void winner(int score1, int score2)
{
    if (score1 > score2)
    {
        printf("With a score of %i against %i, Player 1 wins!!\n", score1, score2);
    }
    else if (score2 > score1)
    {
        printf("With a score of %i against %i, Player 2 wins!!\n", score2, score1);
    }
    else
    {
        printf("With a score of %i against %i, It's a tie!!\n", score1, score2);
    }
}
