#include <stdio.h>

void quick_sort(int *arr, int start, int end);
int partition(int *arr, int start, int end);
void swap(int *a, int *b);
void print_array(int *arr);

int main()
{
    int arr[10] = {5, 2, 9, 1, 7, 10, 4, 8, 3, 6};
    int size = 10;
    print_array(arr);
    quick_sort(arr, 0, size - 1);
    print_array(arr);
    return 0;
}

void quick_sort(int *arr, int start, int end)
{
    int pivot;

    if (start < end)
    {
        pivot = partition(arr, start, end);
        quick_sort(arr, start, pivot - 1);
        quick_sort(arr, pivot + 1, end);
    }
}

int partition(int *arr, int start, int end)
{
    int pivot = arr[start];
    int i = start + 1, j = end;

    do
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (j > i)
        {
            swap(&arr[i], &arr[j]);
        }
        else{
            swap(&arr[start], &arr[j]);
        }
    } while (j > i);

    return j;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int *arr)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}