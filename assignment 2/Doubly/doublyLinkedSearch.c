#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Give every node an int value
// (current_node, current_iteration, whether_circular, head_node)
void getValue(struct Node **ref, int i)
{

    // Pointer the actual tail
    struct Node *pointer = *ref;

    // Input data into node
    printf("\nEnter data for node %d: ", i);
    scanf("%d", &pointer->data);

    // End list
    pointer->next = NULL;
}

// ... create nodes dynamically
struct Node *dynamicNodes()
{
    struct Node *a_head = NULL;
    struct Node *a_tail = NULL;

    int size, i;

    printf("Enter size of list : ");
    scanf("%d", &size);

    for (i = 0; i < size; i++)
    {
        // Create first node
        if (i == 0)
        {
            // Create node
            a_head = a_tail = create();
            // Get value from user
            getValue(&a_tail, i);
            // Set p->ll (Left link) to NULL
            a_head->prev = NULL;
        }
        else
        {
            a_tail->next = create();     // adding new node to the end of non-empty list
            a_tail->next->prev = a_tail; // Update Left link for the node we've just created
            getValue(&a_tail->next, i);  // Insert data into the new node
            a_tail = a_tail->next;       // Update tail pointer (Move the tail one step)
        }
    }

    // Return the head of the list
    return a_head;
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

bool search(struct Node **reference)
{

    if (*(reference) == NULL)
    {
        printf("\nLinked List not initialized");
        return false;
    }

    struct Node *pointer = *reference;
    int search_term; 

    printf("\nPlease enter integer to be searched: ");
    scanf("%d", &search_term);

    // Foward search
    while (pointer != NULL)
    {
        if (pointer->data == search_term)
        {
            return true;
        }
        pointer = pointer->next;
    }
}

int main()
{
    // Create dynamic list and return the head of the node
    struct Node *dynamicList = dynamicNodes();

    traverse(&dynamicList);

    if (search(&dynamicList))
    {
        printf("\nThe integer has been found in the list\n");
    } else
    {
       printf("\nValue has not been found in the list\n"); 
    }
    
    return 0;
}
