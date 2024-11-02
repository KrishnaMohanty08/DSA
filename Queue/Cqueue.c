#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4

struct queue {
    int front;
    int rear;
    int size;
    int* arr;
};

int isFull(struct queue *q) {
    return (q->rear + 1) % q->size == q->front; // Return 1 if full
}

int isEmpty(struct queue *q) {
    return (q->front == -1); // Return 1 if empty
}

void enqueue(struct queue *q, int x) {
    if (isFull(q)) {
        printf("The Queue is Full\n");
    } else {
        if (isEmpty(q)) {
            q->front = q->rear = 0; // Initialize front and rear
        } else {
            q->rear = (q->rear + 1) % q->size; // Circular increment
        }
        q->arr[q->rear] = x; // Insert element
        printf("Value %d is inserted into the queue\n", x);
    }
}

int dequeue(struct queue *q) {
    if (isEmpty(q)) {
        printf("The Queue is Empty\n");
        return -1; // Return -1 to indicate the queue is empty
    } else {
        int a = q->arr[q->front]; // Get the front value
        if (q->front == q->rear) {
            // Queue becomes empty after this dequeue
            q->front = q->rear = -1;
        } else {
            q->front = (q->front + 1) % q->size; // Circular increment
        }
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
        while(i!=q->rear){
            printf("%d ,",q->arr[i]);
            i=(i+1)%q->size;
        }
        printf("%d",q->arr[i]);
    }
}

int main() {
    struct queue q;
    q.size = MAX_SIZE;
    q.front = q.rear = -1; // Initialize front and rear
    q.arr = (int *)malloc(q.size * sizeof(int)); // Allocate memory for the queue array

    // Check if the queue is empty
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
 
    enqueue(&q, 3);
    enqueue(&q, 231);

    // Check if the queue is empty after dequeue operations
    if (isEmpty(&q)) {
        printf("Queue is Empty\n");
    }
    printf("\n");
    display(&q);

    // Free dynamically allocated memory
    free(q.arr);

    return 0;
}