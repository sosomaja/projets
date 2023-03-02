#include <stdio.h>
#include <cs50.h>
void bubble_sort(int arr[], int size);
void selection_sort(int arr[], int size);
void insertion_sort(int arr[], int size);
void merge_sort(int arr[], int s, int e);
void merge(int arr[], int s, int m, int e);
void print_merge_sort(int arr[], int n);
int main(void)
{
    int n = 6;
    int nums[] = {5, 2, 1, 3, 6, 4};
    int nums2[] = {97, 82, 85, 90, 105, 82, 97, 85, 107};
    int s = sizeof(nums2) / sizeof(nums2[0]);
    int nums3[] = {5, -9, -3, 0, 72, 33};
    int nums4[] = {23, 11, 19, -4, 0, 2};
    selection_sort(nums, n);
    bubble_sort(nums2, s);
    insertion_sort(nums3, n);
    merge_sort(nums4, 0, n - 1);
    // print_merge_sort(nums4, n);
    return 0;
}
void bubble_sort(int arr[], int size)
{
    int temp;
    const int t = size;
    for (int j = 0; j < t; j++)
    {
        int counter = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                counter++;
            }
        }
        if (counter == 0)
        {
            break;
        }
        size -= 1;
    }
    // printf("\nsorted array using bubble sort:    ");
    // for (int i = 0; i < t; i++)
    //     printf("%i ", arr[i]);
    // printf("\n");
}
void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = 999999, temp, ind;
        for (int j = i; j < size; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                ind = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[ind];
        arr[ind] = temp;
    }
    // printf("\nsorted array using selection sort: ");
    // for (int i = 0; i < size; i++)
    //     printf("%i ", arr[i]);
    // printf("\n");
}
void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size - 1; i++)
    {
        int temp;
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        temp = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (j < 0)
            {
                break;
            }
            if (arr[j] > arr[i])
            {
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // printf("\nsorted array using insertion sort: ");
    // for (int i = 0; i < size; i++)
    //     printf("%i ", arr[i]);
    // printf("\n\n");
}
void merge_sort(int arr[], int s, int e)
{
    if (s < e)
    {
        int m = (s + e) / 2;
        merge_sort(arr, s, m);
        merge_sort(arr, m + 1, e);
        merge(arr, s, m, e);
    }
}
void merge(int arr[], int s, int m, int e)
{
    int len1 = m - s + 1;
    int len2 = e - m;
    int a[len1], b[len2];
    for (int i = 0; i < len1; i++)
    {
        a[i] = arr[s + i];
    }
    for (int j = 0; j < len2; j++)
    {
        b[j] = arr[j + 1 + m];
    }
    int i = 0, j = 0, k = s;
    while (i < len1 && j < len2)
    {
        if (a[i] <= b[j])
        {
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = b[j++];
        }
    }
    while (i < len1)
    {
        arr[k++] = a[i++];
    }
    while (j < len2)
    {
        arr[k++] = b[j++];
    }
}
void print_merge_sort(int arr[], int n)
{
    printf("sorted array using merge sort:     ");
    for (int i = 0; i < n; i++)
        printf("%i ", arr[i]);
    printf("\n\n");
}