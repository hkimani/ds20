#include <stdio.h>

// Defining an array wth max input size
char queue_array[10];

// Initializing a tracker for queue = empty
int rear = -1;

// 
int front = -1;
char elements[5] = {'a', 'b', 'c', 'd', 'e'};

// Max queue size
int queueSize = 50;

// Insert elements into the queue
int enqueue(char item)
{
    // If we are already at the last element
    if (rear == queueSize - 1)
        printf("Queue full \n");
    else
    {
        // When we are at first element
        if (front == -1)
            front = 0;

        printf("Element enqueued is : %c \n", item);
        rear = rear + 1;

        // Enqueue
        queue_array[rear] = item;
    }
    return 0;
}

int dequeue ()
{
    // If queue is already empty and still trying to delete
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow \n");
        return 0;
    }
    else
    {
        printf("Element dequeued is : %c\n", queue_array[front]);
        front = front + 1;
    }
    return 0;
}

int display()
{
    int i;
    if (front == -1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%c ", queue_array[i]);
        printf("\n");
    }
    return 0;
}

int main()
{
    // Insert element into queue (ENQUEUE)
    for (int i = 0; i < sizeof(elements); i++)
    {
        // Enqueue 5 element
        enqueue(elements[i]);
    }

    printf("\n");

    // Display the elements that have been enqueued
    display();

    printf("\n");

    // Delete elements in the queue one by one (DEQUEUE)
    // ... first in first out
    for (int i = 0; i < sizeof(elements); i++)
    {
        // Dequeue
        dequeue ();
    }
}