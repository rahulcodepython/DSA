#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

void create_queue(struct queue *q);
bool isFull(struct queue *q);
bool isEmpty(struct queue *q);
void display_queue(struct queue *q);
void enqueue(struct queue *q);
void dequeue(struct queue *q);

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    int choice;
    bool controller = true;
    printf("Enter the size of the array: ");
    scanf("%d", &q->size);
    q->arr = (int *)malloc(q->size * sizeof(int));
    q->front = -1;
    q->rear = -1;
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
            create_queue(q);
            break;
        case 2:
            if (isFull(q))
            {
                printf("The queue is full.\n");
            }
            else
            {
                printf("The queue is not full.\n");
            }
            break;
        case 3:
            if (isEmpty(q))
            {
                printf("The queue is empty.\n");
            }
            else
            {
                printf("The queue is not empty.\n");
            }
            break;
        case 4:
            display_queue(q);
            break;
        case 5:
            enqueue(q);
            break;
        case 6:
            dequeue(q);
            break;
        case 7:
            if (isEmpty(q))
            {
                printf("The queue is empty.\n");
            }
            else
            {
                printf("Peek is %d.\n", q->arr[q->front]);
            }
            break;
        case 8:
            printf("The size of the queue occupied is %d.\n", q->rear + 1);
            break;
        default:
            printf("The program is terminated.\n");
            controller = false;
            break;
        }
    }
    free(q->arr);
    free(q);
    return 0;
}

void create_queue(struct queue *q)
{
    int data;
    bool controller = true;
    if (isFull(q))
    {
        printf("The queue is full.\n");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        while (controller && !isFull(q))
        {
            printf("Enter the data: ");
            scanf("%d", &data);
            if (data >= 0)
            {
                q->arr[++q->rear] = data;
            }
            else
            {
                controller = false;
            }
        }
    }
}

bool isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        return true;
    }
    return false;
}

bool isEmpty(struct queue *q)
{
    if (q->front == -1)
    {
        return true;
    }
    return false;
}

void display_queue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("The queue is empty.\n");
    }
    else
    {
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

void enqueue(struct queue *q)
{
    int data;
    if (isFull(q))
    {
        printf("The queue is full.\n");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        printf("Enter the data: ");
        scanf("%d", &data);
        q->arr[++q->rear] = data;
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
        for (int i = q->front; i <= q->rear - 1; i++)
        {
            q->arr[i] = q->arr[i + 1];
        }
        q->rear--;
    }
}