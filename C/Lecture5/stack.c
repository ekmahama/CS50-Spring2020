#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Implementaion of array based stack

int const CAPACITY = 10;

typedef struct _stack
{
    int elements[CAPACITY];
    int top;
} stack;

// Prototypes
void push(stack *s, int n);
void pop(stack *s);

int main(int argc, char **argv)
{
    stack s;
    s.top = 0;

    for (int i = 1; i < 5; i++)
    {
        push(&s, i);
    }

    for (int k = 1; k < 5; k++)
    {
        pop(&s);
    }
    return 0;
}

void push(stack *s, int n)
{
    // Add an element to the stach
    s->elements[s->top] = n;
    s->top++;
    return;
}

void pop(stack *s)
{
    // Remove the most recently addend element
    s->elements[s->top - 1] = 0;
    s->top--;
    return;
}