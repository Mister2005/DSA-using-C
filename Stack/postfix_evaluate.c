#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int tos = -1;
void push(int);

void push(int item) 
{
    if (tos >= MAX - 1) 
    {
        printf("Stack overflow\n");
        return;
    } 
    else 
    {
        stack[++tos] = item;
    }
}

int pop() 
{
    if (tos == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        return stack[tos--];
    }
}

int evaluatePostfix(char *postfix) 
{
    int i = 0;
    while (postfix[i]) 
    {
        if (isdigit(postfix[i])) 
        {
            push(postfix[i] - '0');
        } 
        else 
        {
            int val1 = pop();
            int val2 = pop();
            switch (postfix[i]) 
            {
                case '+': push(val2 + val1); 
                        break;
                case '-': push(val2 - val1); 
                        break;
                case '*': push(val2 * val1); 
                        break;
                case '/': push(val2 / val1); 
                        break;
            }
        }
        i++;
    }
    return pop();
}

int main() 
{
    char postfix[100];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    printf("Result of postfix evaluation: %d\n", evaluatePostfix(postfix));
    return 0;
}