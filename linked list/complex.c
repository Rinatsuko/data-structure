#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
Node *Head;
void print(Node *p);
void insert(int data, int index);
void delete(int index);
void menu();
int main()
{
    char choice;
    while (choice != 'd')
    {
        menu();
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':
            print(Head);
            printf("\n");
            break;
        case 'b':
        {
            int data, index;
            printf("enter the data u want to insert:");
            scanf("%d", &data);
            printf("enter the index:");
            scanf("%d", &index);
            insert(data, index);
            break;
        }
        case 'c':
        {
            int index;
            printf("enter the index u want to delete");
            scanf("%d", &index);
            delete(index);
            break;
        }
        case 'd':
            printf("u have quitted the menu");
            goto exit;
        default:
            printf("invalid input,the program will close.");
            return 1;
        }
        printf("list updated!\n");
    }
exit:
    return 0;
}

void insert(int data, int index)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (index == 0)
    {
        temp->next = Head;
        Head = temp;
        return;
    }
    Node *temp1 = Head;
    if (temp1 == NULL)
    {
        printf("Error: List is empty, cannot insert at index %d\n", index);
        free(temp);
        return;
    }

    for (int i = 0; i < index - 1; i++)
    {
        if (temp1->next == NULL)
        {
            printf("Error: Index %d is out of bounds.\n", index);
            free(temp);
            return;
        }
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void print(Node *p)
{
    if (p == NULL)
        return;
    printf("%d ", p->data);
    print(p->next);
}

void delete(int index)
{
    if (index == 0)
    {
        printf("u cant delete the head node!");
        return;
    }
    Node *temp = Head;
    Node *temp1 = Head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    for (int i = 0; i < index; i++)
    {
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    free(temp1);
}
void menu()
{
    printf("**************************************\n");
    printf("*      a:print linked list now       *\n");
    printf("*     b:insert a number in list      *\n");
    printf("*     c:delete a number in list      *\n");
    printf("*          d:exit the menu           *\n");
    printf("**************************************\n");
}
