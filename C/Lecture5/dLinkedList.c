#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *prev;
    struct node *next;

} node;

node *createNewNode(int val);
void deleteList(node **list);
void delNode(int val, node **list);
bool findVal(int val, node *list);
node *addToList(node *newNode, node *list);

int main(int argc, char *argv[])
{
    node *newNode = NULL;
    node *myList = NULL;

    for (int i = 0; i < 5; i++)
    {
        newNode = createNewNode(i + 1);
        myList = addToList(newNode, myList);
    }

    // Find a value in the list
    int searchVal = 4;
    if (findVal(searchVal, myList))
    {
        printf("%i is list\n", searchVal);
    }
    else
    {
        printf("%i is not list\n", searchVal);
    }

    int delnum = 0;
    delNode(delnum, &myList);
    deleteList(&myList);
}

node *createNewNode(int val)
{
    node *newNode = malloc(sizeof(node));
    newNode->val = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

node *addToList(node *newNode, node *list)
{
    if (list == NULL)
    {
        return newNode;
    }
    else
    {
        list->prev = newNode;
        newNode->next = list;
    }
    return newNode;
}

bool findVal(int val, node *list)
{
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->val == val)
        {
            return true;
        }
    }
    return false;
}

void delNode(int val, node **list)
{
    for (node *ptr = *list; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->val == val)
        {
            if (ptr->prev == NULL)
            {
                *list = ptr->next;
                (*list)->prev = NULL;
                free(ptr);
            }
            else if (ptr->next == NULL)
            {
                ptr->prev->next = NULL;
                free(ptr);
            }
            else
            {
                node *tmpP = ptr->prev;
                node *tmpN = ptr->next;
                ptr->prev->next = tmpN;
                ptr->next->prev = tmpP;
                free(ptr);
            }
            return;
        }
    }
    printf("%i not in list\n", val);
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
