#include <stdio.h>
#include <string.h>

// ==========================================
// 1. Stack Implementation (栈的实现)
// ==========================================
char stack[100];
int top = -1; // top = -1 means the stack is empty

void push(char c)
{
    if (top >= 99)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = c;
}

char pop()
{
    if (top == -1)
    {
        return '\0'; // Return null char if empty (though we check isempty before calling)
    }
    char val = stack[top];
    top--;
    return val;
}

int isempty()
{
    if (top == -1)
    {
        return 1; // True (Empty)
    }
    else
    {
        return 0; // False (Not Empty)
    }
}

// ==========================================
// 2. Helper Function (配对检查)
// ==========================================
// Returns 0 if match, -1 if mismatch
int checksame(char left, char right)
{
    if (left == '(' && right == ')')
        return 0;
    if (left == '[' && right == ']')
        return 0;
    if (left == '{' && right == '}')
        return 0;
    return -1;
}

// ==========================================
// 3. Main Logic
// ==========================================
int main()
{
    char a[100];
    printf("Enter parentheses string: ");
    scanf("%s", a);

    int total = strlen(a);

    for (int i = 0; i < total; i++)
    {
        // Case 1: Left Bracket -> Push
        if (a[i] == '(' || a[i] == '[' || a[i] == '{')
        {
            push(a[i]);
        }
        // Case 2: Right Bracket -> Check & Pop
        else if (a[i] == ')' || a[i] == ']' || a[i] == '}')
        {

            if (isempty())
            {
                printf("Unbalanced! (No opening bracket for %c)\n", a[i]);
                return 1;
            }

            char top_char = pop();

            if (checksame(top_char, a[i]) == -1)
            {
                printf("Unbalanced! (Mismatch: %c and %c)\n", top_char, a[i]);
                return 1;
            }
        }
    }

    // Final Check: Stack must be empty after loop
    if (!isempty())
    {
        printf("Unbalanced! (Left brackets remain in stack)\n");
        return 1;
    }

    printf("Balanced!\n");
    return 0;
}