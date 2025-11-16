#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void reverse(char str[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str)-1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
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
            pop(); // discard '('
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

void infixToPrefix(char infix[], char prefix[]) {
    char reversed[MAX], postfix[MAX];

    strcpy(reversed, infix);

    
    reverse(reversed);

    
    for (int i = 0; reversed[i] != '\0'; i++) {
        if (reversed[i] == '(') reversed[i] = ')';
        else if (reversed[i] == ')') reversed[i] = '(';
    }

    
    top = -1;
    infixToPostfix(reversed, postfix);

    
    strcpy(prefix, postfix);
    reverse(prefix);
}

int main() {
    int choice;
    char infix[MAX], prefix[MAX];

    while (1) {
        printf("\n--- MENU ---");
        printf("\n1. Convert Infix to Prefix");
        printf("\n2. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter Infix Expression: ");
                fgets(infix, MAX, stdin);
                infix[strcspn(infix, "\n")] = '\0';

                infixToPrefix(infix, prefix);

                printf("Prefix Expression: %s\n", prefix);
                break;

            case 2:
                return 0;

            default:
                printf("\nInvalid Choice!");
        }
    }
}
