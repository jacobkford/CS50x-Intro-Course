// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 50;

// Hash table
node *table[N];
int total_words = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Compares the words
    if (table[hash(word)] == NULL)
    {
        return false;
    }

    // Creates the cursor pointer that scans through the hash table
    node *cursor = table[hash(word)];

    // Goes through the entire hash table looking for the word
    while (strcasecmp(cursor->word, word) != 0)
    {
        if (cursor->next == NULL)
        {
            return false;
        }
        // Updates cursor position
        cursor = cursor->next;
    }
    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Source: djb2 algorithm by Dan Bernstein (http://www.cse.yorku.ca/~oz/hash.html)
    unsigned long hash = 5381;
    int c = *word;
    c = tolower(c);

    while (*word != 0)
    {
        hash = ((hash << 5) + hash) + c;
        c = *word++;
        c = tolower(c);
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Opens dictionary file
    FILE *file = fopen(dictionary, "r");
    // Checks if the program couldn't open the file
    if (file == NULL)
    {
        return false;
    }
    // Creates the chuck of memory each word in the Dictionary will be stored in until it's been hashed
    char *dict_word = malloc(LENGTH + 1);
    // Checks if the system stored this chunk of memory
    if (dict_word == NULL)
    {
        return false;
    }

    // Repeats until the end of the file
    while (fscanf(file, "%s", dict_word) != EOF)
    {
        // Creates the node header pointer
        node *n = malloc(sizeof(node));
        // Checks if the system stored this chunk of memory
        if (n == NULL)
        {
            return false;
        }

        // Copies the word and puts in into a chunk of memory the size of a node
        strcpy(n->word, dict_word);
        // Updates next node pointer to the first element in the linked list
        n->next = table[hash(dict_word)];
        // Resets the first element to be the new node
        table[hash(dict_word)] = n;
        // Adds to total word count for the size function
        total_words++;
    }
    // Closes dictionary file
    fclose(file);
    // Free memory from the Dictionary word's chunk of memory
    free(dict_word);
    // Ends function
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return total_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Creates 2 pointers that will go through the hash table
    node *tmp = NULL;
    node *cursor = NULL;
    // Goes through every element in the linked list
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL)
        {
            continue;
        }
        // Sets cursor to the current position
        cursor = table[i];
        tmp = cursor;

        // Loops until the cursor has reached the end of the linked list
        while (cursor->next != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
        free(cursor);
    }
    return true;
}