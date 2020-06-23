#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Implementaion of array based stack

typedef struct _stack
{
    int val;
    struct _stack *next;
} stack;

// Prototypes
stack *push(stack *s, int n);
stack *pop(stack *s);
void pop1(stack **s);

int main(int argc, char **argv)
{
    stack *s = NULL;

    for (int i = 1; i < 5; i++)
    {
        s = push(s, i);
    }

    for (int k = 1; k < 5; k++)
    {
        // s = pop(s);
        pop1(&s);
    }
    return 0;
}

stack *push(stack *s, int n)
{
    // Add an element to the stach
    stack *newNode = calloc(1, sizeof(stack));
    if (!newNode)
        exit(1);

    newNode->val = n;
    if (!s)
    {
        s = newNode;
    }
    else
    {
        newNode->next = s;
    }

    return newNode;
}

stack *pop(stack *s)
{
    // Remove the most recently addend element
    if (!s)
    {
        printf("stact empty");
        exit(1);
    }

    stack *tmp = s;
    s = s->next;
    free(tmp);
    return s;
}

void pop1(stack **s)
{
    // Remove the most recently addend element
    if (!*s)
    {
        printf("stack empty");
        return;
    }
    stack *trav = (*s)->next;
    free(*s);
    *s = trav;
    //return s;
}