#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int usn;
    char name[20];
    char branch [10];
    int sem;
    char phone[12];
}Student;
struct node{
    Student data;
    struct node* link;
};
typedef struct node* NodePtr;
NodePtr getnode(Student item){
    NodePtr newNode = (NodePtr)malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Memory not available!");
        exit(0);
    }
    newNode->data=item;
    newNode->link=NULL;
    return newNode;
}
NodePtr insertFront(Student item, NodePtr first){
    NodePtr newNode = getnode(item);
    newNode->link=first;
    return newNode;
}
NodePtr insertRear(Student item, NodePtr first){
    NodePtr newNode = getnode(item);
    if(newNode==NULL){
        return newNode;
    }
    NodePtr temp = first;
    while(temp->link!=NULL){
        temp = temp->link;
    }
    temp->link = NULL;
    return first;
}
NodePtr deleteFront(NodePtr first){
    if(first==NULL){
        printf("Student list is empty\n");
        return NULL;
    }
    NodePtr temp = first;
    first = first->link;
    free(temp);
    return first;
}
NodePtr deleteRear(NodePtr first){
    if(first==NULL){
        printf("Student list is empty\n");
        return NULL;
    }
    if(first->link=NULL){
        free(first);
        return NULL;
    }
    NodePtr prev = NULL;
    NodePtr temp = first;
    while(temp->link!=NULL){
        prev=temp;
        temp=temp->link;
    }
    free(temp);
    prev->link=NULL;
    return first;
}
void display(NodePtr first){
    if(first==NULL){
        printf("Student list is empty\n");
        return;
    }
    NodePtr temp = first;
    while(temp!=NULL){
        printf("%d\t%s\t%s\t%d\t%s",temp->data.usn,temp->data.name,temp->data.branch,temp->data.sem,temp->data.phone);
        temp=temp->link;
    }
}
int main(){
    NodePtr first = NULL;
    int choice;
    Student item;
    printf("\nMENU");
    printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit");
    while(1){
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter USN, Name, Branch, Semester, Phone Number:\n");
                scanf("%d%s%s%d%s",&item.usn,item.name,item.branch,&item.sem,item.phone);
                first = insertFront(item, first);
                break;
            case 2:
                printf("Enter USN, Name, Branch, Semester, Phone Number:\n");
                scanf("%d%s%s%d%s",&item.usn,item.name,item.branch,&item.sem,item.phone);
                first = insertRear(item, first);
                break;
            case 3:
                first = deleteFront(first);
                break;
            case 4:
                first = deleteRear(first);
                break;
            case 5:
                display(first);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Enter a valid choice!");
                break;
            
        }
    }
}
