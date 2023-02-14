#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool only_digits(string s);

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

    // Prompt user for plaintext

    // For each character in the plaintext:

        // Rotate the character if it's a letter


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