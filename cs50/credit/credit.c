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

        if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    int add1 = 0;
    int add2 = 0;
    long cc = n;
    int total = 0;
    int mo1;
    int mod2;
    int d1;
    int d2;
    do
    {
        mod1 = x % 10;
        cc = cc / 10;
        add1 = add1 + mod1;
        
        mod2 = x % 10;
        x = x / 10;

        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;

    }
    while (x > 0);
    total = sum1 + sum2;

long start = n;
    do
    {
        start = start / 10;
    }
    while (start > 100);

    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
        else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }
        else if (start / 10 == 4)
    {
        printf("VISA\n");
    }
        else
    {
        printf("INVALID\n");
    }

}
