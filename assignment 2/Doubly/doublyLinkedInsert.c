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

/* Given a reference (pointer to pointer) to the head of a list 
   and an int, inserts a new node on the front of the list. */
void add(struct Node **reference)
{

    int data_to_insert;
    printf("\nPlease enter Integer to insert at begining: ");
    scanf("%d", &data_to_insert);

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
void addAfter(struct Node **reference)
{

    int data_to_insert;
    printf("\nPlease enter Integer to insert after: ");
    scanf("%d", &data_to_insert);

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

void append(struct Node **reference)
{

    int data_to_insert;
    printf("\nPlease enter Integer to append: ");
    scanf("%d", &data_to_insert);

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

int main()
{

    // Create dynamic list and return the head of the node
    struct Node *dynamicList = dynamicNodes();

    traverse(&dynamicList);

    // Add at front
    add(&dynamicList);

    traverse(&dynamicList);

    // Insert
    addAfter(&dynamicList);

    traverse(&dynamicList);

    // Append
    append(&dynamicList);

    traverse(&dynamicList);

    return 0;
}
