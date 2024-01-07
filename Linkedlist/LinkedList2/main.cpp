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

void insertList(Node** list, int element, int pos)
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

void appendList(Node** list, int value)
{

    Node* p = *list;
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    while(p->next) {
        p = p->next;
    }
    p->next = temp;
}

void reverseList(Node** list)
{

    Node* p = *list;
    Node* q = NULL;
    Node* r = NULL;
    while(p!= NULL) {
       r = q;
       q = p;
       p = p->next;
       q->next = r;
    }
    *list = q;
}

void deleteList(Node** list, int pos)
{
    Node* p = *list;
    Node* temp;
    int index = pos - 1;
    if(index == 0) {
        temp = *list;
        *list = temp->next;
        free(temp);
    } else {
        for(int i = 0; i < (index - 1); ++i) {
            p = p->next;
        }
        temp = p->next;
        p->next = temp->next;
        free(temp);
    }
}

int main(int argc, char** argv)
{
    int array[] = { 2, 3, 4, 5, 6, 7 };
    int size = (sizeof(array) / sizeof(int));
    Node* list;
    list = createList(array, size);
    insertList(&list, 3, 1);
    display(&list);
    deleteList(&list, 3);
    printf("\n\n");
    display(&list);
    appendList(&list, 4);
    printf("\n\n");
    display(&list);
    reverseList(&list);
    printf("\n\n");
    display(&list);
}
