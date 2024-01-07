#ifndef QUEUE_H
#define QUEUE_H


class Node
{
public:
    int data;
    int prio;
    Node* next;
    Node(int data, int prio, Node* next)
        : data{ data }
        , prio{ prio }
        , next{ next }
    {
    }
};

class Queue
{
public:
    Node* front;
    Node* rear;
    virtual void init(Queue*& q) = 0;
    virtual void enqueue(Queue*& q, int data, int prio) = 0;
    virtual int dequeue(Queue*& q) = 0;
    virtual void display(Queue* q) = 0;
    virtual ~Queue()
    {
    }
};

#endif