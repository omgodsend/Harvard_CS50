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

    while(card > 0)
    {

    long lastNumber = card/10;
    long everyOther = lastNumber % 10;
    card = card / 100;
    printf("%li\n", everyOther);
}

    //if


   // else
  //  {
   //     printf("INVALID");
   // }

}
12345
    long lastNumber = visa/10; 
    long everyOther = lastNumber % 10;
    visa = visa / 100;
    printf("%li\n", everyOther);
