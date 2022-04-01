#include<stdio.h>
#include<stdlib.h>
# define MAX 5

int rear=-1,front=-1;
typedef struct process{
    int pid,pr,bt;
}job;

job pjob[MAX];

void insert(){
    int pr,pid,bt;
    if(rear==MAX-1){
        printf("OVER-FLOW\n");
    }
    else{
        printf("Enter pid, pr, bt : ");
        scanf("%d%d%d",&pid,&pr,&bt);
        if(rear==-1){
            front++;
            rear++;
        }
        else{
            rear++;
        }
        pjob[rear].pid=pid;
        pjob[rear].pr=pr;
        pjob[rear].bt=bt;
    }
}

void delete(){
    int i, pos=0,max=0;
    if(front==-1){
        printf("Underflow\n");
    }
    else{
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            for(i=front;i<=rear;i++){
                if(pjob[i].pr>max){
                    max=pjob[i].pr;
                    pos=i;
                }
            }
            for(i=pos;i<=rear;i++){
                pjob[i].pid=pjob[i+1].pid;
                pjob[i].pr=pjob[i+1].pr;
                pjob[i].bt=pjob[i+1].bt;
            }
            rear--;
        }
    }
}

void display(){
    if(front==-1){
        printf("The queue is empty\n");
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("pid - %d\tpr - %d\tbt - %d\n",pjob[i].pid,pjob[i].pr,pjob[i].bt);
        }
    }
}

void main(){
    int  ch;
    while(1){
        printf("1.Insert\t2.Delete\t3.Display\n");
        printf("Choose an option to proceed\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: insert();break;
            case 2: delete();break;
            case 3: display();break;
            default: printf("Invalid choice");break;
        }
    }
}
