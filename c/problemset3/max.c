#include <stdio.h>
#include <string.h>
#include <cs50.h>
int max(int arr[], int x);
int main(void)
{
    int n = get_int("Enter number of elements: ");
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = get_int("Element(%i) value: ", i);
    }
    printf("Max value is %i\n", max(a, n));
}
int max(int arr[], int x)
{
    int maxi = -1000000;
    for (int i = 0; i < x; i++)
    {
        if (maxi < arr[i])
        {
            maxi = arr[i];
        }
    }
    return maxi;
}