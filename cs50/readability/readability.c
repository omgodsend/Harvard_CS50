#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string words);
int count_sentences(char *sent);

int main(void)
{

    string all = get_string("Text: ");

    int letters = count_letters(all);
    int words = count_words(all);
    int sent = count_sentences(all);

    float L = ((letters/(float)words) * 100);
    float S = ((sent/(float)words) * 100);

    int index = (0.0588 * L - 0.296 * S - 15.8);

    printf("Grade %i\n", index);

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
    int len = 1;
    int num = strlen(word);

    for (int i = 0; i < num; i++)
    {
        if (isspace(word[i]))
        {
            len ++;
        }
    }
return len;
}

int count_sentences(char *sent)
{
    int len = 0;
    int num = strlen(sent);

    for (int i = 0; i < num; i++)
        {
            if ((sent[i]) == '.' || (sent[i]) == '!' || (sent[i]) == '?')
            {
                len ++;
            }
        }
return len;
}