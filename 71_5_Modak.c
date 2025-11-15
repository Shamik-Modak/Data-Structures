#include<stdio.h>
#define MAX 50

char stk[MAX];
int top = -1;

void push(char c){
    if(top < MAX-1){
        stk[++top] = c;
    }
}

char pop(){
    if(top >= 0){
        return stk[top--];
    }
    return '\0';
}

int match(char a, char b){
    return (a=='(' && b==')') ||
           (a=='{' && b=='}') ||
           (a=='[' && b==']');
}

int main(){
    char arr[MAX];
    printf("Enter expression: ");
    scanf("%s", arr);

    for(int i=0; arr[i]!='\0'; i++){
        if(arr[i]=='(' || arr[i]=='{' || arr[i]=='['){
            push(arr[i]);
        }
        else if(arr[i]==')' || arr[i]=='}' || arr[i]==']'){
            if(top == -1){        
                printf("NOT MATCHED");
                return 0;
            }
            char temp = pop();
            if(!match(temp, arr[i])){  
                printf("NOT MATCHED");
                return 0;
            }
        }
    }

    if(top == -1)
        printf("MATCHED");
    else
        printf("NOT MATCHED");

    return 0;
}
