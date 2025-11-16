#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int val) {
    struct node *t = (struct node*)malloc(sizeof(struct node));
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


void inorder(struct node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}


void BFS(struct node *root) {
    if (root == NULL) return;

    struct node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }
}


void mirror(struct node *root) {
    if (root == NULL) return;
    struct node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}


struct node* parent(struct node* root, int val) {
    if (root == NULL) return NULL;
    if ((root->left && root->left->data == val) ||
        (root->right && root->right->data == val))
        return root;

    if (val < root->data) return parent(root->left, val);
    return parent(root->right, val);
}


void children(struct node* root, int val) {
    if (root == NULL) return;

    if (root->data == val) {
        if (root->left) printf("Left child: %d\n", root->left->data);
        else printf("Left child: NULL\n");

        if (root->right) printf("Right child: %d\n", root->right->data);
        else printf("Right child: NULL\n");
        return;
    }

    if (val < root->data) children(root->left, val);
    else children(root->right, val);
}


void sibling(struct node* root, int val) {
    struct node* p = parent(root, val);
    if (!p) {
        printf("No sibling\n");
        return;
    }
    if (p->left && p->right) {
        if (p->left->data == val) printf("Sibling: %d\n", p->right->data);
        else printf("Sibling: %d\n", p->left->data);
    } else {
        printf("No sibling\n");
    }
}


struct node* grandparent(struct node* root, int val) {
    struct node* p = parent(root, val);
    if (!p) return NULL;
    return parent(root, p->data);
}


void uncle(struct node* root, int val) {
    struct node* gp = grandparent(root, val);
    if (!gp) {
        printf("No uncle\n");
        return;
    }
    struct node* p = parent(root, val);

    if (gp->left && gp->right) {
        if (gp->left->data == p->data)
            printf("Uncle: %d\n", gp->right->data);
        else
            printf("Uncle: %d\n", gp->left->data);
    } else {
        printf("No uncle\n");
    }
}


int main() {
    struct node *root = NULL;
    int choice, val, low, high;

    while (1) {
        printf("\n\n--- BST MENU ---\n");
        printf("1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.BFS\n6.Mirror Tree\n");
        printf("7.Children\n8.Sibling\n9.Parent\n10.Grandparent\n11.Uncle\n12.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                inorder(root);
                break;

            case 3:
                preorder(root);
                break;

            case 4:
                postorder(root);
                break;

            case 5:
                BFS(root);
                break;

            case 6:
                mirror(root);
                printf("Tree mirrored!\n");
                break;

            case 7:
                printf("Enter node value: ");
                scanf("%d", &val);
                children(root, val);
                break;

            case 8:
                printf("Enter node value: ");
                scanf("%d", &val);
                sibling(root, val);
                break;

            case 9:
                printf("Enter node value: ");
                scanf("%d", &val);
                struct node *p = parent(root, val);
                if (p) printf("Parent: %d\n", p->data);
                else printf("No parent\n");
                break;

            case 10:
                printf("Enter node value: ");
                scanf("%d", &val);
                struct node *gp = grandparent(root, val);
                if (gp) printf("Grandparent: %d\n", gp->data);
                else printf("No grandparent\n");
                break;

            case 11:
                printf("Enter node value: ");
                scanf("%d", &val);
                uncle(root, val);
                break;

            case 12:
                return 0;
        }
    }
}
