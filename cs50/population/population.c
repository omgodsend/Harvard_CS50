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
  while (n < 9);

    // TODO: Prompt for end size
int e;

do

  {
      e = get_int("End size: ");
  }
  while (e < n);

int y = 0;
do
{
    if (e==n)
    {
        printf("Years = 0\n");
    }
    else
    {
        n = n + ((n/3) - (n/4));
y++;

    }
}
while (n < e);

printf("Years: %i\n", y);

}
