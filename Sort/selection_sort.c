#include <stdio.h>

void selection_sort(int *arr, int size);
void swap(int *a, int *b);
int minimum_num(int *arr, int size, int start);

int main()
{
    int arr[10] = {10, 3, 8, 6, 2, 7, 1, 4, 9, 5};
    int size = 10;
    selection_sort(arr, size);
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

int minimum_num(int *arr, int size, int start)
{
    int min = start;
    for (int i = start; i < size; i++)
    {
        if (arr[i] < arr[min])
        {
            min = i;
        }
    }
    return min;
}

void selection_sort(int *arr, int size)
{
    int min;
    for (int i = 0; i < size; i++)
    {
        min = minimum_num(arr, size, i);
        if (arr[i] > arr[min])
        {
            swap(&arr[i], &arr[min]);
        }
    }
}