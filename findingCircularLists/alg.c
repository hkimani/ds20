#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define type of node (Singly linked list)
struct Node
{
    int data;
    struct Node *next;
};

// Function for creating nodes
struct Node *create()
{
    return (struct Node *)malloc(sizeof(struct Node));
}

// function for checking whether list has loop
bool hasCycle(struct Node **head)
{

    if (head == NULL)
    {
        printf("List is empty");
        return false;
    }

    // We initialize the first pointer 1 step ahead to start with
    struct Node *hare = (*head)->next;
    struct Node *tortoise = *head;

    // While we are stil traversing the list
    while (hare != NULL && hare->next != NULL && tortoise != NULL)
    {
        // When we find two equal nodes
        if (hare->data == tortoise->data)
        {
            printf("%d", hare->data);
            printf("\nLoop found\n");
            return true;
        }

        hare = hare->next->next;
        tortoise = tortoise->next;
    }

    // If there's no cycle
    printf("\nNo cycle has been found\n");
    return false;
}

// (current_node, current_iteration, whether_circular, head_node)
void getValue(struct Node **ref, int i, bool circular, struct Node **head)
{

    // Pointer the actual head node
    struct Node *pointer = *ref;

    // Input data into node
    printf("\nEnter data for node %d: ", i);
    scanf("%d", &pointer->data);

    // End list
    if (circular == true) {
        // If we are creating a circular list the the next will point to the head
        pointer->next = *head;
    } else
    {
        // Creating a non circular pointer
        pointer->next = NULL;
    }   
    
}

// Struct of return type node
// ... create nodes dynamically
struct Node *dynamicNodes(bool circular)
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
            getValue(&a_tail, i, circular, &a_head);
        }
        else
        {
            a_tail->next = create();    // adding new node to the end of non-empty list
            getValue(&a_tail->next, i, circular, &a_head); // Insert data into the new node
            a_tail = a_tail->next;      // Update tail pointer (Move the tail one step)
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

int main()
{

    // int snprintf(char *str, size_t size, const char *format, ...);

    // Create dynamic list and return the head of the node
    // struct Node *dynamicList = dynamicNodes(false);
    // traverse(&dynamicList);

    // create circular list
    struct Node *circularList = dynamicNodes(false);

    // Floyd's algorithm. Tortoise and hare
    hasCycle(&circularList);
}
