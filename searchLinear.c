#include <stdio.h>
#include <stdlib.h>

void fail()
{
    printf("Cannot allocate memory");
    exit(EXIT_FAILURE);
}

int main()
{
    int *head;
    int n;

    // Length of the list
    n = 5;

    // Allocate memory block and return address of the linear list
    head = calloc(n, sizeof(char[2]));

    if (head == NULL)
        fail();

    for (int i = 0; i < n; i++)
    {
        head[i] = ("element %d", i);
    }

    // Accessing the block
    // Print the elements of the array
    printf("The elements of the array are: ");
    for (int i = 0; i < n; ++i)
    {
        printf("%s, ", head[i]);
    }

    return 0;
}
