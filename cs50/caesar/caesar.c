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
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        return 0;
    }

    // Make sure every character in argv[1] is a digit
    int check = only_digits(argv[1])

    if (check == 0)



    // Convert argv[1] from a `string` to an `int`

    // Prompt user for plaintext

    // For each character in the plaintext:

        // Rotate the character if it's a letter


}

bool only_digits(string s)
{
    if (isdigit(argv[1]))
    {
        printf("true");
        return true;
    }
    else
    {
        return false;
    }

}