#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

typedef struct tries
{
    char university[20];
    struct tries *path[10];
} tries;

tries *trieRoot = NULL;

// Prototype
tries *createNode(char univ[], bool setName);
void addToRoot(char univName[], int univYear, tries *root);
void free_all(tries *curs);
void findEntry(tries *root, int key);

int main()
{
    // create root of the trie
    trieRoot = calloc(1, sizeof(tries));

    //trieRoot->path[10] = {0};

    char *univName;
    int univYear;

    // Promp for value and key
    for (int i = 0; i < 3; i++)
    {
        univName = get_string("Univ name: "); // Value
        univYear = get_int("Year: ");         // key

        // strcpy(univName, "Havard");
        // univYear = 1631;

        // Add this entry to the trie
        addToRoot(univName, univYear, trieRoot);
    }

    findEntry(trieRoot, 2631);

    //destroyTries(trieRoot);
    free_all(trieRoot);
    return 0;
}

tries *createNode(char univ[], bool setName)
{
    // Allocate new trie node
    tries *newTrie = calloc(1, sizeof(tries));

    // *(newTrie)->path = 0, 0, 0, 0;

    // If all key digits is exhausted set name on that node
    if (setName)
    {
        strcpy(newTrie->university, univ);
    }
    return newTrie;
}
void addToRoot(char univName[], int univYear, tries *root)
{

    bool setName = false;    // Variable to indicate when to set name
    int key = univYear % 10; // Get digits of key

    if (!(univYear / 10))
    {
        setName = true;
    }

    // If path is not alreay set by a previous entry
    if (root->path[key] == NULL)
    {
        tries *newNode = createNode(univName, setName);
        root->path[key] = newNode;

        if (setName)
        {
            return;
        }
        addToRoot(univName, (univYear / 10), newNode);
    }
    // if path is set by a previous entry
    else
    {
        if (setName)
        {
            return;
        }
        addToRoot(univName, (univYear / 10), root->path[key]);
    }
}

void free_all(tries *curs)
{
    // recursive case (go to end of trie)
    for (int i = 0; i < 10; i++)
    {
        if (curs->path[i])
        {
            free_all(curs->path[i]);
        }
    }
    // base case
    free(curs);
}

void findEntry(tries *root, int key)
{
    // If key is a single digit , that is end of node
    // Priet the value associated that
    if (!(key / 10))
    {
        if (root->path[key])
        {
            printf("%s\n", root->path[key]->university);
        }
        else
        {
            printf("No such entry exist in tries\n");
        }
        return;
    }
    else
    {
        int k = key % 10; // Get digits of key
        int newKey = key / 10;

        if (root->path[k])
        {
            findEntry(root->path[k], newKey);
        }
        else
        {
            printf("No such entry exist in tries\n");
            return;
        }
    }
}