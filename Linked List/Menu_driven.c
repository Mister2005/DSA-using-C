#include<stdio.h>
#include<conio.h>
struct Node* createNode(int);
void addAtFront(int);
void addAtEnd(int);
void displayList();
void deleteAtBegin();
void deleteAtEnd();
void insertAtposition(int);
int searchNode(int);
int searchAndDelete(int);
int count=0;

struct Node
{
	int data;
	struct Node* next;
};
struct Node *node,*list=NULL,*last=NULL,*temp=NULL,*p=NULL,*q=NULL;

void main()
{
	int data,choice,location;
    do
    {
	printf ("\n***LINKED LIST**\n1.AddatFront\n2.Add at End\n3.Delete At Begin\n4.DeleteAtEnd\n5.InsertAtPosition\n6.Search\n7.SearchAndDelete\n8.Exit");
	printf("\n Enter Choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("\n Enter Data to add in Node: ");
				scanf("%d",&data);
				addAtFront(data);
				count++;
				displayList();
				printf("\n Total Nodes in the list=%d",count);
				break;
		case 2: printf("\n Enter Data to add in Node: ");
				scanf("%d",&data);
				addAtEnd(data);
				count++;
				displayList();
				printf("\n Total Nodes in the list=%d",count);
				break;
		case 3: deleteAtBegin();
				count--;
				displayList();
				printf("\n Total Nodes in the list=%d",count);
				break;
		case 4: deleteAtEnd();
				count--;
				displayList();
				printf("\n Total Nodes in the list=%d",count);
				break;
		case 5: printf("\n Enter Data to add in Node: ");
				scanf("%d",&data);
				insertAtposition(data);
				count++;
				displayList();
				printf("\n Total Nodes in the list=%d",count);
				break;
		case 6: printf("\n Enter Data to Search in List: ");
				scanf("%d",&data);
				location=searchNode(data);
				displayList();
				printf("\n Total Nodes in the list=%d",count);
				if(location!=0)
					printf("\n %d Element found at Location=%d",data,location);
				else
					printf("\n Element Not Found");
				break;
		case 7: printf("\n Enter Data to Search and delet from List: ");
				scanf("%d",&data);
				location=searchAndDelete(data);
				displayList();
				printf("\n Total Nodes in the list=%d",count);
				if(location!=0)
					printf("\n %d Element found at Location=%d and Deleted successfully",data,location);
				else
					printf("\n Element Not Found");
				break;
		case 8: exit(0);
			break;
		}
	}while(choice!=8);
	getch();

}

struct Node* createNode(int info)
{
	struct Node* node= malloc(sizeof(struct Node));

	node->data=info;
	node->next=NULL;
	return node;
}

void addAtFront(int info)
{
	    node=createNode(info);
	    if(list==NULL)
	    {
			list=node;
			last=node;
		}
		else
		{
			node->next=list;
			list=node;
		}
}

int searchNode(int info)
{
	int index=1,flag=0;
	if(list==NULL)
	{
		printf("\n List is Empty");
		count=0;
	}
	else
	{
		temp=list;
		while(temp!=NULL)
		{
			if(temp->data==info)
			{       
				flag=1;
				break;
			}
			temp=temp->next;
			index++;
		}
	}
	if(flag==1)
		return index;
	else
		return 0;
}

int searchAndDelete(int info)
{
	int index=1,flag=0;
	if(list==NULL)
	{
		printf("\n List is Empty");
		count = 0;
	}
	else
	{
		temp=list;
		p=list;
		while(temp!=NULL)
		{
			if(temp->data==info)
			{
				flag=1;
				break;
			}
			p=temp;
			temp=temp->next;
			index++;
		}
	}
	if(flag==1)
	{
		q=temp->next;
		p->next=q;
		free(temp);
		count--;
		return index;
	}
	else
		return 0;
}

void deleteAtBegin()
{
	temp=list;
	if(list==NULL)
	{
		printf("\n List is Empty");
		count = 0;
	}
	else
	{
		printf("\n%d Node Deleted",temp->data);
		list=list->next;
		free(temp);
	}
}

void addAtEnd(int info)
{
      node=createNode(info);
      if(list==NULL)
      {
		list=node;
		last=node;
      }
      else
      {
		last->next=node;
		last=node;
      }

}

void insertAtposition(int info)
{
	int position,i;
	node=createNode(info);
	printf("\nEnter a position: ");
	scanf("%d",&position);
	temp=list;
	if(position==1)
	    addAtFront(info);
	else if(position==count+1)
	    addAtEnd(info);
	else
	{
		for( i=1;i<position;i++)
		{
			p=temp;
			temp=temp->next;
		}
		p->next=node;
		node->next=temp;
	}
}

void deleteAtEnd()
{
	if(list==NULL)
	{
		printf("\n List is Empty");
		count = 0;
	}
	else if(list->next==NULL)
		list=NULL;
	else
	{       
		temp=list;
		p=list;
		while(temp->next!=NULL)
		{       
			p=temp;
			temp=temp->next;
		}
		free(temp);
		p->next=NULL;
		last=p;
	}
}

void displayList()
{

	printf("\nTotal Nodes in List: %d\n",count);
	if(list==NULL)
	{
		printf("\n List is Empty");
		count = 0;
	}
	else
	{
		temp=list;
		while(temp!=NULL)
		{
			printf("%d-->",temp->data);
			temp=temp->next;
		}
	}
}