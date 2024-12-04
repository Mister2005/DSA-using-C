#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data) root->left = insertNode(root->left, value);
    else if (value > root->data) root->right = insertNode(root->right, value);
    return root;
}

struct Node *minValueNode(struct Node *node) {
    struct Node *current = node;
    while (current && current->left != NULL) current = current->left;
    return current;
}

struct Node *deleteNode(struct Node *root, int value) {
    if (root == NULL) return root;
    if (value < root->data) root->left = deleteNode(root->left, value);
    else if (value > root->data) root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct Node *searchNode(struct Node *root, int value) {
    if (root == NULL || root->data == value) return root;
    if (value < root->data) return searchNode(root->left, value);
    return searchNode(root->right, value);
}

int main() {
    struct Node *root = NULL;
    int choice, value;

    do {
        printf("\n1. Insert Node\n2. Search Node\n3. Delete Node\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insertNode(root, value);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            struct Node *result = searchNode(root, value);
            if (result != NULL) printf("Node found: %d\n", result->data);
            else printf("Node not found\n");
            break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Node deleted if existed.\n");
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