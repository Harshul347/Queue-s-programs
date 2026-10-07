#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int priority[SIZE];
int count = 0;

void insert(int value, int p)
{
    if (count == SIZE)
    {
        printf("Priority Queue is full\n");
        return;
    }

    queue[count] = value;
    priority[count] = p;
    count++;
}

void deleteHighestPriority()
{
    int i, pos = 0;

    if (count == 0)
    {
        printf("Priority Queue is empty\n");
        return;
    }

    for (i = 1; i < count; i++)
    {
        if (priority[i] < priority[pos])
            pos = i;
    }

    printf("Deleted element: %d\n", queue[pos]);

    for (i = pos; i < count - 1; i++)
    {
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }

    count--;
}

void display()
{
    int i;

    printf("Remaining elements:\n");

    for (i = 0; i < count; i++)
    {
        printf("Element: %d, Priority: %d\n",
               queue[i], priority[i]);
    }
}

int main()
{
    insert(10, 2);
    insert(20, 1);
    insert(30, 3);

    deleteHighestPriority();

    display();

    return 0;
}
