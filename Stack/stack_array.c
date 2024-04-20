#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

void print_stack(struct stack *s);
void push(struct stack *s);
void pop(struct stack *s);
bool isEmpty(struct stack *s);
bool isFull(struct stack *s);
void peek(struct stack *s);

int main()
{
    int choice;
    bool controller = true;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    while (controller)
    {
        printf("Enter 1 for printing a stack. \n");
        printf("Enter 2 for pushing an element in the stack. \n");
        printf("Enter 3 for popping an element from the stack. \n");
        printf("Enter 4 for checking the stack is empty or not. \n");
        printf("Enter 5 for checking the stack is full or not. \n");
        printf("Enter 6 for peek at a position of the array. \n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            print_stack(s);
            break;
        case 2:
            push(s);
            break;
        case 3:
            pop(s);
            break;
        case 4:
            isEmpty(s) ? printf("The stack is empty. \n") : printf("The stack is not empty \n");
            break;
        case 5:
            isFull(s) ? printf("The stack is full. \n") : printf("The stack is not full. \n");
            break;
        case 6:
            peek(s);
            break;
        default:
            printf("The program is terminated. \n");
            controller = false;
            break;
        }
    }
    free(s);
    return 0;
}

void print_stack(struct stack *s)
{
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d \t", s->arr[i]);
    }
    printf("\n");
}

void push(struct stack *s)
{
    int val;
    if (isFull(s))
    {
        printf("There is no space left. \n");
    }
    else
    {
        printf("Enter a value: ");
        scanf("\t%d", &val);
        if (val < 0)
        {
            printf("You can not add negetive numbers. \n");
        }
        else
        {
            s->arr[++s->top] = val;
        }
    }
}

void pop(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("There is no element to pop. \n");
    }
    else
    {
        --s->top;
    }
}

bool isEmpty(struct stack *s)
{
    if (s->top < 0)
    {
        return true;
    }
    return false;
}
bool isFull(struct stack *s)
{
    if (s->top == (s->size - 1))
    {
        return true;
    }
    return false;
}

void peek(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("The stack is empty. \n");
    }
    else
    {
        printf("%d \n", s->arr[s->top]);
    }
}