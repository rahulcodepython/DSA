#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void enter_value(int *arr, int size);
void print_value(int *arr, int size);
int *inset_value(const int *arr, int size, int index, int val);
void delete_value(int *arr, int size, int index);

int main()
{
    int size, *arr, choice, index, val;
    bool controller = true;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    arr = (int *)malloc(size * sizeof(int));
    while (controller)
    {
        printf("Enter 1 for add value in the array.\n");
        printf("Enter 2 for print values of the array.\n");
        printf("Enter 3 for insert a value in the array.\n");
        printf("Enter 4 for delete a value in the array.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter some value in the array.\n");
                enter_value(arr, size);
                break;
            case 2:
                printf("Print the all values of the array:\n");
                print_value(arr, size);
                break;
            case 3:
                printf("Insert a value in the array:\n");
                printf("Enter the index where you want to add the value: ");
                scanf("%d", &index);
                printf("Enter the value which you want to add: ");
                scanf("%d", &val);
                arr = inset_value(arr, size, index, val);
                size++;
                break;
            case 4:
                printf("Delete a value in the array:\n");
                printf("Enter the index where you want to delete the value:");
                scanf("%d", &index);
                delete_value(arr, size, index);
                size--;
                break;
            default:
                printf("The program is terminated.\n");
                controller = false;
                break;
        }
    }
    free(arr);
    return 0;
}

void enter_value(int *arr, int size)
{
    int n;
    for (int i = 0; i < size; ++i)
    {
        printf("Enter a value: ");
        scanf("%d", &n);
        arr[i] = n;
    }
}

void print_value(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}

int *inset_value(const int *arr, int size, int index, int val)
{
    int *new_arr = (int *)malloc((size + 1) * sizeof(int));
    int counter = 0, i = 0;
    while (counter < size + 1)
    {
        if (counter != index)
        {
            new_arr[counter] = arr[i++];
        }
        counter++;
    }
    new_arr[index] = val;
    return new_arr;
}

void delete_value(int *arr, int size, int index)
{
    for (int i = index; i < size; ++i)
    {
        arr[i] = arr[i + 1];
    }
}