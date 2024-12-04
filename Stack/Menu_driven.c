#include<stdio.h>
#include<conio.h>
#include<ctype.h>
# define MAX 10
int stack[MAX],tos = -1;
void main()
{
    int choice;
    do
    {
        printf("\n-----Stack-----");
        printf("\n1.Push\n2.Pop\n3.display\n4.Top\n5.exit");
        printf("\n---------------");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push();
            break;

            case 2: pop();
            break;

            case 3: display();
            break;

            case 4: top();
            break;

            case 5: exit(0);

            default: printf("Invalid choice");
        }
    }while (choice != 5);
}

void push()
{
    if(tos == MAX-1)
    {
        printf("\nStack is overflow");
    }
    else
    {
        printf("\nEnter the element to be pushed: ");
        scanf("%d",&stack[++tos]);
        printf("The element is pushed");
    }
}

void pop()
{
    if(tos == -1)
    {
        printf("\nStack is underflow");
    }
    else
    {
        printf("\nPopped element is: %d\n",stack[tos--]);
    }
}

void display()
{
    if(tos == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nStack elements are: \n");
        for(int i=tos;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

void top()
{
    if(tos == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nTop element of the stack is: %d",stack[tos]);
    }
}