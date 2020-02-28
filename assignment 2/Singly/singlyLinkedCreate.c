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

// Program to create a simple linked
// list with 3 nodes
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

    second->data = 2; // assign data to second node
    second->next = third; // Link second node with the third node

    third->data = 3; // assign data to third node
    third->next = NULL; // Complete list

    printf("%d \n", second->data);

    return 0;
}
