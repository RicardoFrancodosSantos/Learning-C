#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get the desired height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (8 < n || n < 1);


    int row = 0;     // Current row / amount of #
    int space = 0;   // Amount of spaces before #
    int s_count = 0; // Counter to keep track of space
    int b_count = 0; // Counter to keep track of #
    do
    {

        space = (n - row - 1);

        // Loop to print spaces
        while (s_count < space)
        {
            printf(" ");
            s_count++;
        }

        s_count = 0;

        // Loop to print #'s

        do
        {
            printf("#");
            b_count++;
        }
        while (b_count < (row + 1));

        b_count = 0;
        printf("  ");

        // Loop to print #'s after space

        do
        {
            printf("#");
            b_count++;
        }
        while (b_count < (row + 1));

        b_count = 0;
        printf("\n");
        row++;
    }
    while (row < n);
}
