//Kumar Ankit
//Circular Queue using arrays
#include<stdio.h>
#define MAX 5

typedef struct{
    int data[MAX]; //holding data
    int f; //front
    int r; //rear
}Cqueue;

int insert(Cqueue *q, int v){
    if(q->f == (q->r+1)%MAX){ //Full condition
        printf("Queue is full\n");
        return 1;
    }
    //Inserting element
    if(q->r == -1){ 
        q->f = q->r = 0;
        q->data[q->r] = v;
    }else{
        q->r = (q->r+1)%MAX;
        q->data[q->r] = v;
    }
    return 0;
}

int delete(Cqueue *q, int *m){
    if(q->f == -1){ //Empty condition
        printf("Queue is empty\n");
        return 1;
    }
    //Deleting element
    if(q->f == q->r){
        *m = q->data[q->f];
        q->f = q->r = -1;
    }else{
        *m = q->data[q->f];
        q->f = (q->f+1)%MAX;
    }
    return 0;
}

void display(Cqueue q){
    int i;
    if (q.f == - 1) //Front is pointing to -1, that is queue is empty
        printf("Queue is empty \n");
    else{
        if(q.f <= q.r){
            i=q.f;
            while(i<=q.r){
                printf("%d ", q.data[i]);
                i++;
            }
        }else{
            i=q.f;
            while(i<MAX){
                printf("%d ", q.data[i]);
                i++;
            }
            i=0;
            while(i<=q.r){
                printf("%d ", q.data[i]);
                i++;
            }
        }
        printf("\n");
    }
}

int main(){
    Cqueue q1;
    q1.f = q1.r = -1;
    printf("Inserting 5 elements : 10, 15, 20, 25, 30 : \n");
    int p = insert(&q1, 10);
    p = insert(&q1, 15);
    p = insert(&q1, 20);
    p = insert(&q1, 25);
    p = insert(&q1, 30);
    printf("Queue is : ");
    display(q1);
    printf("Deleting 1 element : \nQueue is : ");
    int m;
    int q = delete(&q1, &m);
    display(q1);
    printf("Inserting 35 : \nQueue is : ");
    p = insert(&q1, 35);
    display(q1);
    return 0;
}