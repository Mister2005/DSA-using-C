#include<stdio.h>
#include<string.h>
#include<conio.h>

void printArray(int* A,int n);
void insertionSort(int* A,int n);

int main()
{
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter Element %d: ",i+1);
        scanf("%d",&A[i]);
    }
    printArray(A,n);
    insertionSort(A,n);
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

void insertionSort(int* A, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = key;
    }
}