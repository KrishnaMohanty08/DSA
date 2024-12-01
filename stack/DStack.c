#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

// Creating the node structure
struct node {
    int data;
    struct node* link;
};

// Creating the Stack structure --> this contains the top element
struct Stack {
    struct node* head;
};
    
// Checking if the stack is empty 
bool isEmpty(struct Stack *s) {
    return s->head == NULL;
}
    
// Push an element ---> initiating a newNode ---> newNode is assigned as head and then *head is swapped
void push(struct Stack *s, int data) {
    struct node *newTop = (struct node*)malloc(sizeof(struct node));
    if (newTop == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newTop->data = data;
    newTop->link = s->head;
    s->head = newTop;
}

// Pop the top element
void pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Empty Stack\n");
        return;
    }
    struct node *temp = s->head;
    s->head = s->head->link;
    free(temp);
}

// Peek the top element
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Empty Stack\n");
        return -1; // Returning -1 to indicate an empty stack
    }
    return s->head->data;
}

int main() {
    struct Stack s;
    s.head = NULL;
    
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    
    while (!isEmpty(&s)) {
        printf("%d is the element at the top\n", peek(&s));
        pop(&s);
    }

    return 0;
}
