#include <stdio.h>

void binary_search(int *arr, int size, int key, int start, int end);

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int key, start, end;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    binary_search(arr, size, key, 0, size - 1);
}

void binary_search(int *arr, int size, int key, int start, int end)
{
    int mid = (start + end) / 2;

    if (mid == start || mid == end)
    {
        printf("Element not found");
    }
    else if (arr[mid] == key)
    {
        printf("Element found at index %d", mid + 1);
    }
    else if (arr[mid] < key)
    {
        binary_search(arr, size, key, mid + 1, end);
    }
    else
    {
        binary_search(arr, size, key, start, mid - 1);
    }
}