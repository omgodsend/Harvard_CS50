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

for (i, i=0, i--)
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
    printf("%li\n", everyOther);
}




}
