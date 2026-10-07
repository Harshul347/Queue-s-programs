#include <stdio.h>

#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

void insertFront(int value)
{
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front > 0)
    {
        front--;
    }
    else
    {
        printf("Deque is full at Front\n");
        return;
    }

    deque[front] = value;
}

void insertRear(int value)
{
    if (rear == -1)
    {
        front = rear = 0;
    }
    else if (rear < SIZE - 1)
    {
        rear++;
    }
    else
    {
        printf("Deque is full at Rear\n");
        return;
    }

    deque[rear] = value;
}

void deleteFront()
{
    if (front == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deleted from Front: %d\n", deque[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

void deleteRear()
{
    if (rear == -1)
    {
        printf("Deque is empty\n");
        return;
    }

    printf("Deleted from Rear: %d\n", deque[rear]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear--;
    }
}

void display()
{
    int i;

    printf("Remaining elements: ");

    for (i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}

int main()
{
    insertFront(10);
    insertRear(20);
    insertFront(30);

    deleteFront();
    deleteRear();

    display();

    return 0;
}
