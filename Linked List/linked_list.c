#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct listNode
{
    int val;
    struct listNode *next;
};

struct listNode *create_node();
void print_node(struct listNode *head);
struct listNode *inset_value(struct listNode *head);
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
                head = inset_value(head);
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
    else
    {
        node->val = val;
        node->next = create_node();
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

struct listNode *inset_value(struct listNode *head)
{
    struct listNode *newNode = (struct listNode *)malloc(sizeof(struct listNode));
    struct listNode *current;
    int index, val;
    int i = 1;
    printf("Insert a value in the linked list.\n");
    printf("Enter the index where you want to add the value: ");
    scanf("%d", &index);
    printf("Enter the value which you want to add: ");
    scanf("%d", &val);
    newNode->val = val;

    if (index == 1)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        current = head;
        while (current != NULL)
        {
            if (i == index - 1)
            {
                newNode->next = current->next;
                current->next = newNode;
                break;
            }
            current = current->next;
            i++;
        }
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
    struct listNode *current, *temp;
    int i = 1;
    if (index == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    else
    {
        current = head;
        while (current != NULL)
        {
            if (i == index - 1)
            {
                temp = current->next;
                if (temp == NULL) {
                    printf("Index out of range.\n");
                    return head;
                }
                current->next = temp->next;
                free(temp);
                break;
            }
            current = current->next;
            i++;
        }
    }
    return head;
}
