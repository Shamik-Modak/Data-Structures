#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* createNode(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void insertBegin(int x) {
    struct node *newnode = createNode(x);
    newnode->next = head;
    head = newnode;
}

void insertEnd(int x) {
    struct node *newnode = createNode(x);
    if (head == NULL) {
        head = newnode;
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

void insertPos(int pos, int x) {
    if (pos == 1) {
        insertBegin(x);
        return;
    }
    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("\nInvalid Position");
        return;
    }
    struct node *newnode = createNode(x);
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteBegin() {
    if (head == NULL) return;
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct node *temp = head;
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
    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("\nInvalid Position");
        return;
    }
    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
}

void display() {
    struct node *temp = head;
    if (!temp) {
        printf("\nList Empty");
        return;
    }
    printf("\nList: ");
    while (temp) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void reverseList() {
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

struct node* merge(struct node *h1, struct node *h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    struct node *res = NULL;

    if (h1->data <= h2->data) {
        res = h1;
        res->next = merge(h1->next, h2);
    }
    else {
        res = h2;
        res->next = merge(h1, h2->next);
    }
    return res;
}

void findMiddle() {
    if (!head) {
        printf("\nList empty");
        return;
    }
    struct node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("\nMiddle Element = %d", slow->data);
}

void sortList() {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void detectLoop() {
    struct node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            printf("\nLoop detected!");
            return;
        }
    }
    printf("\nNo Loop Found");
}

void sumData() {
    int sum = 0;
    struct node *temp = head;
    while (temp) {
        sum += temp->data;
        temp = temp->next;
    }
    printf("\nSum of data = %d", sum);
}

void printOddEven() {
    struct node *temp = head;
    int pos = 1;

    printf("\nOdd Position data: ");
    while (temp) {
        if (pos % 2 == 1)
            printf("%d ", temp->data);
        pos++;
        temp = temp->next;
    }

    temp = head;
    pos = 1;
    printf("\nEven Position data: ");
    while (temp) {
        if (pos % 2 == 0)
            printf("%d ", temp->data);
        pos++;
        temp = temp->next;
    }
}

int main() {
    int choice, x, pos;
    struct node *h1 = NULL, *h2 = NULL;

    while (1) {
        printf("\n\n--- SINGLY LINKED LIST MENU ---");
        printf("\n1.Insert Begin\n2.Insert End\n3.Insert Position\n4.Delete Begin\n5.Delete End");
        printf("\n6.Delete Position\n7.Display\n8.Reverse\n9.Merge 2 Lists\n10.Find Middle");
        printf("\n11.Sort\n12.Detect Loop\n13.Sum of Data\n14.Print Odd/Even Position Data\n15.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertBegin(x);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insertEnd(x);
                break;

            case 3:
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &x);
                insertPos(pos, x);
                break;

            case 4: deleteBegin(); break;
            case 5: deleteEnd(); break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePos(pos);
                break;

            case 7: display(); break;

            case 8: reverseList(); break;

            case 9:
                h1 = head;
                printf("Creating second sorted list...\n");
                h2 = createNode(5);
                h2->next = createNode(9);
                h2->next->next = createNode(14);
                head = merge(h1, h2);
                break;

            case 10: findMiddle(); break;

            case 11: sortList(); break;

            case 12: detectLoop(); break;

            case 13: sumData(); break;

            case 14: printOddEven(); break;

            case 15: return 0;

            default: printf("\nInvalid Choice!");
        }
    }
}
