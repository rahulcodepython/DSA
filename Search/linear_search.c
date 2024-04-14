#include <stdio.h>

int main()
{
    int arr[10] = {10, 3, 5, 7, 9, 2, 4, 6, 8, 1};
    int size = 10;
    int key;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            printf("Element found at position %d\n", i + 1);
            return 0;
        }
    }
    printf("Element not found\n");
    return 0;
}