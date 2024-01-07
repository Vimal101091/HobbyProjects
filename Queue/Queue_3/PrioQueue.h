#include <iostream>
#include "Queue.h"

class PrioQueue : public Queue
{

    virtual void init(Queue*& q) override
    {
        q->front = NULL;
        q->rear = NULL;
    }

    virtual void enqueue(Queue*& q, int data, int prio)
    {

        Node* t = new Node(data, prio, NULL);
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
