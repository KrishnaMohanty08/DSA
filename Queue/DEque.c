#include <stdio.h>
#include <stdlib.h>

struct DeQue{
    int front;
    int rear;
    int size;
    int *arr;
};
int isEmpty(struct DeQue *q) {
    return q->front == -1;
}

int isFull(struct DeQue *q) {
    return (q->rear + 1) % q->size == q->front;
}

void insertAtFront(struct DeQue *q,int x){
    if(isFull(q)){
        printf("The DeQue is Full\n");
    }else {
        if(isEmpty(q)){
            q->front=q->rear=0;
        }else{
            q->front=((q->front-1)%q->size);
        }q->arr[q->front]=x;
    }
    
}

void insertAtRear(struct DeQue *q,int x){
    if(isFull(q)){
        printf("The DeQue is Full\n");
    }else{
        if(isEmpty(q)){
            q->front=q->rear=0;
        }else{
            q->rear=((q->rear+1)%q->size);
        }q->arr[q->rear]=x;
    }

}

void deleteAtRear(struct DeQue *q){
    if(isEmpty(q)){
        printf("The DeQue is Empty\n");
    }else {
        if(q->front==q->rear){
            q->front=q->rear=-1;
        }else {
            q->rear=((q->rear-1)%q->size);
        }
    }
    
}
void deleteAtFront(struct DeQue *q){
    if(isEmpty(q)){
        printf("The DeQue is Empty\n");
    }else {
        int a=q->arr[q->front];
        if(q->front==q->rear){
            q->front=q->rear=-1;
        }else {
            q->front=((q->front+1)%q->size);
            printf("The dequeued element is %d",a);
        }
        
    }
}

void display(struct DeQue *q){
    int i=q->arr[q->front];
    while(i<q->rear){
        printf("%d ,",q->arr[i]);
        if (i == q->rear) break; // Stop when we reach the rear
        i = (i+ 1) % q->size; // Circular increment
    }
    printf("\n");  
}

int main(){
    struct DeQue q;
    q.size = 5; // Example size for the DeQue
    q.front = q.rear = -1; // Initialize as empty
    q.arr = (int *)malloc(q.size * sizeof(int)); // Allocate memory for the array

    // Insert elements at the rear
    insertAtRear(&q, 10);
    insertAtRear(&q, 20);
    insertAtRear(&q, 30);
    display(&q); // Display current elements

    // Insert elements at the front
    insertAtFront(&q, 5);
    insertAtFront(&q, 3);
    display(&q); // Display current elements

    // Delete an element from the front
    deleteAtFront(&q);
    display(&q); // Display current elements

    // Delete an element from the rear
    deleteAtRear(&q);
    display(&q); // Display current elements

    // Free allocated memory
    free(q.arr);
    return 0;

}