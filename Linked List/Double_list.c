#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct listNode
{
    int val;
    struct listNode *next;
    struct listNode *prev;
};

struct listNode *create_node();
void print_node(struct listNode *head);
struct listNode *insert_value(struct listNode *head);
struct listNode *delete_node(struct listNode *head);

int main()
{
    struct listNode *head = NULL;
    int choice, index, val;
    bool controller = true;
    while (controller)
    {
        printf("Enter 1 for create a linked list: \n");
        printf("Enter 2 for print a linked list: \n");
        printf("Enter 3 for insert a value in linked list: \n");
        printf("Enter 4 for delete a value from the linked list: \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Create a linked list.\n");
            head = create_node();
            break;
        case 2:
            print_node(head);
            break;
        case 3:
            head = insert_value(head);
            break;
        case 4:
            head = delete_node(head);
            break;
        default:
            printf("You have terminated the program.");
            controller = false;
            break;
        }
    }
    return 0;
}

struct listNode *create_node()
{
    int val;
    struct listNode *node = (struct listNode *)malloc(sizeof(struct listNode));
    printf("Enter a value to add node: ");
    scanf("%d", &val);
    if (val < 0)
    {
        free(node);
        return NULL;
    }
    node->val = val;
    node->next = NULL;
    node->prev = NULL;

    struct listNode *nextNode = create_node();

    if (nextNode != NULL)
    {
        node->next = nextNode;
        nextNode->prev = node;
    }

    return node;
}

void print_node(struct listNode *head)
{
    struct listNode *current = head;
    printf("Print the all values of the linked list: \n");
    while (current != NULL)
    {
        printf("%d\t", current->val);
        current = current->next;
    }
    printf("\n");
}

struct listNode *insert_value(struct listNode *head)
{
    struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }

    int index, val;
    printf("Insert a value in the linked list.\n");
    printf("Enter the index where you want to add the value and Enter -1 to add value at the end: ");
    scanf("%d", &index);
    printf("Enter the value which you want to add: ");
    scanf("%d", &val);
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (index == 1)
    {
        newNode->next = head;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
    }
    else if (index == -1)
    {
        struct listNode *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    else
    {
        struct listNode *current = head;
        int i = 1;
        while (current != NULL)
        {
            if (i == index - 1)
            {
                break;
            }
            current = current->next;
            i++;
        }
        if (current == NULL)
        {
            printf("Index out of range.\n");
            free(newNode);
            return head;
        }
        newNode->next = current->next;
        if (current->next != NULL)
        {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    return head;
}

struct listNode *delete_node(struct listNode *head)
{
    int index;
    printf("Delete a value from the linked list.\n");
    printf("Enter the index where you want to delete the value: ");
    scanf("%d", &index);

    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    if (index == 1)
    {
        struct listNode *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
    }
    else if (index == -1)
    {
        struct listNode *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        if (current->prev != NULL)
        {
            current->prev->next = NULL;
        }
        free(current);
    }
    else
    {
        struct listNode *current = head;
        int i = 1;
        while (current != NULL)
        {
            if (i == index)
            {
                break;
            }
            current = current->next;
            i++;
        }
        if (current == NULL)
        {
            printf("Index out of range.\n");
            return head;
        }

        if (current->prev != NULL)
        {
            current->prev->next = current->next;
        }
        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }
        free(current);
    }

    return head;
}
