#include<stdio.h>
#include<conio.h>
#define MAX 50

int stack[MAX],tos = -1;

int main()
{
    int n;
    printf("Enter an Decimal numaber : ");
    scanf("%d",&n);
    printf("Binary Equivalent is : ");
    DecToBin(n);
    print();
    
    return 0;
}

void DecToBin(int n)
{
    while(n != 0)
    {
        push(n%2);
        n = n/2;
    }
}

void print()
{
    if(isEmpty())
    {
        printf("\nStack is Empty");
        exit(1);
    }
    while(!isEmpty())
    {
        printf("%d",pop());
    }
}

int isFull()
{
    if(tos == MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if(tos == -1)
        return 1;
    else
        return 0;
}

void push(int n)
{
    if(isFull())
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++tos] = n;
    }
}

int pop()
{
    int x;
    if(isEmpty())
    {
            printf("Stack Underflow\n");
            exit(1);
    }
    x = stack[tos--];
    return x;
}