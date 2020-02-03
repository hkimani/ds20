#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the stack with max size
char stack[5];

// When last is negative 1, the stack is empty
int last = -1;

// Number of elements we'll work with
int count = 5;

// Elements we'll work with
char letters[5] = {'a', 'b', 'c', 'd', 'e'};

int push(char character)
{

    if (last == count - 1)
    {
        printf("\nStack full");
        return 0;
    }
    else
    {
        // Increment size tracker by 1
        last = last + 1;
        stack[last] = character;
        return 0;
    }
}

int pop()
{
    if (last == -1)
    {
        printf("\nStack is empty!!\n");
        return 0;
    }
    else
    {
        printf("\nPopped element is %c \n", stack[last]);
        // Decrement size tracker by one
        last = last - 1;
        return 0;
    }
}

void display()
{
    if (last >= 0)
    {
        printf("\nElements in the STACK from top to bottom \n");
        for (int i = last; i >= 0; i--)
            printf("\n%c", stack[i]);
    }
    else
    {
        printf("\nThe STACK is empty");
    }
}

int main()
{
    // Pop empty list
    printf("Trying to pop an empty stack:");
    pop(1);

    // push to empty list
    printf("\nPushing to the stack till full:");
    for (int i = 0; i < count; i++)
    {
        push(letters[i]);
    }

    // Display the elements we've pushed
    display();

    // Trying to push to a full stack
    printf("\n\nTrying to push to a full stack:");
    push('x');

    // Popping all elements and trying to display the stack
    printf("\n\nPopping all elements and trying to display the stack:");
    for (int i = 0; i < count; i++)
    {
        pop();
    }

    // Trying to display empty stack
    printf("\nTrying to display empty stack: ");
    display();    

}
