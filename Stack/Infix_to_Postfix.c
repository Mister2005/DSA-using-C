#include<stdio.h>
#include<conio.h>
#include<ctype.h>

char stack[100];
int tos = -1;

void push(char x)
{
    stack[++tos] = x;
}

char pop()
{
    if(tos == -1)
    return -1;

    else
    return stack[tos--];
}

int priority(char x)
{
    if(x == '(')
    return 0;
    
    if(x == '+' || x == '-')
    return 1;
    
    if(x == '*' || x == '/')
    return 2;
    
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    
    while(*e != '\0')
    {
        if(isalnum(*e))
        printf("%c ",*e);
        
        else if(*e == '(')
        push(*e);
        
        else if(*e == ')')
        {
            while((x = pop()) != '(')
            printf("%c ", x);
        }
        
        else
        {
            while(priority(stack[tos]) >= priority(*e))
            printf("%c ",pop());
            push(*e);
        }
        e++;
    }

    while(tos != -1)
    {
        printf("%c ",pop());
    }
    return 0;
}