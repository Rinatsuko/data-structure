#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    char data;
    struct stack *next;
} stack;
char top(stack **ptr);
char pop(stack **ptr);
void push(stack **ptr, char data);
int isempty(stack **ptr);
char *convert(char string[], int n);
int calculate(char string[]);
int compare_priority(char a, char b);
int main()
{

    return 0;
}

void push(stack **ptr, char data)
{
    stack *temp = (stack *)malloc(sizeof(stack));
    if (temp == NULL)
    {
        return;
    }
    temp->data = data;
    temp->next = *ptr;
    *ptr = temp;
}
int top(stack **ptr)
{
    if (*ptr == NULL)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    char a = (*ptr)->data;
    return a;
}
int pop(stack **ptr)
{
    if (*ptr == NULL)
    {
        printf("Stack Underflow!\n");
        return -1;
    }

    char a = (*ptr)->data;
    stack *temp = (*ptr);
    (*ptr) = (*ptr)->next;
    free(temp);
    return a;
}
int isempty(stack **ptr)
{
    if ((*ptr) == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
char *convert(char string[], int n)
{
    for (int i = 0; i < n; i++)
    {
    }
}
int calculate(char string[]);
