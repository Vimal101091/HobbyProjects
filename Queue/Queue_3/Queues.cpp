
#include "QueueUtils.h"
#include <iostream>

int main()
{
    Queue* q = new UnorderedQueue;
    init(q);
    enqueue(q, 2, 0);
    enqueue(q, 3, 0);
    enqueue(q, 4, 0);
    enqueue(q, 6, 0);
    dequeue(q);
    display(q);
    Queue* q1 = new PrioQueue;
    init(q1);
    enqueue(q1, 2, 0);
    enqueue(q1, 3, 0);
    enqueue(q1, 3, 0);
    enqueue(q1, 5, 0);
    enqueue(q1, 4, 0);
    display(q1);

    return 0;
}