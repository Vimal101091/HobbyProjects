#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front;
    int back;
    int size;
    int* array;
};

void create(Queue* q, int size)
{
    q->front = -1;
    q->back = -1;
    q->array = (int*)malloc(sizeof(int) * size);
    q->size = size;
}

void enqueue(Queue* q, int element)
{
    if(q->back == q->size - 1) {
        printf("Queue is full");
        return;
    }
    q->back++;
    q->array[q->back] = element;
}

int dequeue(Queue* q)
{
    int x;
    if(q->front == q->back) {
        printf("Queue is empty");
        return -1;
    }
    q->front++;
    x = q->array[q->front];
    return x;
}

void display(Queue q)
{
    for(int i = ++q.front; i < q.size; ++i) {
        printf("%d\n", q.array[i]);
    }
}