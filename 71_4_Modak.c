#include<stdio.h>
#define MAX 20
int q[MAX],front1=-1,front2=MAX,rear1=-1,rear2=MAX;

void enqueue1(int x){
    if(rear1+1==rear2){
        printf("Queue overflow");
    }
    if(front1 == -1)
        front1 = 0;

    rear1++;
    q[rear1] = x;
}


void enqueue2(int x){
    if(rear2-1==rear1){
        printf("Queue overflow");
    }
    if(front2 == MAX)
        front2 = MAX-1;

    rear2--;
    q[rear2] = x;
}


void dequeue1(){
    if(front1 == -1 || front1 > rear1){
        printf("Queue underflow");
    }
    else{
        
        front1++;
        if(front1 > rear1){
        front1 = rear1 = -1; 
    }
    
    }
}

void dequeue2(){
    if(front2 == MAX || front2 < rear2){
        printf("Queue underflow");
    }
    else{
        front2--;
        if(front2 < rear2){
        front2 = rear2 = MAX;
    }
    }
}

void disp1(){
    for(int i=front1;i<=rear1;i++){
        printf("%d ",q[i]);
    }
    printf("\n");
}

void disp2(){
    for(int i=front2;i>=rear2;i--){
        printf("%d ",q[i]);
    }
    printf("\n");
}

int main(){
    int res;
do{
    printf("\n1.enqueue1\n2.enqueue2\n3.dequeue1\n4.dequeue2\n5.Display1\n6.Display2\n7.Exit\n");
    scanf("%d",&res);
    int value;
    switch (res)
    {
    case 1:
        printf("\nEnter value:");
        scanf("%d",&value);
        enqueue1(value);
        break;
    case 2:
        printf("\nEnter value:");
        scanf("%d",&value);
        enqueue2(value);
        break;    
    case 3:
        dequeue1();
        break;
    case 4:
        dequeue2();
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