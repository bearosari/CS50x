// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
int tot_words = 0; //container for the total number of words


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //hashes word to obtain hash value
    node *cursor = table[hash(word)];

    //compares two strings case-insensitively
    if (strcasecmp(cursor->word, word) == 0)
    {
        return true;
    }

    //traverses linked list looking fot the word
    while (cursor->next != NULL)
    {
        cursor = cursor->next;
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}


// Hashes word to a number
// first letter, alphabet as buckets
unsigned int hash(const char *word)
{
    // TODO
    int hash_num = (int) tolower(word[0]) - 97;

    return hash_num;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // opens dictionary file
    FILE *file = fopen(dictionary, "r");
    char *dict_word = malloc(LENGTH);

    if (dict_word == NULL)
    {
        return false;
    }

   // reads strings from file on at a time
    while (fscanf(file, "%s", dict_word) != EOF)
    {
        // creates a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // copies word into node
        strcpy(n->word, dict_word);
        tot_words++;

        // uses hash function to hash word to determine which linked list to use
        n->next = table[hash(dict_word)];

        // insert node to the beginning of the linked list
        table[hash(dict_word)] = n;
    }

    fclose(file);
    free(dict_word);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // counts total words in dictionary
    return tot_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
     // creates two pointers to traverse the linked list and cancel its element without losing its address
    node *temp;
    node *cursor;

    // repeats for every index in the table
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL)
        {
            continue;
        }

        cursor = table[i];
        temp = cursor;

        // until the end of the list keeps freeing the memory allocated in load
        while (cursor->next != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
        free(cursor);
    }
    return true;
}
