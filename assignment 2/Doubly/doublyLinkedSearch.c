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

/* Given a reference (pointer to pointer) to the head of a list 
   and an int, inserts a new node on the front of the list. */
void insert(struct Node **reference, int data_to_insert)
{
    /* 1. allocate node */
    struct Node *new_node = create();

    /* 2. put in the data  */
    new_node->data = data_to_insert;

    /* 3. Make next of new node as head and previous as NULL */
    new_node->next = (*reference);
    new_node->prev = NULL;

    /* 4. change prev of head node to new node */
    if ((*reference) != NULL)
        (*reference)->prev = new_node;

    /* 5. move the head to point to the new node */
    (*reference) = new_node;
}

/* Given a node as prev_node, insert a new node after the given node */
void insertAfter(struct Node **reference, int data_to_insert)
{
    /*1. check if the given prev_node is NULL */
    if (reference == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    /* 2. allocate new node */
    struct Node *new_node = create();

    /* 3. put in the data  */
    new_node->data = data_to_insert;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = (*reference)->next;

    /* 5. Make the next of prev_node as new_node */
    (*reference)->next = new_node;

    /* 6. Make prev_node as previous of new_node */
    new_node->prev = *reference;

    /* 7. Change previous of new_node's next node */
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void append(struct Node **reference, int data_to_insert)
{
    /* 1. allocate node */
    struct Node *new_node = create();

    struct Node *last = *reference; /* used in step 5*/

    /* 2. put in the data  */
    new_node->data = data_to_insert;

    /* 3. This new node is going to be the last node, so 
          make next of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new 
          node as head */
    if (*reference == NULL)
    {
        new_node->prev = NULL;
        *reference = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;

    /* 7. Make last node as previous of new node */
    new_node->prev = last;

    return;
}

bool search(struct Node **reference, int data_to_search)
{

    if (*(reference) == NULL)
    {
        printf("Linked List not initialized");
        return false;
    }

    struct Node *pointer = *reference;
    struct Node *trailer = *reference;

    // Foward search
    while (pointer != NULL)
    {
        if (pointer->data == data_to_search)
        {
            return true;
        }
        trailer = pointer;
        pointer = pointer->next;
    }

    // Reverse search
    while (trailer != NULL)
    {
        if (trailer->data == data_to_search)
        {
            return true;
        }
        trailer = trailer->next;
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

    // traverse(&first);

    // Insert at begining then traverse
    // insert(&first, 56);
    // traverse(&first);

    // Insert after
    // insertAfter(&second, 6);
    // traverse(&first);

    // Append
    // append(&second, 789);
    // traverse(&first);

    // Search
    printf("\nSearch Begins \n");
    if (search(&first, 2))
    {
        printf("\nItem Has been found \n");
    }
    else
    {
        printf("\nItem Has not been found \n");
    }
    return 0;
}
