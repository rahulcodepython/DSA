#include <stdio.h>

void print_array(int *arr, int size);
void merge_sort(int *arr, int start, int end);
void merge(int *arr, int start, int mid, int end);

int main()
{
    int arr[10] = {5, 2, 9, 1, 7, 10, 4, 8, 3, 6};
    int size = 10;
    print_array(arr, size);
    merge_sort(arr, 0, size - 1);
    print_array(arr, size);
    return 0;
}

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void merge_sort(int *arr, int start, int end)
{
    int mid = (start + end) / 2;
    if (start < end)
    {
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void merge(int *arr, int start, int mid, int end)
{
    int i = start, j = mid + 1, k, index = start;
    int temp[end];
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[index++] = arr[i++];
        }
        else
        {
            temp[index++] = arr[j++];
        }
    }
    if (i > mid)
    {
        while (j <= mid)
        {
            temp[index++] = arr[j++];
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[index++] = arr[i++];
        }
    }
    for (int k = start; k < index; k++)
    {
        arr[k] = temp[k];
    }
}