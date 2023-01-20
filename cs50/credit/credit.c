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
        long num = card;
        while (num > 0)
        {
            num = num / 10;
            i++;
        }

if (i%2 !=0);




}
