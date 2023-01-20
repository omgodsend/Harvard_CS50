#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;

    do
    {
        card = get_long("Enter card number: ");
    }
    while (card < 0);


    int i = 0;
 //       long cc = n;
        while (card > 0)
        {
            card = card / 10;
            i++;
        }
printf(%li, card);

}
