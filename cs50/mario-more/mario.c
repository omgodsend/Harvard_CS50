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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n-i; j++)
            printf(" ");
        for (int k = 0; k < (i*2)-1; k++)
            printf("#");

        printf("\n");
    }

}





