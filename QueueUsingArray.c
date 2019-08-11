#include<stdio.h>
#include<stdlib.h>

//QUEUE node
struct queue{
    int val[100];
    int size;
    int front;
    int back;
};
typedef struct queue queue;

queue* initQueue(){
    queue* q = (queue*)malloc(sizeof(queue*));
    q->size = 0;
    q->front = -1;
    q->back = -1;
    return q;
}
void enqueue(queue* q,int data){
    if(q->front == -1){
        q->front = 0;
        q->back = 0;
        q->size = 1;
        q->val[q->back] = data;
        return;
    }else{
        q->size++;
        q->back++;
        q->val[q->back] = data;
        return;
    }
}

int dequeue(queue* q){
    if(q->size == 0)return -1;
    else{
        q->size--; 
        return q->val[q->front++];
    }
}

void printQueue(queue* q){
    printf("QUEUE is as follows : \n");
    for(int i = q->front;i <= q->back;i++){
        printf("%d <- ",q->val[i]);
    }
    printf("\n");
}


int main (void){
    queue* q = initQueue();

    enqueue(q,12);
    enqueue(q,3);
    enqueue(q,1);
    enqueue(q,6);
    enqueue(q,8);

    dequeue(q);

    enqueue(q,23);
    enqueue(q,32);
    enqueue(q,11);
    enqueue(q,62);
    enqueue(q,81); 

    dequeue(q);   

    printQueue(q);


    return  0;
}