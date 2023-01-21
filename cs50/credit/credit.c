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

    int sum1 = 0;
    int sum2 = 0;
    long k = card;
    int total = 0;
    int end1;
    int end2;
    int d1;
    int d2;
    do
    {
        end1 = k % 10;
        k = k / 10;
        end1 = sum1 + end1;

        end2 = k % 10;
        k = k / 10;

        end2 = end2 * 2;
        d1 = end2 % 10;
        d2 = end2 / 10;
        sum2 = sum2 + d1 + d2;

    }
    while (k > 0);
    total = sum1 + sum2;

if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

long first = card;
    do
    {
        first = first / 10;
    }
    while (first > 100);

    if ((first / 10 == 5) && (0 < first % 10 && first % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
        else if ((first / 10 == 3) && (first % 10 == 4 || first % 10 == 7))
    {
        printf("AMEX\n");
    }
        else if (first / 10 == 4)
    {
        printf("VISA\n");
    }
        else
    {
        printf("INVALID\n");
    }

}
