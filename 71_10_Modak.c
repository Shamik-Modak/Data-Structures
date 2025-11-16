#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (rear == NULL) {    
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("\nInserted %d", x);
}

int dequeue() {
    if (front == NULL) {
        printf("\nQueue Underflow");
        return -1;
    }
    struct node *temp = front;
    int val = temp->data;
    front = front->next;

    if (front == NULL)
        rear = NULL; 

    free(temp);
    return val;
}

void display() {
    struct node *temp = front;
    if (temp == NULL) {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nQueue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n\n--- QUEUE MENU ---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                value = dequeue();
                if (value != -1)
                    printf("\nDequeued: %d", value);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("\nInvalid choice!");
        }
    }
}
