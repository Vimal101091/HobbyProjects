#include <stdio.h>
#include "Queue.h"
int main(int argc, char **argv)
{
    Queue q;
    int size = 7;
    create(&q, size);
    enqueue(&q, 8);
    enqueue(&q, 3);
    enqueue(&q, 5);
    dequeue(&q);
    display(q);
	return 0;
}
