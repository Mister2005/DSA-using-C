#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct Node
{
	int data;
	struct Node *prev, *next;
};
struct Node *node, *list = NULL, *last = NULL, *temp, *p, *q;
void AddAtStart(int info);
void AddAtEnd(int info);
void DeleteAtStart();
void DeleteAtEnd();
int Search(int info);
int SearchAndDelete(int info);
void DisplayListF();
void DisplayListB();
void AddAtPosition(int info);
struct Node *CreateNode(int info);
int count = 0;
void main()
{
	int data, location, choice;
	do
	{
		printf("\n1.AddatFront\n2.Add at End\n3.Delete At Begin\n4.DeleteAtEnd\n5.InsertAtPosition\n6.Search\n7.SearchAndDelete\n8.Exit");
		printf("\nEnter Choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter Data to add in Node:\n ");

			scanf("%d", &data);
			AddAtStart(data);
			count++;
			printf("displayed forward ");
			DisplayListF();
			printf("\ndisplayed backward ");
			DisplayListB();
			printf("\n Total Nodes in the list=%d", count);
			break;

		case 2:
			printf("Enter Data to add in Node: ");

			scanf("%d", &data);
			AddAtEnd(data);
			count++;
			printf("displayed forward ");
			DisplayListF();
			printf("\ndisplayed backward ");
			DisplayListB();
			printf("\nTotal Nodes in the list=%d", count);
			break;

		case 3:
			printf("deleting the first Node: ");
			DeleteAtStart(data);
			count--;
			printf("displayed forward ");
			DisplayListF();
			printf("\ndisplayed backward ");
			DisplayListB();
			printf("\nTotal Nodes in the list=%d", count);
			break;

		case 4:
			printf("\ndeleting the last Node: ");
			DeleteAtEnd(data);
			count--;
			printf("displayed forward ");
			DisplayListF();
			printf("\ndisplayed backward ");
			DisplayListB();
			printf("\nTotal Nodes in the list=%d", count);
			break;

		case 5:
			printf("Enter Data to add in Node: ");

			scanf("%d",&data);
			AddAtPosition(data);
			count++;
			printf("displayed forward ");
			DisplayListF();
			printf("\ndisplayed backward ");
			DisplayListB();
			printf("\nTotal Nodes in the list=%d", count);
			break;

		case 6:
			printf("Enter Data to search in Node: ");

			scanf("%d", &data);
			location = Search(data);
			printf("displayed forward ");
			DisplayListF();
			printf("\ndisplayed backward ");
			DisplayListB();
			if(location!=0)
			{
			printf("\nThe element %d found at %d position", data,location);
			}
			else
			{
				printf("\n Element not present in the list");
			}
			printf("\nTotal Nodes in the list=%d", count);
			break;

		case 7:
			printf("Enter Data to delete: ");

			scanf("%d", &data);
			location = SearchAndDelete(data);
			count++;
			printf("\nDisplayed forward ");
			DisplayListF();
			printf("\ndisplayed backward ");
			DisplayListB();
			if(location!=0)
			{
			printf("\nThe element %d found at %d position",data,location);
			}
			else
			{
				printf("\n Element not present in the list");
			}

			printf("\nTotal Nodes in the list=%d", count);
			break;

		case 8:
			printf("*****exit*****");
			exit(0);
			break;
		}

	} while (choice != 9);
}
struct Node *CreateNode(int info)
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = info;
	node->prev = NULL;
	node->next = NULL;
	return node;
}
void AddAtStart(int info)
{
	node = CreateNode(info);
	if (list == NULL)
	{
		list = node;
		last = node;
		list->prev = NULL;
		last->next = NULL;
	}
	else
	{
		list->prev = node;
		node->next = list;
		list = node;
		list->prev = NULL;
	}
}
void AddAtEnd(int info)
{
	node = CreateNode(info);
	if (list == NULL)
	{
		list = node;
		last = node;
		list->prev = NULL;
		last->next = NULL;
	}
	else
	{
		last->next = node;
		node->prev = last;
		last = node;
		last->next = NULL;
	}
}
void DeleteAtStart()
{

	if (list == NULL)
	{
		printf("\nList is Empty");
	}
	else
	{
		temp = list;
		list = list->next;
		list->prev = NULL;
		free(temp);
	}
}
void DeleteAtEnd()
{

	if (list == NULL)
	{
		printf("\nList is Empty");
	}
	else
	{
		temp = last;
		last = last->prev;
		last->next = NULL;
		free(temp);
	}
}
int Search(int info)
{
	int flag=0, index=1;
	if (list == NULL)
	{
		printf("\nList is Empty");
	}
	else
	{
		temp = list;

		while (temp != NULL)
		{
			if (temp->data == info)
			{
				flag = 1;
				break;
			}
			temp = temp->next;
			index++;
		}
		if (flag == 1)
		{
			return index;
		}
		else
		{
			return 0;
		}
	}
	return index;
}
void DisplayListF()
{
	if (list == NULL)
	{
		printf("list is empty");
	}
	else
	{
		temp = list;
		while (temp != NULL)
		{
			printf("%d-->", temp->data);
			temp = temp->next;
		}
	}
}
void DisplayListB()
{
	if (list == NULL)
	{
		printf("\n list is empty");
	}
	else
	{
		temp = last;
		while (temp != NULL)
		{
			printf("%d-->", temp->data);
			temp = temp->prev;
		}
	}
}
int SearchAndDelete(int info)
{
	int flag = 0, index = 1;
	if (list == NULL)
	{
		printf("\n list is empty");
	}
	else
	{
		temp = list;
		p = list;
		while (temp != NULL)
		{
			if (temp->data == info)
			{
				flag = 1;
				break;
			}
			p = temp;
			temp = temp->next;
			index++;
		}
		if (flag == 1)
		{
			q = temp->next;
			q->prev=p;
			p->next = q;
			free(temp);
			return index;
		}
		else
		{
			return 0;
		}
	}
	return index;
}
void AddAtPosition(int info)
{
	int i, position;
	printf("Enter the position\n");
	scanf("%d",&position);
	node= CreateNode(info);
	if (position == 1)
	{
		AddAtStart(info);
	}
	else if (position == count + 1)
	{
		AddAtEnd(info);
	}
	else
	{
		temp = list;
		p = list;
		for (i = 1; i < position; i++)
		{
			p = temp;
			temp = temp->next;
		}
		p->next = node;
		node->prev = p;
		node->next = temp;
		temp->prev = node;
	}
}