#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);

int main(void)
{

    string all = get_string("Text: ");

    int letters = count_letters(all);

    printf("%i letters\n", letters);

}

int count_letters(string text)
{
    int num = strlen(text);
    int len = 0;

    for (int i = 0; i < num; i++)
    {
        if (isalpha(text[i]))
        {
            len ++;
        }
    }

return len;
}
