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
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string prompt = get_string("Plaintext: \n");

    string cyphertext = ""

    // For each character in the plaintext:
    for (int i = 0; i < strlen(prompt); i++)
    {
        cyphertext += rotate((char)prompt[i], key);
    }

    printf("cyphertext: %s\n", cyphertext);
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
    // If the character is uppercase
    if (c >= 'A' && c <= 'Z')
    {
        // Shift the character n times and wrap around if necessary
        c = (c - 'A' + n) % 26 + 'A';
    }
    // If the character is lowercase
    else if (c >= 'a' && c <= 'z')
    {
        // Shift the character n times and wrap around if necessary
        c = (c - 'a' + n) % 26 + 'a';
    }

    return c;
}