#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int val) {
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data = val;
    t->left = t->right = NULL;
    return t;
}

struct node* insert(struct node* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int findMax(struct node* root) {
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int main() {
    struct node* root = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Minimum = %d\n", findMin(root));
    printf("Maximum = %d\n", findMax(root));

    return 0;
}
