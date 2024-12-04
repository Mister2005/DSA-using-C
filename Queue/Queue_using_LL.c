#include<stdio.h>
#include<stdlib.h>

struct Queue* createNode(int);
void enQueue(int);
void display();
void deQueue();
void queueFront();
void queueRear();

struct Queue
{
    int data;
    struct Queue* next;
};

struct Queue* node,*f=NULL,*r=NULL,*temp=NULL;

struct Queue* createNode(int info)
{
    struct Queue* node = (struct Queue*)malloc(sizeof(struct Queue));

    node->data=info;
    node->next=NULL;
    return node;
}

void main()
{
	int data,choice,location;
    do
    {
	printf ("\n---LINKED LIST---\n1.EnQueue\n2.DeQueue\n3.QueueFront\n4.QueueRear\n5.Display\n6.Exit\n-----------------\n");
	printf("\n Enter Choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("\n Enter Data to add in Queue: ");
			scanf("%d",&data);
			enQueue(data);
			break;
		case 2: deQueue();
			break;
		case 3: queueFront();
			break;
		case 4:queueRear();
			break;
        case 5: display();
            break;
		case 6: exit(0);
			break;
	}
    }while(choice!=6);
}

void enQueue(int info)
{
      node=createNode(info);
      if(f==NULL)
      {
		f=node;
		r=node;
      }
      else
      {
		r->next=node;
		r=node;
      }
}

void deQueue()
{
    if(f==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        temp=f;
        printf("Dequeued element is: %d",temp->data);
        f=f->next;
        free(temp);
    }
}

void queueFront()
{
    if(f==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        printf("Queue Front is: %d",f->data);
    }
}

void queueRear()
{
    if(f==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        printf("Queue Rear is: %d",r->data);
    }
}

void display()
{
    if(f==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        temp=f;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}