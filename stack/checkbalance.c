#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void pop(char data);
void push(char data);
char top();
int isempty();
int checksame(char a, char b);
int main()
{
    int check;
    char a[100];
    scanf("%s", a);
    char stack[100];
    int total = strlen(a);
    for (int i = 0; i < total; i++)
    {
        if (a[i] == '(')
        {
            push(a[i]); // other situation simliar
        }
        if (a[i] == ')')
        {
            char top = pop();
            check = checksame(top, a[i]); // error3:when meet right element,pop the top and compare;
            if (check == -1)
            {
                printf("unbalanced!");
                return 1;
            }

            // other situation simliar
            int empty = isempty(cheack);
            // judgement
        }
    }
    return 0;
}
char pop()
{
}