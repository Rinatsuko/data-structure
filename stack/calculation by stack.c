#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} stack;

int isempty(stack *ptr)
{
    if (ptr == NULL)
    {
        return 1; // True (Empty)
    }
    else
    {
        return 0; // False (Not Empty)
    }
}
void push(stack **ptr, int value)
{
    // 1. Create a new node
    stack *newNode = (stack *)malloc(sizeof(stack));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = *ptr;
    *ptr = newNode;
}

int pop(stack **ptr)
{

    if (isempty(*ptr))
    {
        printf("Stack Underflow!\n");
        return -1;
    }

    stack *temp = *ptr;
    int poppedValue = temp->data;

    // 3. Move head to the next node
    *ptr = (*ptr)->next;

    // 4. Free the old node
    free(temp);

    return poppedValue;
}

// Peek/Top (Look at top without removing)
// 查看栈顶元素（但不删除）- 转换表达式时非常需要这个函数！
int peek(stack *ptr)
{
    if (isempty(ptr))
    {
        return -1; // Stack is empty
    }
    return ptr->data;
}

// --- Simple Test in Main ---
int main()
{
    stack *operatorStack = NULL; // Head pointer

    // Testing char (ASCII) storage
    printf("Pushing 'A'...\n");
    push(&operatorStack, 'A');

    printf("Pushing '('...\n");
    push(&operatorStack, '(');

    printf("Is empty? %d\n", isempty(operatorStack)); // Should be 0

    printf("Peek top: %c\n", peek(operatorStack)); // Should be '('

    printf("Popped: %c\n", pop(&operatorStack)); // '('
    printf("Popped: %c\n", pop(&operatorStack)); // 'A'

    printf("Is empty? %d\n", isempty(operatorStack)); // Should be 1

    return 0;
}