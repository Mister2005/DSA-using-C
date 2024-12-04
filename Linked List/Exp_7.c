#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

struct Node* mergeLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    if (head1->data < head2->data) {
        head1->next = mergeLists(head1->next, head2);
        return head1;
    } else {
        head2->next = mergeLists(head1, head2->next);
        return head2;
    }
}

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void deletePrimeNodes(struct Node** head) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp != NULL) {
        if (isPrime(temp->data)) {
            if (prev == NULL) {
                *head = temp->next;
                free(temp);
                temp = *head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

void removeAllOccurrences(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == value) {
            if (prev == NULL) {
                *head = temp->next;
                free(temp);
                temp = *head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

void splitEvenOdd(struct Node* head, struct Node** evenList, struct Node** oddList) {
    while (head != NULL) {
        if (head->data % 2 == 0) {
            insertAtEnd(evenList, head->data);
        } 
        else {
            insertAtEnd(oddList, head->data);
        }
        head = head->next;
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* mergedList = NULL;
    struct Node* evenList = NULL;
    struct Node* oddList = NULL;
    int choice, value, n, i;

    do{
        printf("\nMenu:\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Reverse List 1\n");
        printf("4. Reverse List 2\n");
        printf("5. Merge List 1 and List 2\n");
        printf("6. Delete Prime Nodes from Merged List\n");
        printf("7. Remove All Occurrences of a Value from Merged List\n");
        printf("8. Split Merged List into Even and Odd Lists\n");
        printf("9. Print List 1\n");
        printf("10. Print List 2\n");
        printf("11. Print Merged List\n");
        printf("12. Print Even List\n");
        printf("13. Print Odd List\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of elements to insert into List 1: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter value: ");
                    scanf("%d", &value);
                    insertAtEnd(&list1, value);
                }
                break;
            case 2:
                printf("Enter number of elements to insert into List 2: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter value: ");
                    scanf("%d", &value);
                    insertAtEnd(&list2, value);
                }
                break;
            case 3:
                reverseList(&list1);
                printf("List 1 reversed.\n");
                break;
            case 4: 
                reverseList(&list2);
                printf("List 2 reversed.\n");
                break;
            case 5:
                mergedList = mergeLists(list1, list2);
                printf("Lists merged.\n");
                break;
            case 6:
                deletePrimeNodes(&mergedList);
                printf("Prime nodes deleted from merged list.\n");
                break;
            case 7:
                printf("Enter value to remove from merged list: ");
                scanf("%d", &value);
                removeAllOccurrences(&mergedList, value);
                printf("All occurrences of %d removed from merged list.\n", value);
                break;
            case 8:
                splitEvenOdd(mergedList, &evenList, &oddList);
                printf("Merged list split into even and odd lists.\n");
                break;
            case 9:
                printf("List 1: ");
                printList(list1);
                break;
            case 10:
                printf("List 2: ");
                printList(list2);
                break;
            case 11:
                printf("Merged List: ");
                printList(mergedList);
                break;
            case 12:
                printf("Even List: ");
                printList(evenList);
                break;
            case 13:
                printf("Odd List: ");
                printList(oddList);
                break;
            case 14:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while (choice <= 14);
    return 0;
}