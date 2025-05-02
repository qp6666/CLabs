#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertManual(Node* root, int value, char direction) {
    if (direction == 'L') {
        if (!root->left)
            root->left = createNode(value);
        else
            insertManual(root->left, value, direction);
    }
    else if (direction == 'R') {
        if (!root->right)
            root->right = createNode(value);
        else
            insertManual(root->right, value, direction);
    }
}

void printTree(Node* root, int space) {
    if (root == NULL)
        return;

    space += 5;
    printTree(root->right, space);
    for (int i = 5; i < space; i++) printf(" ");
    printf("%d\n", root->data);
    printTree(root->left, space);
}

Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void sumOddLevels(Node* root, int level, int* sum) {
    if (root == NULL) return;
    if (level % 2 == 1)
        *sum += root->data;
    sumOddLevels(root->left, level + 1, sum);
    sumOddLevels(root->right, level + 1, sum);
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = NULL;
    int value;
    char dir;

    printf("Enter root value: ");
    scanf_s("%d", &value);
    root = createNode(value);

    while (1) {
        printf("Enter value to insert (or -1 to stop): ");
        scanf_s("%d", &value);
        if (value == -1) break;
        printf("Enter direction from root (L/R): ");
        scanf_s(" %c", &dir);
        insertManual(root, value, dir);
    }

    printTree(root, 0);

    printf("Enter value to delete: ");
    scanf_s("%d", &value);
    root = deleteNode(root, value);

    printTree(root, 0);

    int sum = 0;
    sumOddLevels(root, 1, &sum);
    printf("Sum of odd-level nodes: %d\n", sum);

    freeTree(root);
    return 0;
}