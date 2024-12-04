#include<stdio.h>
#include<string.h>
#include<conio.h>

void printArray(int* A,int n);
void bubbleSort(int* A,int n);

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
    bubbleSort(A,n);
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

void bubbleSort(int* A,int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("Working on pass no. %d.....\n", i+1);
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            return 0;
        }
    }
}