// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 50000;
// Keep track of the number of words
int count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    node *cursor = table[index];
    for (node *temp = cursor; temp != NULL; temp = temp->next)
    {
        if (strcasecmp(temp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return strlen(word);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary
    FILE *f = fopen(dictionary, "r");
    // Check if open is successful
    if (f == NULL)
    {
        return false;
    }

    // Temporary store the word read from the dictionary
    char word[LENGTH + 1];
    while (fscanf(f, "%s", word) != EOF)
    {
        // Count the number of words
        count += 1;
        // Create a new node
        node *w = malloc(sizeof(node));
        // Check if malloc is successful
        if (w == NULL)
        {
            unload();
            return false;
        }
        // Copy new word into node
        strcpy(w->word, word);
        w->next = NULL;

        // Get index for hash table
        int index = hash(w->word);

        if (table[index] == NULL)
        {
            table[index] = w;
        }
        else
        {
            w->next = table[index];
            table[index] = w;
        }
    }
    fclose(f);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *temp = NULL;
    node *cursor = NULL;
    for (int i = 0; i < N; i += 1)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
