#include <stdio.h>
#define SIZE 20

int hashTable[SIZE];

void initializeHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1; // -1 indicates an empty slot
    }
}

int hashFunction(int key) {
    int hashValue = (key / 1000) % SIZE; // Subtraction and digit extraction
    return hashValue;
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
    int keys[] = {100111, 100112, 100113, 100114, 100115, 100116, 100117, 100118, 100119};
    int n = sizeof(keys) / sizeof(keys[0]);

    initializeHashTable();

    for (int i = 0; i < n; i++) {
        insert(keys[i]);
    }

    displayHashTable();

    return 0;
}