#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{

// Make sure program was run with just one command-line argument
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        return 0;
    }

    // Convert argv[1] from a `string` to an `int`
    int arg = atoi(argv[1])

    // Prompt user for plaintext
    int prompt = getstring("Plaintext: \n")

    // For each character in the plaintext:
    for (int i = 0; i < strlen(prompt); i++)
    {
        rotate((char)prompt[i], arg)
    }
}

bool only_digits(string text)
{
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        if (!isdigit(text[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    int arg;

    if ((char)c >= 'A' && (char)c <= 'Z')
    {
        return((char)c + arg);
    }
    else if ((char)c >= 'a' && (char)c <= 'z')
    {
        ((char)c + arg);
    }
    else
    {
        return (char) c;
    }

}