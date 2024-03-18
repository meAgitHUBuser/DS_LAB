#include<stdio.h>
#include<stdlib.h>
#define max 5
int rb[max];
int front=-1, rear=-1;
void insert(int);
void delete();
void display();
int main(){
    int i,choice,item;
    printf("MENU");
    printf("\n1. Insert and overflow");
    printf("\n2. Delete and underflow");
    printf("\n3. Display");
    printf("\n4. Exit");
    while(1){
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to enter: ");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Enter a valid choice!!!");
                break;
        }
    }
}
void insert(int item){
    if(front==(rear+1)%max){
        printf("\nRing overflow\n");
    }
    else{
        if(front==-1){
            front=rear=0;
        }
        else{
            rear = (rear+1)%max;
        }
        rb[rear]=item;
    }
}
void delete(){
    int item;
    if(front == -1){
        printf("\nRing underflow\n");
    }
    else{
        item=rb[front];
        if(front == rear){
            front=rear=-1;
        }
        else{
            front=(front+1)%max;
        }
        printf("The deleted element is %d",item);
    }
}
void display(){
    int i;
    if(front==-1){
        printf("\nCircular queue is empty\n");
    }
    else{
        printf("\nCircular list contains: \n");
        printf("Front[%d]-> ",front);
        for(i=front;i!=rear;i=(i+1)%max)
            printf("%d  ",rb[i]);
        printf("%d",rb[i]);
        printf(" <-[%d]Rear\n",rear);
    }
}
