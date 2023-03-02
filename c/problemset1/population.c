#include <stdio.h>

int main(void)
{
    int sp, ep, sum = 0, count = 0;
    do
    {
        printf("Please make sure that the start size is at least 9 llamas and that the end size is at least equal to start size.\n");
        printf("Enter start size: ");
        scanf("%i", &sp);
        printf("Enter end size: ");
        scanf("%i", &ep);
    } while (sp < 9 || ep < sp);
    while (sum < ep)
    {
        sum = sp + (sp / 3) - (sp / 4);
        count += 1;
        sp = sum;
    }
    printf("It will take %i year(s) to reach at least %i llamas\n", count, ep);
}