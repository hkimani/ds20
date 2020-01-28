#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>

void fail()
{
    printf("Cannot allocate memory");
    exit(EXIT_FAILURE);
}

int main()
{   
    // variable for where we want to store contigous list
    char **list;
    // Length of the list
    int n = 5;

    // Allocate memory block and return address of the linear list
    list = calloc(n, sizeof(char*));

    if (list == NULL)
        fail();

    for (int i = 0; i < n; i++)
    {
        // The number plus terminating character
        // ... n memory locations with 10 bytes of space
        char str[n][10];
        
        // Format put into string
        sprintf(str[i], "element %d", i + 1);

        // The highest number that can be stored is 255 because only one 1 byte of memory,
        // ... is allocated for storage

        list[i] = str[i];
    }

    // Accessing the block
    // Print the elements of the array
    printf("The elements of the array are: ");
    for (int i = 0; i < n; ++i)
    {
        printf("%s, \n", list[i]);
    }

    return 0;
}
