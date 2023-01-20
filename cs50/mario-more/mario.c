#include <cs50.h>
#include <stdio.h>

int main(void)

{

    int n;

    do
    {
        n = get_int("size: ");
    }
    while (n < 1 || n > 8);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n - i); j++)
        {
            printf(" ");
        }
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}



//The outer for loop starts at 1 and goes up to n, the size of the pyramids
//he first inner for loop is for printing the spaces before the first set of hashtags. It starts at 1 and goes up to (n - i), where i is the current iteration of the outer for loop. This ensures that the spaces decrease as the number of hashtags increase.
//The second inner for loop is for printing the first set of hashtags. It starts at 1 and goes up to i, the current iteration of the outer for loop.
//The third inner for loop is for printing the second set of hashtags, which are the same number of the first set.
//The printf("\n") at the end of each iteration of the outer for loop will create a new line, creating the pyramid shape.