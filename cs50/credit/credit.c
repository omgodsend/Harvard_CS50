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
    long lastnum = card/10;
    long alternate = lastnum % 10;
    alternate += alternate;
    card = card / 100;
    altsum = alternate+= alternate;
    }

    //if


   // else
  //  {
   //     printf("INVALID");
   // }

}
