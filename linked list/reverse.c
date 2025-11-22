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

void reverseIterative();
Node *reverseRecursive(Node *p);
int main()
{
    char choice;
    Head = NULL;

    while (choice != 'd')
    {
        menu();
        printf("Enter choice: ");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'a':
            printf("List currently: ");
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
            printf("u have quitted the menu\n");
            goto exit;

        case 'e':
            reverseIterative();
            printf("List reversed (Iterative)!\n");
            break;

        case 'f':
            if (Head != NULL)
            {
                Head = reverseRecursive(Head);
                printf("List reversed (Recursive)!\n");
            }
            else
            {
                printf("List is empty!\n");
            }
            break;

        default:
            printf("invalid input\n");
        }
    }
exit:
    return 0;
}

void reverseIterative()
{
    if (Head == NULL || Head->next == NULL)
    {
        return;
    }

    Node *prev = NULL;
    Node *current = Head;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    Head = prev;
}
Node *reverseRecursive(Node *p)
{
    Node *newhead = NULL;
    if (p == NULL || p->next == NULL)
    {
        return p;
    }
    newhead = reverseRecursive(p->next);
    (p->next)->next = p;
    p->next = NULL;
    return newhead;
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
    if (Head == NULL)
        return;

    if (index == 0)
    {
        printf("u cant delete the head node! (per your logic)\n");
        return;
    }
    Node *temp = Head;
    Node *temp1 = Head;
    for (int i = 0; i < index - 1; i++)
    {
        if (temp->next == NULL)
            return;
        temp = temp->next;
    }
    Node *target = temp->next;
    if (target != NULL)
    {
        temp->next = target->next;
        free(target);
    }
}

void menu()
{
    printf("\n**************************************\n");
    printf("* a: print linked list now      *\n");
    printf("* b: insert a number            *\n");
    printf("* c: delete a number            *\n");
    printf("* e: Reverse (Iterative)        *\n");
    printf("* f: Reverse (Recursive)        *\n");
    printf("* d: exit the menu              *\n");
    printf("**************************************\n");
}