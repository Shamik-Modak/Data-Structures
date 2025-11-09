#include<stdio.h>
#include<conio.h>
#define MAX 50
int top=-1,stk[MAX];

push(){
    int n;
    if(top==MAX){
        printf("\nStack overflow");
    }
    else{
        printf("Enter element to push: ");
        scanf("%d",&n);
        top++;
        stk[top]=n;
    }
}

pop(){
    if(top==-1){
        printf("\nStack underflow");
    }
    else{
        
        printf("%d popped from the stack\n",stk[top]);
        top--;
    }
}

display(){
    if(top==-1){
        printf("\nStack underflow");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d ",stk[i]);
        }
        printf("\n");
    }
}

int main(){
    int res;
do{
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    scanf("%d",&res);
    
    switch (res)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    default:
        break;
    }
}while(res!=4);
return 0;
}