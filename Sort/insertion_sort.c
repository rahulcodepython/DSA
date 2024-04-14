#include <stdio.h>

void insertion_sort(int *arr, int size);
void swap(int *a, int *b);

int main()
{
    int arr[10] = {10, 3, 8, 6, 2, 7, 1, 4, 9, 5};
    int size = 10;
    insertion_sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d \n", arr[i]);
    }

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(&arr[j - 1], &arr[j]);
            }
        }
    }
}