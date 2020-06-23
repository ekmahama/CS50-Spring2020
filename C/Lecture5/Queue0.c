#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int CAPACITY = 10;

typedef struct _node
{
    int array[CAPACITY];
    int last;
    int first;

} node;

// Prototype
void enqueue(node *queue, int val);
int dequeue(node *queue);

int main(int argc, char **argv)
{
    node queue;
    queue.first = 0;
    queue.last = 0;

    for (int i = 1; i < 5; i++)
    {
        enqueue(&queue, i);
    }

    for (int k = 1; k < 6; k++)
    {
        int tmp = dequeue(&queue);
    }
    return 0;
}

void enqueue(node *queue, int val)
{
    if (queue->last == CAPACITY)
    {
        printf("Queue is full\n");
        return;
    }
    int ind = (queue->last + queue->first) % CAPACITY;

    queue->array[ind] = val;
    queue->last++;
}

int dequeue(node *queue)
{
    if (queue->last == 0)
    {
        printf("Queue is empty\n");
        exit(1);
    }
    int q = queue->array[queue->first];
    queue->first++;
    queue->last--;
    return q;
}