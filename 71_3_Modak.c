#include<stdio.h>
#define MAX 20
int stk[MAX],top1=-1,top2=MAX;

void push1(int x){
    if(top1+1==top2){
        printf("Stack overflow");
    }
    else{
        top1++;
        stk[top1]=x;
    }
}

void push2(int x){
    if(top2-1==top1){
        printf("Stack overflow");
    }
    else{
        top2--;
        stk[top2]=x;
    }
}

void pop1(){
    if(top1==-1){
        printf("Stack underflow");
    }
    else{
        
        top1--;
    
    }
}

void pop2(){
    if(top2==MAX){
        printf("Stack underflow");
    }
    else{
        top2++;
    }
}

void disp1(){
    for(int i=top1;i>=0;i--){
        printf("%d ",stk[i]);
    }
    printf("\n");
}

void disp2(){
    for(int i=top2;i<MAX;i++){
        printf("%d ",stk[i]);
    }
}

int main(){
    int res;
do{
    printf("1.Push1\n2.Push2\n3.Pop1\n4.Pop2\n5.Display1\n6.Display2\n7.Exit\n");
    scanf("%d",&res);
    int value;
    switch (res)
    {
    case 1:
        printf("\nEnter value:");
        scanf("%d",&value);
        push1(value);
        break;
    case 2:
        printf("\nEnter value:");
        scanf("%d",&value);
        push2(value);
        break;    
    case 3:
        pop1();
        break;
    case 4:
        pop2();
        break;
    case 5:
        disp1();
        break;
    case 6:
        disp2();
        break;
    default:
        break;
    }
}while(res!=7);
return 0;
}