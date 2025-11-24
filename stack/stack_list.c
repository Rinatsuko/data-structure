#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int data;
    struct stack *next;
} stack;
int top(stack **ptr);
int pop(stack **ptr);
void push(stack **ptr, int data);
int isempty(stack **ptr);
void print(stack **ptr);
int main()
{
    stack *head = NULL; // Initialize the stack pointer to NULL
    int choice, val;

    printf("\n=== Stack Debugging Menu ===\n");
    printf("1. Push (Add element)\n");
    printf("2. Pop  (Remove element)\n");
    printf("3. Top  (View top element)\n");
    printf("4. Print (View all elements)\n");
    printf("5. Check if Empty\n");
    printf("6. Exit\n");

    while (1) // Infinite loop for continuous testing
    {
        printf("\nEnter choice: ");
        // Note: The space before %d handles newline characters from previous inputs
        if (scanf("%d", &choice) != 1)
        {
            // Handle case where user types a letter instead of a number
            while (getchar() != '\n')
                ; // Clear buffer
            continue;
        }

        switch (choice)
        {
        case 1: // Push
            printf("Enter value to push: ");
            scanf("%d", &val);
            // NOTICE: We pass &head because push expects (stack **)
            push(&head, val);
            printf(">> %d pushed to stack.\n", val);
            break;

        case 2: // Pop
            // We check empty here solely to avoid printing the return value if it failed
            // (Though your pop function handles the error message printing itself)
            if (!isempty(&head))
            {
                val = pop(&head);
                printf(">> Popped value: %d\n", val);
            }
            else
            {
                pop(&head); // Just to trigger your "Stack Underflow" message
            }
            break;

        case 3: // Top
            if (!isempty(&head))
            {
                val = top(&head);
                printf(">> Top value is: %d\n", val);
            }
            else
            {
                top(&head); // Trigger error message
            }
            break;

        case 4: // Print
            printf(">> Current Stack: ");
            print(&head);
            printf("\n");
            break;

        case 5: // Is Empty
            if (isempty(&head))
                printf(">> Result: Stack is EMPTY (Returns 1)\n");
            else
                printf(">> Result: Stack is NOT empty (Returns 0)\n");
            break;

        case 6: // Exit
            printf("Exiting... Bye!\n");
            exit(0);

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
// why we use double pointer there?
// we need to change the head pointers address in function we must use pointer to achieve this if we dont return a value
// just pay attention to the function we want to achieve
void push(stack **ptr, int data)
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
        return -1; // Or handle error appropriately
    }
    int a = (*ptr)->data;
    return a;
}
int pop(stack **ptr)
{
    if (*ptr == NULL)
    {
        printf("Stack Underflow!\n");
        return -1;
    }

    int a = (*ptr)->data;
    stack *temp = (*ptr);
    (*ptr) = (*ptr)->next;
    free(temp);
    return a;
}
// notice:when to use double pointer?
// in this case when dont need to change the head pointers value
// we just read them so we dont need to use double pointer
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
void print(stack **ptr)
{
    stack *temp = *ptr;
    if ((*ptr) == NULL)
    {
        printf("stack underflow!");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
