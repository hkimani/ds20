#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define structure of the node
struct Node
{
    int data;
    struct Node *next;
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

    // Pointer the actual head node
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
            a_head = a_tail = create();
            getValue(&a_tail, i);
        }
        else
        {
            a_tail->next = create();             // adding new node to the end of non-empty list
            getValue(&a_tail->next, i); // Insert data into the new node
            a_tail = a_tail->next;               // Update tail pointer (Move the tail one step)
        }
    }

    // Return the head of the list
    return a_head;
}

bool search(struct Node **reference)
{
    struct Node *pointer = *reference; // Initialize the head of the pointer
    int search_term;                   // What we want to search

    printf("\nPlease enter integer to be searched: ");
    scanf("%d", &search_term);

    while (pointer != NULL)
    {
        if (pointer->data == search_term)
        {
            return true;
        }

        pointer = pointer->next;
    }
}

// Traverse the list
void traverse(struct Node **ref)
{
    struct Node *pointer = *ref;
    while (pointer != NULL)
    {
        if (pointer->next != NULL)
        {
            printf("\n%d", pointer->data);
            pointer = pointer->next;
        }
        else
        {
            printf("\n%d\n", pointer->data);
            return;
        }
    }
}

// Program to create a simple linked
// list with 3 nodes
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
       printf("\nThe integer has not been found in the list\n"); 
    }
    

    return 0;
}
