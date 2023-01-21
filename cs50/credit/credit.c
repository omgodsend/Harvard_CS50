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
4
3
5
if (i%2 !=0);
card= 5

if i = 13
card= card/10 = 726354728374
n1= a%10 = 4
card= card/100 = 7263547283
n2= card%10= 3
card = card/100 = 72635472
n3= card%10 = 2
card = card/100 = 726354
n4= card%10 = 4
card = card/100 = 7263
n5 = card%10 = 3
card= card/100 = 72
n6= card%10 = 2
n1+n2 +n3 +n4+n5+n6)*2

else
card= card/10 = 72635472837453
num1= a%10 = 3
card= card/100 = 726354728374
num2= card%10= 4
card = card/100 = 7263547283
num3= card%10 = 3
card = card/100 = 72635472
num4= card%10 = 2
card = card/100 = 726354
num5 = card%10 = 4
card= card/100 = 7263
num6= card/10 = 3
card= card/100 = 72
num7= card%10=2
n1+n2 +n3 +n4+n5+n6+n7


for (k, k=0, i--)
a= card/10 = 51324
num1= card%10 = 4
card= a/100 = 513
num2= card%10= 3
(num1+num2) *2 =14



a=    513247/10 = 51324
num1  a%10 = 4
card=    a/100= 513
num2= b%10 = 3
c =.  b/10 = 51
num 3 = c/10 = 5


b=      a%10 =
b= a/10 =       51
num2= b%10 =    1

while(visa > 0)
{
    long lastNumber = visa/10;
    long everyOther = lastNumber % 10;
    visa = visa / 100;
    return every0ther

}
// Calculate checksum
    int sum1 = 0;
    int sum2 = 0;
    long x = n;
    int total = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;
    do
    {
        // Remove last digit and add to sum1
        mod1 = x % 10;
        x = x / 10;
        sum1 = sum1 + mod1;
        // Remove second last digit
        mod2 = x % 10;
        x = x / 10;
        // Double second last digit and add digits to sum2
        mod2 = mod2 * 2;
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (x > 0);
    total = sum1 + sum2;


}
