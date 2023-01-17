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
        for (int j = 0; j < n; j++)

            printf("#");
        {
            for (int k = 0; k < n; k++)

                printf("#\n");
        }
        printf("\n");
    }

}





