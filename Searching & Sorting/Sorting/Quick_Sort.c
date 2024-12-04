#include<stdio.h>
#include<string.h>
#include<conio.h>

void printArray(int* A,int n);
int partition(int* A, int low, int high);
void QuickSort(int* A, int low, int high);
int n;

int main()
{
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter Element %d: ",i+1);
        scanf("%d",&A[i]);
    }
    printf("\n");
    printf("Original Array: ");
    printArray(A,n);
    printf("\n");
    QuickSort(A,0,n-1);
    printf("\n");
    printf("Sorted Array: ");
    printArray(A,n);
    return 0;
}

void printArray(int* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int* A, int low, int high) 
{
    int pivot = A[high];
    int i = low - 1;
    for (int j = low; j < high; j++) 
    {
        if (A[j] <= pivot) 
        {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp;

    return i + 1;
}

void QuickSort(int* A, int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(A, low, high);
        printf("Sorting Process: ");
        printArray(A,n);
        QuickSort(A, low, pi - 1);
        QuickSort(A, pi + 1, high);
    }
}