#include <stdio.h>
#include <stdlib.h>

/* AVL Tree Node */
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

/* Height of node */
int height(struct Node *n) {
    if (n == NULL)
        return 0;
    return n->height;
}

/* Maximum of two numbers */
int max(int a, int b) {
    return (a > b) ? a : b;
}

/* Create new node */
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

/* Right Rotation */
struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

/* Left Rotation */
struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

/* Balance factor */
int getBalance(struct Node *n) {
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

/* Insert into AVL Tree */
struct Node* insert(struct Node* node, int key) {

    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;   // no duplicates

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);

    // LL case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // RR case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // LR case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

/* Main */
int main() {
    struct Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Print final AVL tree root info
    printf("Final AVL Tree:\n");
    printf("Root = %d\n", root->key);

    if (root->left)
        printf("Left child = %d\n", root->left->key);

    if (root->right)
        printf("Right child = %d\n", root->right->key);

    return 0;
}

