#include <iostream>
#include "Queue.h"

class UnorderedQueue : public Queue
{
    virtual void init(Queue*& q) override
    {
        q->front = NULL;
        q->rear = NULL;
    }

    virtual void enqueue(Queue*& q, int data, int prio) override
    {
        Node* t = new Node(data, prio, NULL);
        if(q->front == NULL && q->rear == NULL) {
            q->front = q->rear = t;
            return;
        }
        q->rear->next = t;
        q->rear = q->rear->next;
    }

    virtual int dequeue(Queue*& q) override
    {
        int x;
        if(q->front == q->rear) {
            std::cout << "Queue is full" << std::endl;
            return -1;
        }
        x = q->front->data;
        q->front = q->front->next;
        return x;
    }

    virtual void display(Queue* q) override
    {
        Node* t = q->front;
        while(t) {
            std::cout << t->data << std::endl;
            t = t->next;
        }
    }
};

