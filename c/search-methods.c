#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>
void binary_search(int n, int arr[], int size);
void linear_search(int n, int arr[], int size);
int main(void)
{
    int x = get_int("Enter number to find: ");
    int y = 15;
    int nums[] = {9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
    binary_search(x, nums, y);
    linear_search(x, nums, y);
}
void binary_search(int n, int arr[], int size)
{
    int x = 0, y = size - 1;
    printf("binary search...\n");
    while (true)
    {
        int z = (x + y) / 2;
        // printf("x is %i y is %i z is %i arr[z] is %i\n", x, y, z, arr[z]);
        if (n == arr[z])
        {
            printf("Found at index %i\n", z);
            break;
        }
        else if (n > arr[z])
        {
            x = z + 1;
        }
        else if (n < arr[z])
        {
            y = z - 1;
        }
        if (x > y)
        {
            printf("not found\n");
            break;
        }
    }
}
void linear_search(int n, int nums[], int size)
{
    int flag = 0;
    printf("linear search...\n");
    for (int i = 0; i < size; i++)
    {
        if (nums[i] == n)
        {
            printf("Found at index %i\n", i);
            flag++;
            break;
        }
    }
    if (flag == 0)
    {
        printf("not found\n");
    }
}
