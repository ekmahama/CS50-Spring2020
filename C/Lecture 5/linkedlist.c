#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int val;
    struct node *next;
    /* data */
} node;

node *create(int val);
bool findVal(int val, node *list);
node *insertNode(node *newNode, node *list);
void printList(node *list);
void destroyList(node **list);
void deleteList(node **list);
void destroyList2(node *list);

int main(int argc, char const *argv[])
{
    int searchVal = 4;
    node *head = NULL;
    node *newNode = NULL;
    for (int i = 0; i < 5; i++)
    {
        int temp = i + 1;
        //printf("Enter value: ");
        //scanf("%i", &temp);
        newNode = create(temp);
        head = insertNode(newNode, head);
    }
    printList(head);

    if (findVal(searchVal, head))
    {
        printf("%i is in list\n", searchVal);
    }
    else
    {
        printf("%i is not in list\n", searchVal);
    }
    //destroyList2(head);
    //destroyList(&head);
    deleteList(&head);
    printList(head);

    return 0;
}

node *create(int val)
{
    node *newNode = malloc(sizeof(node));
    if (!newNode)
    {
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;
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

node *insertNode(node *newNode, node *list)
{
    if (list == NULL)
    {
        return newNode;
    }

    newNode->next = list;
    return newNode;
}

void printList(node *list)
{
    if (list == NULL)
    {
        exit(1);
    }
    printf("printing list ... \n");
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->val);
    }
}

void destroyList(node **list)
{
    node *tmp;
    while (!list)
    {
        tmp = *list;
        *list = tmp->next;
        free(tmp);
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

    else if ((*list)->next != NULL)
    {
        node *tmp;
        tmp = *list;
        *list = tmp->next;
        free(tmp);
        deleteList(list);
    }
}

void destroyList2(node *list)
{
    // This will leava a dangling pointer
    if (list == NULL)
    {
        return;
    }
    else if (list->next == NULL)
    {
        free(list);
        list = NULL;
    }
    else
    {
        node *tmp;
        tmp = list;
        list = tmp->next;
        free(tmp);
        destroyList2(list);
    }
}