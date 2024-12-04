#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100

int array[MAX];
int top1 = -1;
int top2 = MAX;

void pushUndo(int value) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow! Cannot push into Undo stack.\n");
    } else {
        array[++top1] = value;
        printf("Pushed %d into Undo stack.\n", value);
    }
}

void pushRedo(int value) {
    if (top1 + 1 == top2) {
        printf("Stack Overflow! Cannot push into Redo stack.\n");
    } else {
        array[--top2] = value;
        printf("Pushed %d into Redo stack.\n", value);
    }
}

int popUndo() {
    if (top1 == -1) {
        printf("Undo stack is empty!\n");
        return -1;
    } else {
        int value = array[top1--];
        printf("Popped %d from Undo stack.\n", value);
        return value;
    }
}

int popRedo() {
    if (top2 == MAX) {
        printf("Redo stack is empty!\n");
        return -1;
    } else {
        int value = array[top2++];
        printf("Popped %d from Redo stack.\n", value);
        return value;
    }
}

void peekUndo() {
    if (top1 == -1) {
        printf("Undo stack is empty!\n");
    } else {
        printf("Top of Undo stack: %d\n", array[top1]);
    }
}

void peekRedo() {
    if (top2 == MAX) {
        printf("Redo stack is empty!\n");
    } else {
        printf("Top of Redo stack: %d\n", array[top2]);
    }
}

int main() 
{
    int choice, stack, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push into Undo stack\n");
        printf("2. Push into Redo stack\n");
        printf("3. Pop from Undo stack\n");
        printf("4. Pop from Redo stack\n");
        printf("5. Peek Undo stack\n");
        printf("6. Peek Redo stack\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push into Undo stack: ");
                scanf("%d", &value);
                pushUndo(value);
                break;
            case 2:
                printf("Enter value to push into Redo stack: ");
                scanf("%d", &value);
                pushRedo(value);
                break;
            case 3:
                popUndo();
                break;
            case 4:
                popRedo();
                break;
            case 5:
                peekUndo();
                break;
            case 6:
                peekRedo();
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}