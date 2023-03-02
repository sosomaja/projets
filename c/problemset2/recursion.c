#include <stdio.h>
#include <cs50.h>
int fib(int n);
int fact(int n);
int collatz(int n);
int main(void)
{
    int x = get_int("Enter fibonnici term to find its value: ");
    printf("Term [%i] is %i\n", x, fib(x));
    int y = get_int("Enter a number to find its factorial: ");
    printf("Factorial of %i is %i\n", y, fact(y));
    int z = get_int("Enter a number to calculate how many steps it takes to reach 1 using collatz conjucture: ");
    printf("It took %i steps for %i to reach 1 using collatz conjucture\n", collatz(z), z);
    return 0;
}
int fib(int n)
{
    if (n < 2)
        return 0;
    else if (n < 3)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}
int fact(int n)
{
    if (n == 1)
    {
        printf("1\n");
        return 1;
    }
    else
    {
        printf("%ix", n);
        return n * fact(n - 1);
    }
}
int collatz(int n)
{
    if (n == 1)
    {
        printf("1\n");
        return 0;
    }
    else if (n % 2 == 0)
    {
        printf("%i->", n);
        return 1 + collatz(n / 2);
    }
    else
    {
        printf("%i->", n);
        return 1 + collatz((3 * n) + 1);
    }
}