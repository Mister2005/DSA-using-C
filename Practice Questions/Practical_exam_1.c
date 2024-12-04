#include<stdio.h>
#include<conio.h>
#include<ctype.h>
# define MAX 10
int stack1[MAX],stack2[MAX],tos1=-1,tos2=-1;
void main()
{
    int choice,stack_no;
    do
    {
        printf("\n---Game Statistics---");
        printf("\n1.Push\n2.Pop\n3.display\n4.peek\n5.exit");
        printf("\n---------------");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter a choice: ");
                    scanf("%d",&stack_no);
                    if(stack_no == 1)
                        push1();
                    else if(stack_no == 2)
                        push2();
                    else
                        printf("\nInvalid choice");
                        break;
            break;

            case 2: printf("\nEnter a choice: ");
                    scanf("%d",&stack_no);
                    if(stack_no == 1)
                        pop1();
                    else if(stack_no == 2)
                        pop2();
                    else
                        printf("\nInvalid choice");
                        break;
            break;

            case 3: printf("\nEnter a choice: ");
                    scanf("%d",&stack_no);
                    if(stack_no == 1)
                        display1();
                    else if(stack_no == 2)
                        display2();
                    else
                        printf("\nInvalid choice");
                        break;
            break;

            case 4: printf("\nEnter a choice: ");
                    scanf("%d",&stack_no);
                    if(stack_no == 1)
                        peek1();
                    else if(stack_no == 2)
                        peek2();
                    else
                        printf("\nInvalid choice");
                        break;
            break;

            case 5: exit(0);

            default: printf("Invalid choice");
        }
    }while (choice != 5);
}

void push1()
{
    if(tos1 == MAX-1)
    {
        printf("\nStack is overflow");
    }
    else
    {
        printf("\nEnter the element to be pushed in Stack 1: ");
        scanf("%d",&stack1[++tos1]);
        printf("The element is pushed in Stack 1");
    }
}

void push2()
{
    if(tos2 == MAX-1)
    {
        printf("\nStack is overflow");
    }
    else
    {
        printf("\nEnter the element to be pushed in Stack 2: ");
        scanf("%d",&stack2[++tos2]);
        printf("The element is pushed in Stack 2");
    }
}

void pop1()
{
    if(tos1 == -1)
    {
        printf("\nStack is underflow");
    }
    else
    {
        printf("\nPopped element from Stack 1 is: %d\n",stack1[tos1--]);
    }
}

void pop2()
{
    if(tos2 == -1)
    {
        printf("\nStack is underflow");
    }
    else
    {
        printf("\nPopped element from Stack 2 is: %d\n",stack2[tos2--]);
    }
}

void display1()
{
    if(tos1 == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nStack 1 elements are: \n");
        for(int i=tos1;i>=0;i--)
        {
            printf("%d\n",stack1[i]);
        }
    }
}

void display2()
{
    if(tos2 == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nStack 2 elements are: \n");
        for(int i=tos2;i>=0;i--)
        {
            printf("%d\n",stack2[i]);
        }
    }
}

void peek1()
{
    if(tos1 == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\npeek element of the stack 1 is: %d",stack1[tos1]);
    }
}

void peek2()
{
    if(tos2 == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\npeek element of the stack 2 is: %d",stack2[tos2]);
    }
}