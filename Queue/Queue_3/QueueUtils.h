#include "UnorderedQueue.h"
#include "PrioQueue.h"

void init(Queue*& q)
{
    q->init(q);
}

void enqueue(Queue*& q, int data, int prio)
{

    q->enqueue(q, data, prio);
}

int dequeue(Queue*& q)
{
    return q->dequeue(q);
}

void display(Queue* q)
{
    q->display(q);
}
