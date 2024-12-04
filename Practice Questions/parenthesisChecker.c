#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int isBalanced(char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1) return 0;
            char topChar = pop();
            if ((exp[i] == ')' && topChar != '(') || 
                (exp[i] == '}' && topChar != '{') || 
                (exp[i] == ']' && topChar != '[')) {
                return 0;
            }
        }
    }
    return top == -1;
}

int main() {
    char expression[MAX];
    printf("Enter an expression: ");
    scanf("%s", expression);
    if (isBalanced(expression)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }
    return 0;
}