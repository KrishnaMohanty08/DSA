#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Define maximum size of the queue

struct queue {
    int front;
    int rear;
    int size;
    int* arr;
};

int isFull(struct queue *q) {
    return (q->rear == q->size - 1);
}

int isEmpty(struct queue *q) {
    return (q->front > q->rear);
}

void enqueue(struct queue *q, int x) {
    if (isFull(q)) {
        printf("Queue is Full\n");
    } else {
        if (q->front == -1) {
            q->front = 0; // Initialize front if this is the first element
        }
        q->rear++;
        q->arr[q->rear] = x;
        printf("Value %d is inserted into the queue\n", x);
    }
}

int dequeue(struct queue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty\n");
        return -1; // Return -1 to indicate the queue is empty
    } else {
        int a = q->arr[q->front];
        q->front++;
        printf("Value %d is dequeued from the queue\n", a);
        return a; // Return the dequeued value
    }
}
void display(struct queue *q){
    int i=q->front;
    if(isEmpty(q)){
        printf("Queue is Empty");
    }
    else {
        while(i<q->rear){
            printf("%d ,",q->arr[i]);
            i++;
        }
        printf("%d",q->arr[i]);
    }
}

int main() {
    struct queue q;
    q.size = MAX_SIZE;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    if (isEmpty(&q)) {
        printf("Queue is Empty\n");
    }

    // Enqueue some values
    enqueue(&q, 3);
    enqueue(&q, 23);
    enqueue(&q, 5);
    enqueue(&q, 263);
    // Dequeue values
    dequeue(&q);
    dequeue(&q);
 
    display(&q);

    // Check if the queue is empty after dequeue operations
    if (isEmpty(&q)) {
        printf("Queue is Empty\n");
    }

    // Free dynamically allocated memory
    free(q.arr);

    return 0;
}