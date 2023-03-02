#include <stdio.h>
int main(void)
{
    printf("Enter your name:\n");
    char s[50];
    fgets(s, sizeof(s), stdin);
    printf("Hello ");
    puts(s);
}