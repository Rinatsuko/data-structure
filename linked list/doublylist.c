#include <stdio.h>
#include <stdlib.h>

// Definition of Doubly Linked List Node
typedef struct DNode
{
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

struct DNode *head = NULL;
// =================================================

DNode *createNode(int data)
{
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void printList()
{
    DNode *temp = head;
    DNode *last = NULL;

    printf("\n[Forward]:  ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        last = temp;
        temp = temp->next;
    }
    printf("NULL\n");

    if (last != NULL)
    {
        printf("[Backward]: ");
        while (last != NULL)
        {
            printf("%d -> ", last->data);
            last = last->prev;
        }
        printf("NULL\n");
    }
}

void insertAfter(DNode *prevNode, int newData)
{
    if (prevNode == NULL)
    {
        printf("Error: Previous node cannot be NULL\n");
        return;
    }

    DNode *newNode = createNode(newData);
    newNode->data = newData;
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    (newNode->next)->prev = newNode;
    prevNode->next = newNode;
}
void deleteNode(DNode *del)
{
    if (head == NULL || del == NULL)
    {
        return;
    }

    if (head == del)
    {
        head = del->next;
    }

    if (del->next != NULL)
    {
        del->next->prev = del->prev;
    }
    if (del->prev != NULL)
    {
        del->prev->next = del->next;
    }

    free(del);
}

// =============================================

int main()
{
    // Manually building a list for testing: 1 <-> 2 <-> 3
    DNode *node1 = createNode(1);
    DNode *node2 = createNode(2);
    DNode *node3 = createNode(3);

    // Setting up the Global Head
    head = node1;

    // Linking them manually
    node1->next = node2;

    node2->prev = node1;
    node2->next = node3;

    node3->prev = node2;

    printf("Original List:");
    printList();

    printf("\n--- Test 1: Insert 99 after Node 2 ---");
    insertAfter(node2, 99);
    printList();

    printf("\n--- Test 2: Delete Node 2 ---");
    deleteNode(node2); // Notice: simpler call, no "&head" needed
    printList();

    printf("\n--- Test 3: Delete Head (Node 1) ---");
    deleteNode(node1); // This tests if you update the global variable correctly
    printList();

    return 0;
}