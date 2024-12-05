#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct 
{
    int array[MAX_SIZE];
    int top1;
    int top2;
}TwoStacks;

void initializeStacks(TwoStacks *stacks) 
{
    stacks->top1 = -1;
    stacks->top2 = MAX_SIZE;
}

void pushStack1(TwoStacks *stacks, int value) 
{
    if (stacks->top1 + 1 == stacks->top2) {
        printf("Stack Overflow! Cannot push to Stack 1.\n");
        return;
    }
    stacks->array[++(stacks->top1)] = value;
}

void pushStack2(TwoStacks *stacks, int value) {
    if (stacks->top1 + 1 == stacks->top2) {
        printf("Stack Overflow! Cannot push to Stack 2.\n");
        return;
    }
    stacks->array[--(stacks->top2)] = value;
}

int popStack1(TwoStacks *stacks) {
    if (stacks->top1 == -1) {
        printf("Stack Underflow! Stack 1 is empty.\n");
        return -1;
    }
    return stacks->array[(stacks->top1)--];
}

int popStack2(TwoStacks *stacks) {
    if (stacks->top2 == MAX_SIZE) {
        printf("Stack Underflow! Stack 2 is empty.\n");
        return -1;
    }
    return stacks->array[(stacks->top2)++];
}

int peekStack1(TwoStacks *stacks) {
    if (stacks->top1 == -1) {
        printf("Stack 1 is empty.\n");
        return -1;
    }
    return stacks->array[stacks->top1];
}

int peekStack2(TwoStacks *stacks) {
    if (stacks->top2 == MAX_SIZE) {
        printf("Stack 2 is empty.\n");
        return -1;
    }
    return stacks->array[stacks->top2];
}

int main() {
    TwoStacks stacks;
    initializeStacks(&stacks);
    pushStack1(&stacks, 10);
    pushStack1(&stacks, 20);
    pushStack1(&stacks, 30);
    
    pushStack2(&stacks, 100);
    pushStack2(&stacks, 200);
    pushStack2(&stacks, 300);

    printf("Top of Stack 1: %d\n", peekStack1(&stacks));
    printf("Top of Stack 2: %d\n", peekStack2(&stacks));
    
    printf("Popped from Stack 1: %d\n", popStack1(&stacks));
    printf("Popped from Stack 2: %d\n", popStack2(&stacks));

    pushStack1(&stacks, 40);
    printf("New top of Stack 1: %d\n", peekStack1(&stacks));
    return 0;
}