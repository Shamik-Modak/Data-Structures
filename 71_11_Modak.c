#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

int evaluatePostfix(char exp[]) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {

        if (isdigit(exp[i])) {
            push(exp[i] - '0');   
        }
        else if (isOperator(exp[i])) {
            int b = pop();
            int a = pop();
            int result;

            switch (exp[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                case '^': result = pow(a, b); break;
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    int choice;
    char expression[MAX];

    while (1) {
        printf("\n--- MENU ---");
        printf("\n1. Evaluate Arithmetic Expression (Postfix)");
        printf("\n2. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter Postfix Expression: ");
                scanf("%s", expression);

                top = -1;  
                printf("Result = %d\n", evaluatePostfix(expression));
                break;

            case 2:
                return 0;

            default:
                printf("\nInvalid Choice!");
        }
    }
}
