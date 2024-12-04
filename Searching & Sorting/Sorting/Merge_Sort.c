#include<stdio.h>
#include<conio.h>
#define MAX 100

void mergeSort(int a[], int lb,int ub);
void merge(int a[], int lb,int mid,int ub);
void main()
{
	int n,i,a[MAX],lb=0,ub;
	printf("Enter Number of Element to be Sort: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
        printf("Enter Element %d: ",i+1);
		scanf("%d",&a[i]);
	}
	ub=n-1;
	mergeSort(a,lb,ub);
	printf("\nSorted Array: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

void mergeSort(int a[], int lb,int ub)
{
	int mid;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		mergeSort(a,lb,mid);
		mergeSort(a,mid+1,ub);
		merge(a,lb,mid,ub);
	}
}

void merge(int a[],int lb,int mid,int ub)
{
	int i=lb,j=mid+1,k=lb,b[MAX];
	while(i<=mid && j<=ub)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	if(i>mid)
	{
		while(j<=ub)
		{
			b[k]=a[j];
			k++;j++;
		}
	}
	else
	{
		while(i<=mid)
		{
			b[k]=a[i];
			k++;i++;
		}
	}
	for(i=lb;i<=ub;i++)
    {
		a[i]=b[i];
    }
}