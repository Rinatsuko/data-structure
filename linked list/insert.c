#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *Head = NULL;
void insert(int data, int index);
void detete(int index);
void print();
int main()
{
    int index, data;
    printf("input the index u want to insert a node?\n");
    scanf("%d", &index);
    printf("input the data u want to insert\n");
    scanf("%d", &data);
    printf("the node before ur insert is\n");
    print();
    insert(data, index);
    printf("after ur operation,the node is\n");
    print();
}
void insert(int data, int index)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    Node *temp1 = Head;
    temp->data = data;
    temp->next = NULL;
    if (index == 0)
    {
        temp->next = Head;
        Head = temp;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }
}
void print()
{
    Node *circulation = Head;
    while (circulation != NULL)
    {
        printf("%d ", circulation->data);
        circulation = circulation->next;
    }
}
void delete(int index)
{
    Node *temp = Head;
    for (int i = 0; i < index - 1; i++)
    {
    }
}