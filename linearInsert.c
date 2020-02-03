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
    // ... an extra line is added to the block for the insertion
    list = calloc(n + 1, sizeof(char *));

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

    // Define search string that exists in the list
    char stringBefore[] = "element 4";

    // string to be inserted
    char string[] = "element x";

    for (int i = 0; i < n; i++)
    {
        // Compare if the two strings are identical
        if ((strcmp(list[i], stringBefore) == 0))
        {

            // Actual position of the element we want to delete starting from one
            int position = i + 1;

            // Size of the new list = n - 1;
            n++;

            // Shift the elements forward
            for (int i2 = n; i2 >= position; i2--)
            {
                list[i2] = list[i2 - 1];
            }

            list[position - 1] = string;

            printf("\n%s has been added before %s, new list is: \n\n", string, list[i + 1]);

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
