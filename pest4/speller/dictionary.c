// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table called Array of pointers

node *hashtable[N];

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];


    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {

        node *new_node = malloc(sizeof(node));
        if()
        {
            unload();
            return false;
        }
        strcpy(new_node -> word,word);

        new_node->next = hashtable[hash(word)];

        hashtable[hash(word)] = new_node;

    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int wordCount = 0;
    for (int i = 0; i < N; i++)
    {
    node *nodePointer =  hashtable[i];
    while (nodePointer != NULL)
        {
            char *Word = (nodePointer -> word);
            nodePointer = (nodePointer -> next);
            wordCount++;
        }
    }
    return wordCount;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *cursor =  hashtable[hash(word)];
    while(cursor!=NULL)
    {
        char* word2 = cursor->word;
        cursor = cursor->next;
       int i = strcasecmp(word,word1);
        if(i != 0){return true;}
    }

    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
     node *temp;
    for(int i=0 ; i < N ; i ++)
    {
        node *cursor = hashtable[i];
        while(cursor!=null)
        {
            temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        if(i == 25){return true;}
    }



    return false;
}
