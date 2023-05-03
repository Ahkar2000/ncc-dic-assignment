#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* createBalancedTree(int start, int end) {
    if (start > end) {
        return NULL;
    }

    int middle = (start + end) / 2;
    struct Node* node = createNode(middle);

    node->left = createBalancedTree(start, middle - 1);
    node->right = createBalancedTree(middle + 1, end);

    return node;
}

void traverseInOrder(struct Node* node) {
    if (node != NULL) {
        traverseInOrder(node->left);
        printf("%d ", node->data);
        traverseInOrder(node->right);
    }
}

int main() {
    struct Node* root = createBalancedTree(1, 1000);
    traverseInOrder(root);
    return 0;
}
