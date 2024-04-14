#include <stdio.h>

void bubble_sort(int *arr, int size);
void swap(int *a, int *b);

int main()
{
    int arr[10] = {10, 3, 8, 6, 2, 7, 1, 4, 9, 5};
    int size = 10;
    bubble_sort(arr, size);
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

void bubble_sort(int *arr, int size)
{
    int limit = size - 1;
    while (limit > 0)
    {
        for (int i = 0; i < limit; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
            }
        }
        limit--;
    }
}