#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Requests pyramid height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // Loop for each pyramid line
    for (int row = 0; row < n; row++)
    {
        // Imprime espaços à esquerda
        for (int space = 0; space < (n - row - 1); space++)
        {
            printf(" ");
        }

        // Imprime blocos # (primeira metade)
        for (int hash = 0; hash <= row; hash++)
        {
            printf("#");
        }

        // Espaço duplo no meio
        printf("  ");

        // Imprime blocos # (segunda metade)
        for (int hash = 0; hash <= row; hash++)
        {
            printf("#");
        }

        // Nova linha após cada linha da pirâmide
        printf("\n");
    }
    
    return 0;
}
