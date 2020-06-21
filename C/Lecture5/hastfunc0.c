#include <stdio.h>
#include <cs50.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    char word[3];
    struct node *next;
} node;

unsigned const int N = 5;
node *hashtable[N];

unsigned long hashstring(char *str);
void addToHashTable(unsigned long key, node *newNode);
node *create(char *val);
void destroyHashTable();
void deleteList(node **list);

int main(int argc, char **argv)
{

    for (int i = 1; i < argc; i++)
    {
        int n = strlen(argv[i]);
        char *name = malloc(n * sizeof(char));
        strcpy(name, argv[i]);

        node *new_n = create(name);

        //unsigned int res = hash1(name);
        unsigned long res1 = hashstring(name);

        addToHashTable(res1, new_n);
        free(name);

        //printf("%s : %i\n", argv[i], res);
        //printf("%s : %li\n", argv[i], res1);
    }
    destroyHashTable();

    return 0;
}

unsigned long hashstring(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;

    return hash % N;
}

node *create(char *val)
{
    node *newNode = malloc(sizeof(node));
    if (!newNode)
    {
        exit(1);
    }
    strcpy(newNode->word, val);
    newNode->next = NULL;
    return newNode;
}

void addToHashTable(unsigned long key, node *newNode)
{
    if (hashtable[key] == NULL)
    {
        hashtable[key] = newNode;
    }
    else
    {
        newNode->next = hashtable[key];
        hashtable[key] = newNode;
    }
}

void destroyHashTable()
{
    for (int i = 0; i < N; i++)
    {
        deleteList(&hashtable[i]);
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