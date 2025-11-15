#include<stdio.h>
#define MAX 50
int q[MAX],front=-1,rear=-1;

void enqueue(){
    int n;
    if(q[rear]==MAX){
        printf("Queue overflow");
    }
    else{
    printf("\nEnter element: ");
    scanf("%d",&n);
    front=0;
    rear++;
    q[rear]=n;
    }
}

void dequeue(){
    if(front>rear||front==-1){
        printf("Queue is empty");
    }
    else{
        printf("\n%d dequeued from the queue",q[front]);
        front++;
    }
}

void display(){
    for(int i=front;i<=rear;i++){
        printf("%d ",q[i]);
    }
}

int main(){
    int res;
    do{
    printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
    printf("\nEnter choice: ");
    scanf("%d",&res);
    switch (res)
    {
    case 1:
        enqueue();
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    }
    }while(res!=4);

}