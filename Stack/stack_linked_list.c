#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct list_node
{
    int val;
    struct list_node *next;
};

struct stack
{
    struct list_node *top;
    struct list_node *head;
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
    s->top = NULL;
    s->head = NULL;
    while (controller)
    {
        printf("Enter 1 for printing a stack. \n");
        printf("Enter 2 for pushing an element in the stack. \n");
        printf("Enter 3 for popping an element from the stack. \n");
        printf("Enter 4 for checking the stack is empty or not. \n");
        printf("Enter 5 for checking the stack is full or not. \n");
        printf("Enter 6 for peek at a position of the array. \n");
        printf("Enter your choice: ");
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
    struct list_node *current = s->head;
    if (s->head == NULL)
    {
        printf("The stack is empty. \n");
    }
    else
    {
        while (current != NULL)
        {
            printf("%d \t", current->val);
            current = current->next;
        }
        printf("\n");
    }
}

void push(struct stack *s)
{
    int val;
    struct list_node *node = (struct list_node *)malloc(sizeof(struct list_node));
    printf("Enter a value: ");
    scanf("%d", &val);
    if (val < 0)
    {
        free(node);
        printf("You can not add negative numbers. \n");
    }
    else
    {
        node->val = val;
        node->next = s->head;
        s->head = node;
        s->top = node;
    }
}

void pop(struct stack *s)
{
    struct list_node *node;
    if (isEmpty(s))
    {
        printf("There is no element to pop. \n");
    }
    else
    {
        node = s->head;
        s->top = s->head->next;
        s->head = s->head->next;
        free(node);
    }
}

bool isEmpty(struct stack *s)
{
    if (s->top == NULL)
    {
        return true;
    }
    return false;
}

bool isFull(struct stack *s)
{
    struct list_node *node = (struct list_node *)malloc(sizeof(struct list_node));
    if (node == NULL)
    {
        free(node);
        return true;
    }
    free(node);
    return false;
}

void peek(struct stack *s)
{
    if (s->head != NULL)
    {
        printf("%d \n", s->head->val);
    }
    else
    {
        printf("There is not any value at this index.");
    }
}