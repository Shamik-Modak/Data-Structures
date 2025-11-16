#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;


struct Node* createNode(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}


void insertBegin(int val) {
    struct Node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;
}


void insertEnd(int val) {
    struct Node *newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}


void insertPos(int val, int pos) {
    if (pos == 1) {
        insertBegin(val);
        return;
    }
    struct Node *newNode = createNode(val);
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteBegin() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
}


void deleteEnd() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}


void deletePos(int pos) {
    if (pos == 1) {
        deleteBegin();
        return;
    }
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct Node *t = temp->next;
    temp->next = t->next;
    free(t);
}


void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List Empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void reverse() {
    struct Node *prev = NULL, *curr = head, *nextNode = NULL;
    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
}


struct Node* merge(struct Node *h1, struct Node *h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    struct Node *res = NULL;

    if (h1->data < h2->data) {
        res = h1;
        res->next = merge(h1->next, h2);
    } else {
        res = h2;
        res->next = merge(h1, h2->next);
    }
    return res;
}


void findMiddle() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element = %d\n", slow->data);
}


void sortList() {
    if (head == NULL) return;
    struct Node *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}


int detectLoop() {
    struct Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}


void sumNodes() {
    int sum = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }
    printf("Sum of all nodes = %d\n", sum);
}


void printOddEven() {
    struct Node *temp = head;

    printf("Odd data: ");
    while (temp != NULL) {
        if (temp->data % 2 != 0) printf("%d ", temp->data);
        temp = temp->next;
    }

    temp = head;
    printf("\nEven data: ");
    while (temp != NULL) {
        if (temp->data % 2 == 0) printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int choice, val, pos;
    struct Node *h1 = NULL, *h2 = NULL;

    while (1) {
        printf("\n----- SINGLY LINKED LIST MENU -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Display\n");
        printf("8. Reverse List\n");
        printf("9. Find Middle\n");
        printf("10. Sort List\n");
        printf("11. Detect Loop\n");
        printf("12. Sum of Nodes\n");
        printf("13. Print Odd & Even Data\n");
        printf("14. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertBegin(val); 
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;

            case 3:
                printf("Enter value & position: ");
                scanf("%d%d", &val, &pos);
                insertPos(val, pos);
                break;

            case 4: deleteBegin(); break;
            case 5: deleteEnd(); break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePos(pos);
                break;

            case 7: display(); break;
            case 8: reverse(); break;
            case 9: findMiddle(); break;
            case 10: sortList(); break;

            case 11:
                if (detectLoop())
                    printf("Loop detected!\n");
                else
                    printf("No loop.\n");
                break;

            case 12:
                sumNodes();
                break;

            case 13:
                printOddEven();
                break;

            case 14:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
