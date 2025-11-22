#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;

} Node;

Node *createnode(int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

int main()
{

    Node *A;
    A = NULL;
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = 2;
    temp->next = NULL;
    A = temp;
    Node *newnode = createnode(5);
    Node *temp = A;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
