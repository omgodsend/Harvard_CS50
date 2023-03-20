// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function


    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    int dict_size = 0;

    FILE *open_dictionary = fopen(dictionary, "r");
    if (open_dictionary == NULL)
    {
        printf("Error: Could not open %s.\n", argv[1]);
        return false;
    }

    char Dword[LENGTH + 1];
    while (fscanf(open_dictionary, "%s", Dword) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Error: unable to allocate memory\n");
            return false;
        }

    strcpy(new_node->word, Dword);
    new_node->next = NULL;
    int index = hash(Dword);

    if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        else
        {
            newNode -> next = table[index];
            table[index] = newNode;
        }

    dict_size++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
