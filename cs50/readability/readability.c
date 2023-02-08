#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);

int main(void)
{

    string all = get_string("Text: ");

    int letters = count_letters(all);
    int words = count_words(all);


    printf("%i Letters\n %i Words", letters, words);

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

int count_words(string word)
{
    int len 


}