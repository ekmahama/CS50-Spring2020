#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node
{
    int val;
    struct node *next;
    /* data */
} node;

int main(int argc, char const *argv[])
{
    node *node1 = malloc(sizeof(node));
    node1->val = 1;
    node *node2 = malloc(sizeof(node));
    node2->val = 2;
    node1->next = node2;
    //node2->next = NULL;

    node node3;
    node2->next = &node3;
    node3.val = 3;
    node node4;
    node3.next = &node4;
    node4.val = 4;
    node4.next = NULL;

    //
    for (node *ptr = node1; ptr != NULL; ptr = ptr->next)
    {
        printf("Val : %i, next : %p\n", ptr->val, ptr->next);
    }

    return 0;
}
