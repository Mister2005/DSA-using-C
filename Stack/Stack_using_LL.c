#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct Stack* createNode(int);
void push(int);
void pop();
void display();
void stacktop();
int data;

struct Stack
{
	int data;
	struct Stack* next;
};

struct Stack *node,*top=NULL,*last=NULL,*temp;

struct Stack* createNode(int info)
{
	struct Stack* node =(struct Stack*) malloc(sizeof(struct Stack));

	node->data=info;
	node->next=NULL;
	return node;
}

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
            case 1: printf("Enter data to push: ");
                    scanf("%d",&data);
                    push(data);
                    break;

            case 2: pop();
                    break;

            case 3: display();
                    break;

            case 4: stacktop();
                    break;

            case 5: exit(0);
                    break;
            default: printf("Invalid choice");
        }
    }while (choice != 5);
}

void push(int info)
{
	    node=createNode(info);
	    if(top==NULL)
	    {
			top=node;
			last=node;
            printf("Pushed element is: %d",top->data);
		}
		else
		{
			node->next=top;
			top=node;
            printf("Pushed element is: %d",top->data);
		}
}

void pop()
{
	temp=top;
	if(top==NULL)
	{
		printf("\n List is Empty");
	}
	else
	{
		printf("\npopped element is: %d",temp->data);
		top=top->next;
		free(temp);
	}
}

void display()
{
	if(top==NULL)
	{
		printf("\n List is Empty");
	}
	else
	{
		temp=top;
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}

void stacktop()
{
    if(top==NULL)
    {
        printf("\n List is Empty");
    }
    else
    {
        printf("\nTop Element is: %d",top->data);
    }
}