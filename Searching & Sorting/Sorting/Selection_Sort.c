#include<stdio.h>
#include<conio.h>
#define MAX 100

void selectionSort(int a[], int n);
void main()
{
	int n,i,a[MAX];
	printf("Enter Number of Element to be Sort: ");
	scanf("%d",&n);
	printf("\n Enter %d Elements in Array to Sort: ",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\n Elements Before Sorting:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	selectionSort(a,n);
	printf("\n Elements after Sorting:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}



void selectionSort(int a[], int n)
{
	int i,j,min,temp;

	for(i = 0; i < n - 1; i++)
	{
		min=i;
		for(j = i + 1; j < n; j++)
		{
			if(a[min] > a[j])
			min=j;
		}
		if(min != i)
		{
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
}