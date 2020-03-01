#include <stdio.h>
#include <stdlib.h>

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

// By reference we mean head
/* Given a reference (pointer to pointer) to the head of a list and an int,  inserts a new node on the front of the list. */
void add(struct Node **reference)
{
    int new_data;
    printf("\nPlease enter Integer to insert at begining: ");
    scanf("%d", &new_data);

    /* 1. allocate node */
    struct Node *new_node = create();

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. Make next of new node as head */
    new_node->next = (*reference);

    /* 4. move the head to point to the new node */
    (*reference) = new_node;
}

// Insert after the first node
// Can be apllied for all other nodes
void addAfter(struct Node **prev_node)
{

    int new_data;
    printf("\nPlease enter Integer to insert in: ");
    scanf("%d", &new_data);

    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL)
    {
        printf("\nthe given previous node cannot be NULL");
        return;
    }

    /* 2. allocate new node */
    struct Node *new_node = create();

    /* 3. put in the data  */
    new_node->data = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = (*prev_node)->next;

    /* 5. move the next of prev_node as new_node */
    (*prev_node)->next = new_node;
}

void append(struct Node **reference)
{

    int new_data;
    printf("\nPlease enter Integer to append: ");
    scanf("%d", &new_data);

    /* 1. allocate node */
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    struct Node *last = *reference; /* used in step 5*/

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so make next of 
          it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*reference == NULL)
    {
        *reference = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}


// Program to create a simple linked
// list with 3 nodes
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
