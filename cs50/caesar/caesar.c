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

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");
    int plaintext_length = strlen(plaintext);

    string ciphertext = "";

    printf("ciphertext: %s", ciphertext);

    // For each character in the plaintext:
    for (int i = 0; i < plaintext_length; i++)
    {
        ciphertext += rotate(plaintext[i], key);
    }

    printf("\n");

    return 0;
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
        // Shift the character n times and wrap around
        printf("%c", ((c - 'A' + n) % 26 + 'A'));
    }
    // If the character is lowercase
    else if (c >= 'a' && c <= 'z')
    {
        // Shift the character n times and wrap around
        printf("%c", ((c - 'a' + n) % 26 + 'a'));
    }
    return c;
}