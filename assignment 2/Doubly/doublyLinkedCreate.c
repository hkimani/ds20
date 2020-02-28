#include <stdio.h>
#include <stdlib.h>

/* Node of a doubly linked list */
struct Node
{
    int data;
    struct Node *next; // Pointer to next node in DLL
    struct Node *prev; // Pointer to previous node in DLL
};

// Create function with return type of struct node
struct Node *create()
{
    return (struct Node *)malloc(sizeof(struct Node));
}

struct Node *traverse(struct Node **reference)
{

    printf("\nTraversal in forward direction: \n");
    struct Node *pointer = *reference;
    struct Node *trailer;
    while (pointer != NULL)
    {
        printf("%d \n", pointer->data);
        trailer = pointer;
        pointer = pointer->next;
    }

    printf("\nTraversal in reverse direction using trailer: \n");
    while (trailer != NULL)
    {
        printf("%d \n", trailer->data);
        trailer = trailer->prev;
    }
}

int main()
{

    // Create three nodes
    struct Node *first = create();
    struct Node *second = create();
    struct Node *third = create();

    /*Data is random because we haven’t assigned  
    anything yet  */

    first->data = 1;      // assign data in first node
    first->next = second; // Link first node with the second node
    first->prev = NULL;   // Link node to previous

    second->data = 2;     // assign data to second node
    second->next = third; // Link second node with the third node
    second->prev = first; // Link to previous

    third->data = 3;      // assign data to third node
    third->next = NULL;   // Complete list
    third->prev = second; // Link to previous

    traverse(&first);

    return 0;
}
