#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;      
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            pop(); 
        }
        else if (isOperator(ch)) {
            while (top != -1 && precedence(peek()) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }


    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int main() {
    int choice;
    char infix[MAX], postfix[MAX];

    while (1) {
        printf("\n--- MENU ---");
        printf("\n1. Convert Infix to Postfix");
        printf("\n2. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter Infix Expression: ");
                fgets(infix, MAX, stdin);
                infix[strcspn(infix, "\n")] = '\0';

                infixToPostfix(infix, postfix);

                printf("Postfix Expression: %s\n", postfix);
                top = -1; 
                break;

            case 2:
                return 0;

            default:
                printf("\nInvalid Choice!");
        }
    }
}
