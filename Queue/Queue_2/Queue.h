
#include <stdlib.h>

typedef struct node {
    int value;
    int prio;
    struct node* next;
} Node;

struct PrioQueue {
    Node* front;
    Node* rear;
};

void init(PrioQueue* q)
{
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(PrioQueue* q, int value, int prio)
{
    Node* t = (Node*)malloc(sizeof(Node));
    t->value = value;
    t->prio = prio;
    t->next = NULL;
    if(q->front == NULL && q->rear == NULL) {
        q->front = q->rear = t;
        return;
    } else if(t->prio >= q->front->prio) {
        t->next = q->front;
        q->front = t;
        return;
    } else {
        Node* p = q->front;
        while(p->next != NULL && prio >= p->prio)
            p = p->next;
        if(p->next == NULL) {
            p->next = t;
            q->rear = t;
            return;
        }
        t->next = p->next;
        p->next = t;
    }
}

int dequeue(PrioQueue* q)
{
    int x;
    if(q->front == q->rear) {
        printf("Queue is full");
        return -1;
    }
    x = q->front->value;
    q->front = q->front->next;
    return x;
}

void display(PrioQueue q)
{
    Node* t = q.front;
    while(t != NULL) {
        printf("%d\n", t->value);
        t = t->next;
    }
}
