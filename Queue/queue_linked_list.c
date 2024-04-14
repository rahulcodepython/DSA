#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    int front;
    int rear;
    struct node *head;
};

struct node *create_queue(struct queue *q);
void display_queue(struct queue *q);
bool isFull(struct queue *q);
bool isEmpty(struct queue *q);
void enqueue(struct queue *q);
void dequeue(struct queue *q);

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    int choice;
    bool controller = true;
    q->front = -1;
    q->rear = -1;
    q->head = NULL;
    while (controller)
    {
        printf("1. Create a queue\n");
        printf("2. Display the queue\n");
        printf("3. Check if the queue is full\n");
        printf("4. Check if the queue is empty\n");
        printf("5. Enqueue\n");
        printf("6. Dequeue\n");
        printf("7. Peek\n");
        printf("8. Size of the queue\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            q->head = create_queue(q);
            q->front++;
            break;
        case 2:
            display_queue(q);
            break;
        case 3:
            if (isFull(q))
            {
                printf("The queue is full.\n");
            }
            else
            {
                printf("The queue is not full.\n");
            }
            break;
        case 4:
            if (isEmpty(q))
            {
                printf("The queue is empty.\n");
            }
            else
            {
                printf("The queue is not empty.\n");
            }
            break;
        case 5:
            enqueue(q);
            break;
        case 6:
            dequeue(q);
            break;
        case 7:
            printf("Peek is %d\n", q->head->data);
            break;
        case 8:
            printf("The size of the queue is %d\n", q->rear + 1);
            break;
        default:
            printf("The program is terminated.\n");
            controller = false;
            break;
        }
    }
    free(q->head);
    free(q);
    return 0;
}

struct node *create_queue(struct queue *q)
{
    int data;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &data);
    if (data < 0)
    {
        free(new_node);
        return NULL;
    }
    else
    {
        new_node->data = data;
        q->rear++;
        new_node->next = create_queue(q);
    }
    return new_node;
}

bool isFull(struct queue *q)
{
    return false;
}

bool isEmpty(struct queue *q)
{
    return q->head == NULL;
}

void display_queue(struct queue *q)
{
    struct node *temp = q->head;
    if (isEmpty(q))
    {
        printf("The queue is empty.\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void enqueue(struct queue *q)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (isEmpty(q))
    {
        q->head = new_node;
        q->front++;
        q->rear++;
    }
    else
    {
        struct node *temp = q->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        q->rear++;
    }
}

void dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("The queue is empty.\n");
    }
    else
    {
        struct node *temp = q->head;
        q->head = q->head->next;
        free(temp);
        q->rear--;
    }
}