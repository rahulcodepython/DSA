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
        printf("1. Display the queue\n");
        printf("2. Check if the queue is full\n");
        printf("3. Check if the queue is empty\n");
        printf("4. Enqueue\n");
        printf("5. Dequeue\n");
        printf("6. Peek\n");
        printf("7. Size of the queue\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display_queue(q);
            break;
        case 2:
            isFull(q) ? printf("The queue is full.\n") : printf("The queue is not full.\n");
            break;
        case 3:
            isEmpty(q) ? printf("The queue is empty.\n") : printf("The queue is not empty.\n");
            break;
        case 4:
            enqueue(q);
            break;
        case 5:
            dequeue(q);
            break;
        case 6:
            printf("The peek element is %d.\n", q->arr[q->front]);
            break;
        case 7:
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