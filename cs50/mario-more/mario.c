#include <cs50.h>
#include <stdio.h>

int main(void)

{

    int n;

    do
    {
        n = get_int("size: ");
    }
    while (n < 0 || n > 8);

    for (int i = 0; i < n; i++)
    {
        {
            for (int j = 1; j < n; j++)
                {
                    printf(" ");
                }
        }

        printf("#\n");

    }

//printf("\n");

}


