#include <stdio.h>
#include <stdlib.h>
#define SIZE 11

struct Node {
    int data;
    struct Node *next;
};

struct Node *hashTable[SIZE];

void initializeHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void displayHashTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        struct Node *temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int keys[] = {83, 53, 64, 25, 39, 96, 12, 71};
    int n = sizeof(keys) / sizeof(keys[0]);

    initializeHashTable();

    for (int i = 0; i < n; i++) {
        insert(keys[i]);
    }

    displayHashTable();

    return 0;
}