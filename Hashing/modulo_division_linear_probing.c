#include <stdio.h>
#define SIZE 11

int hashTable[SIZE];

void initializeHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1; // -1 indicates an empty slot
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE; // Linear probing
    }
    hashTable[index] = key;
}

void displayHashTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: %d\n", i, hashTable[i]);
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