//Static Stack using array
#include <stdio.h>

#define MAX_SIZE 10

typedef struct Stack{
    int element[MAX_SIZE];
    int top;
}Stack;

void push(Stack* stack,int data){
    if(stack->top==MAX_SIZE-1){
        printf("Overflow\n");
        return;
    }stack->element[++stack->top]=data;
}
void pop(Stack* stack){
    if(stack->top<=0){
        printf("UnderFlow");
        return;
    }stack->element[--stack->top];
}
int peek(Stack* stack){
    printf("%d\n",stack->element[stack->top]);
}
void isEmpty(Stack* stack){
    if(stack->element[stack->top==0]){
        printf("Empty Stack");
    }return;
}

int main(){
    
    Stack stack;
    stack.top=-1;
    
    push(&stack,56);
    push(&stack,12);
    push(&stack,19);
    push(&stack,14);
    pop(&stack);
    peek(&stack);
    isEmpty(&stack);

    for(int i=stack.top;i>=0;i--){
        printf("%d %d\n",stack.element[i],i);
    }
}