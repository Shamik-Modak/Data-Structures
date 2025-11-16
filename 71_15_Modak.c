#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void printRange(struct node* root, int low, int high) {
    if (root == NULL) return;

    if (root->data > low)
        printRange(root->left, low, high);

    if (root->data >= low && root->data <= high)
        printf("%d ", root->data);

    if (root->data < high)
        printRange(root->right, low, high);
}

int main() {
    struct node* root = NULL;
    int n, x, low, high;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("Enter range (low high): ");
    scanf("%d %d", &low, &high);

    printf("Values in range [%d, %d]: ", low, high);
    printRange(root, low, high);

    return 0;
}
