#include <stdio.h>
#include "Queue.h"

int main(int argc, char **argv)
{
	PrioQueue q;
    init(&q);
    enqueue(&q,4,2);
    enqueue(&q,5,6);
    enqueue(&q,7,5);
    enqueue(&q,3,8);
    display(q);
    dequeue(&q);
    display(q);
	return 0;
}
