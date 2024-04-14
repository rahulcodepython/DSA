#include <stdio.h>
#include <stdlib.h>

int largest(int *arr, int size)
{
    int largest = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

void display_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[6] = {2, 3, 0, 2, 3, 2};
    int size = 6, index;
    int largest_num = largest(arr, size);
    int *count = (int *)calloc((largest_num + 1), sizeof(int));
    display_array(arr, size);
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }
    display_array(count, largest_num + 1);
    index = 0;
    for (int i = 0; i < (largest_num + 1); i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            arr[index++] = i;
        }
    }
    display_array(arr, size);
}