#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int data;
    struct queue *next;
} queue;
queue *tail = NULL;
void insert(int data);
queue *findhead();
int main()
{
    return 0;
}
void insert(int data)
{
    queue *temp = (queue *)malloc(sizeof(queue));
    temp->data = data;
    temp->next = tail;
    tail = temp;
}
queue *findhead()
{
    queue *temp = tail;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            break;
        }

        temp = temp->next;
    }
    return temp;
}