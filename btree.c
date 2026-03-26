#include <stdio.h>
#include <stdlib.h>

#define T 2

struct BTreeNode {
    int keys[2*T-1];
    struct BTreeNode *child[2*T];
    int n;
    int leaf;
};

struct BTreeNode* createNode(int leaf) {
    struct BTreeNode* node = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    node->leaf = leaf;
    node->n = 0;
    return node;
}

void traverse(struct BTreeNode* root) {
    int i;
    for (i = 0; i < root->n; i++) {
        if (!root->leaf)
            traverse(root->child[i]);
        printf("%d ", root->keys[i]);
    }
    if (!root->leaf)
        traverse(root->child[i]);
}

int main() {
    struct BTreeNode* root = createNode(1);
    root->keys[0] = 10;
    root->keys[1] = 20;
    root->n = 2;

    printf("B-Tree traversal: ");
    traverse(root);
    return 0;
}

