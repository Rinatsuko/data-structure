#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;
node *head = NULL;
void addnode(int index, int data);
void print();
void length(int longer, int shorter);
int main()
{
    return 0;
}
// index means the distance from what we called head,index equals zero means that it will replace the head->next,
void addnode(int index, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    node *temp1 = head;
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = data;
    if (head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        head = temp;
        return;
    }
    if (index == 0)
    {
        temp->next = head;
        temp->prev = head->prev;
        temp->prev->next = temp;
        temp->next->prev = temp;
        head = temp;
        return;
    }
    for (int i = 0; i < index - 1; i++)
    {
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp->prev = temp1;
    temp1->next->prev = temp;
    temp1->next = temp;
}
void length(int longer, int shorter)
{
    node *ptr1 = head;
    node *ptr2 = head;
    longer, shorter = 0;
    do
    {
        ptr1 = ptr1->next->next;
        longer++;
    } while (ptr1 != head);
    do
    {
        ptr2 = ptr->next;
        shorter++;
    } while (ptr2 != head);
    if
}
