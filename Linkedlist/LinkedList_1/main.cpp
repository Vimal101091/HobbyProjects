#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createList(int arr[], int N)
{

    Node* head = (Node*)malloc(sizeof(Node));
    Node* tail;
    head->data = *arr;
    head->next = NULL;
    tail = head;
    int index = 0;
    while(index < (N - 1)) {
        ++index;
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = arr[index];
        temp->next = NULL;
        tail->next = temp;
        tail = tail->next;
    }
    tail->next = NULL;
    return head;
}

void display(Node** list)
{
    Node* p;
    p = *list;
    while(p) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

void insert(Node** list, int element, int pos)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    Node* p = *list;
    int index = pos - 1;
    if(index == 0) {
        temp->data = element;
        temp->next = *list;
        *list = temp;
    } else {
        for(int i = 0; i < (index - 1); ++i) {
            p = p->next;
        }
        temp->data = element;
        temp->next = p->next;
        p->next = temp;
    }
}

int main(int argc, char** argv)
{
    int array[] = { 2, 3, 4, 5, 6, 7 };
    int size = (sizeof(array) / sizeof(int));
    Node* list;
    list = createList(array, size);
    display(&list);
    insert(&list, 3, 4);
    display(&list);
}
