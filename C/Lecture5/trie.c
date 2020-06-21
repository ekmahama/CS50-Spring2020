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

int main()
{
    trieRoot = malloc(sizeof(tries));
    char univName[20];
    int univYear;

    for (int i = 0; i < 2; i++)
    {
        // univName = get_string("Univ name: ");
        // univYear = get_int("Year: ");

        strcpy(univName, "Havard");
        univYear = 1631;

        addToRoot(univName, univYear, trieRoot);
    }
    return 0;
}

tries *createNode(char univ[], bool setName)
{
    tries *newTrie = malloc(sizeof(tries));
    if (setName)
    {
        strcpy(newTrie->university, univ);
    }
    return newTrie;
}
void addToRoot(char univName[], int univYear, tries *root)
{
    bool setName = false;
    int key = univYear % 10;

    if (!(univYear / 10))
    {
        setName = true;
    }
    tries *newNode = createNode(univName, setName);
    if (root->path[key] == NULL)
    {
        root->path[key] = newNode;

        if (setName)
        {
            return;
        }
        addToRoot(univName, (univYear / 10), newNode);
    }
    else
    {
        if (setName)
        {
            return;
        }
        addToRoot(univName, (univYear / 10), root->path[key]);
    }
}