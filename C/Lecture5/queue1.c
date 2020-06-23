#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _queue
{
    int val;
    struct _queue *prev;
    struct _queue *next;
} queue;

// Tail and head pointers
queue *head = NULL;
queue *tail = NULL;

// Prototype
void enqueue(queue *tail, int val);
void dequeue(queue *head);

int main(int argc, char **argv)
{

    for (int i = 1; i < 5; i++)
    {
        enqueue(tail, i);
    }

    for (int k = 1; k < 5; k++)
    {
        // s = pop(s);
        dequeue(head);
    }

    return 0;
}
void enqueue(queue *tailm, int val)
{
    queue *q = calloc(1, sizeof(queue));
    q->val = val;
    q->next = NULL;
    q->prev = NULL;

    if (!tailm)
    {
        head = q;
        tail = q;
        return;
    }
    // Store the curren tail in tmp
    queue *tmp = tail;

    // Set the new nodes previous to tmp
    q->prev = tmp;

    // set q to be the noe following tmp
    tmp->next = q;

    // Set q to be the current tail
    tail = q;
}
void dequeue(queue *headm)
{
    if (!headm)
    {
        printf("Queue is empty\n");
        return;
    }
    queue *travPtr = headm;
    head = travPtr->next;
    free(headm);

    // chek if ensure that at least one element is present
    if (head)
        head->prev = NULL;
    return;
}