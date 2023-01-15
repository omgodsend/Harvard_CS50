#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
 int n;
  do
  {
      n = get_int("Start size: ");
  }
  while (n >= 9);

    // TODO: Prompt for end size
int e;
  do
  {
      e = get_int("End size: ");
  }
  while (e >= n);

    // TODO: Calculate number of years until we reach threshold
//Inside the loop, you’ll likely want to update the population size according to the formula in the Background, and update the number of years that have passed
//formula
int born = n/3;
int die = n/4;

int net_pop = n + born - die;

int y;
do
{
for (int y = 0; e < net_pop; y++)

}
while net_pop < e;


    // TODO: Print number of years
     printf("Years %i\n", n);
}

//create a variable to keep track of how many years have passed.