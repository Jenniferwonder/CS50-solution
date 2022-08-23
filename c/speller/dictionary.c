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
const unsigned int N = 2000;

// Hash table
node *table[N];

//Initialize the number of words in the dictionary
unsigned int word_count = 0;

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open up and read from the dictionary file
    FILE *dict = fopen(dictionary, "r");

    //Check if the return value is NULL
    if (!dict)
    {
        printf("Could not open the file.\n");
        unload();
        return false;
    }

    //Read strings from a file one at a time

    //Define the maximum length of a word
    char word[LENGTH + 1];

    //Run "fscanf" until getting to the end of the file
    while (fscanf(dict, "%s", word) != EOF)
    {
        //fscanf(dict, "%s", word);

        //Create a new node for each word
        node *new_word = malloc(sizeof(node));
        if (new_word == NULL)
        {
            return false;
        }
        //Copy word into new_word node
        strcpy(new_word->word, word);

        //Hash word to obtain a hash value
        int index = hash(new_word->word);

        //Insert node into hash table at the index location
        new_word->next = table[index];
        table[index] = new_word;

        //Count number of new words
        word_count++;
    }

    //Close dictionary file
    fclose(dict);

    //Indicate success
    return true;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // get the index by using the hash function
    int index = hash(word);

    //Set cursor to the first item of the linked list
    node *cursor = table[index];

    //Compare two strings case-insensitively in a linked list until cursor points to null
    while (cursor != NULL) //version 1: while (cursor != 0)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;

    //Loop through every character in the string "word"
    for (int j = 0; word[j] != '\0'; j++)
    {
        //Make sure the hash function is case insensitive
        sum += tolower(word[j]);
    }

    //Make sure the return value is within the maximum buckets N of the hash table
    return sum % N;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //Free memory allocated for each node
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
