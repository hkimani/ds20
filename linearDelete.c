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
    // variable receives a pointer to an array of pointers
    char **list;
    // Length of the list
    int n = 5;

    // Allocate memory block and return address of the linear list
    list = calloc(n, sizeof(char *));

    printf("The elements of the array are: \n");

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
    for (int i = 0; i < n; ++i)
    {
        printf("%s, \n", list[i]);
    }

    // Define search string that doesn't exist in the list
    char searchStringFalse[] = "tesla";

    // Define search string that exists in the list
    char searchStringTrue[] = "element 4";

    for (int i = 0; i < n; i++)
    {
        // Compare if the two strings are identical
        if ((strcmp(list[i], searchStringTrue) == 0))
        {
            // printf ("\n");
            // printf("Search started: \n%s found at index %d after %d iterations \n", searchStringTrue, i, i + 1);

            // Actual position of the element we want to delete starting from one
            int position = i + 1;

            // Size of the new list = n - 1;
            n--;

            // Do deletion for the list
            for (int i = position; i <= n; i++)
            {
                list[i - 1] = list[i];
            }

            // Set old final position to null. 
            // ... because count starts from 0 and the FINAL ELEMENT OF A LIST is
            // ... represented by n - 1 and because we decreased the length of n by one before deletion,
            // ... the final element of the OLD LIST is represented by n
            list[n] = NULL;

            printf("\n%s has been deleted, new list is: \n\n", searchStringTrue);

            // Confirm new list
            for (int i = 0; i < n; i++)
            {
                printf("%s \n", list[i]);
            }

            return 0;
        }
        else if (i == n - 1)
        {
            printf("\n");
            printf("String not found after %d iterations \n", n);
            return 0;
        }
        // printf("%d \n", i);
    }
}
