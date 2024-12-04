#include <stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 100

int tos = -1;
int item;
char stack_string[MAX];
void push(char item);
char pop(void);

int main()
{
    char str[MAX];
    int i;

    printf("Input a string: ");
    scanf("%s",str); 
    for(i=0;i<strlen(str);i++)
        push(str[i]);
    for(i=0;i<strlen(str);i++)
        str[i]=pop();
    printf("Reversed String is: %s\n",str);
    return 0;
}
 
void push(char item)
{
    if(tos == MAX-1)
    {
        printf("\nStack is Overflow !!!\n");
        return;
    }
    tos=tos+1;
    stack_string[tos]=item;
}

char pop()
{
    if(tos == -1)
    {
        printf("\nStack is EMPTY!!!\n");
        return 0;
    }
    item = stack_string[tos];
    tos=tos-1;
    return item;
}