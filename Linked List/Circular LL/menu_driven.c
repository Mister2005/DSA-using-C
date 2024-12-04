#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void deleteByValue(int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head, *prev = NULL;
    while (temp->data != value) {
        if (temp->next == head) {
            printf("Value not found\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp == head && temp->next == head) {
        head = NULL;
    } else if (temp == head) {
        struct Node *last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = head->next;
        head = head->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    printf("List elements: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

int main() {
    int choice, value;
    do {
        printf("\n1. Insert at End\n2. Delete by Value\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteByValue(value);
            break;
        case 3:
            displayList();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}