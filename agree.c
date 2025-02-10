// i want to make a program that get a c char value and asks to user if he agrees with the question
#include <cs50.h>
#include <stdio.h>

int main(void)

{
    char c = get_char(" do you agree?");
    if (c == 'y' || c == 'Y')
    {
        printf("Agreed\n");
    }

    else if (c == 'n' || c == 'N')
    {

        printf("Not agreed.\n");
    }
}