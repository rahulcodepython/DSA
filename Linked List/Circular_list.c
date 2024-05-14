#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct listNode
{
    int val;
    struct listNode *next;
};

struct listNode *create_node(struct listNode *head);
void print_node(struct listNode *head);
// struct listNode *insert_value(struct listNode *head);
// struct listNode *delete_node(struct listNode *head);

int main()
{
    struct listNode *head = NULL;
    int choice;
    bool controller = true;
    while (controller)
    {
        printf("Enter 1 for create a linked list: \n");
        printf("Enter 2 for print a linked list: \n");
        printf("Enter 3 for insert a value in linked list: \n");
        printf("Enter 4 for delete a value from the linked list: \n");
        printf("Enter any other number to terminate the program.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Create a circular linked list.\n");
            head = create_node(head);
            break;
        case 2:
            print_node(head);
            break;
        // case 3:
        //     head = insert_value(head);
        //     break;
        // case 4:
        //     head = delete_node(head);
        //     break;
        default:
            printf("You have terminated the program.\n");
            controller = false;
            break;
        }
    }
    return 0;
}

void print_node(struct listNode *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct listNode *current = head;
    printf("Print all values of the circular linked list: \n");
    do
    {
        printf("%d\t", current->val);
        current = current->next;
    } while (current != head);
    printf("\n");
}
