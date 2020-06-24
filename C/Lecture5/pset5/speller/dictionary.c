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
} node;

void deleteList(node **list);
void destroyHashTable();

// Number of word in dictionary
long numWord = 0;

// Number of buckets in hash table
const unsigned int N = 2000;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    FILE *F = fopen("log_check.txt", "a");

    unsigned int key = hash(word);
    //printf("Keys during check, word:%s, key: %i\n", word, key);
    if (table[key] != NULL)
    {
        for (node *travPtr = table[key]; travPtr != NULL; travPtr = travPtr->next)
        {
            int i = strcasecmp(word, travPtr->word);

            if (!strcasecmp(travPtr->word, word))
            {
                //fclose(F);
                return true;
            }
            else
            {
                //fprintf(F, "Word: %s, Dictionary: %s, key : %i\n", word, travPtr->word, key);
            }
        }
    }
    fclose(F);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash = 5381;
    int c;

    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + tolower(c);
    }

    return (hash % N);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    unsigned int ind;
    char buffer[LENGTH + 1];
    FILE *F = fopen("log.txt", "a");
    FILE *file = fopen(dictionary, "r");
    node *newWord;
    if (file)
    {
        while (fgets(buffer, (LENGTH + 1), file))
        {
            if (buffer[0] != '\n')
            {
                strtok(buffer, "\n"); // Remove newline character

                newWord = calloc(1, sizeof(node));

                strcpy(newWord->word, buffer);

                ind = hash(buffer);

                if (table[ind] == NULL)
                {
                    table[ind] = newWord;
                }
                else
                {
                    newWord->next = table[ind];
                    table[ind] = newWord;
                }
                //fprintf(F, "Word: %s\t index: %i\n", newWord->word, ind);
                numWord++;
            }
        }
        fclose(file);
        fclose(F);
        return true;
    }
    fclose(file);
    fclose(F);
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return numWord;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    destroyHashTable();
    for (int i = 0; i < N; i++)
    {
        if (table[i])
        {
            return false;
        }
    }
    return true;
}

void destroyHashTable()
{
    for (int i = 0; i < N; i++)
    {
        deleteList(&table[i]);
    }
}

void deleteList(node **list)
{

    if (*list == NULL)
    {
        return;
    }
    else if ((*list)->next == NULL)
    {
        free(*list);
        *list = NULL;
    }

    else
    {
        node *tmp;
        tmp = *list;
        *list = tmp->next;
        free(tmp);
        deleteList(list);
    }
}