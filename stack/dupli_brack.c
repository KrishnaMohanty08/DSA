#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

struct Stack{
    int element[MAX_SIZE];
    int top;
};

void push(struct Stack * stack,int x){
    if(stack->top==MAX_SIZE-1){
        printf("Stack OverFlow\n");
        return ;
    }stack->element[++stack->top]=x;
}
void pop(struct Stack* stack){
    if(stack->top<=0){
        printf("Stack is UnderFlow \n");
        return;
    }printf("%d",stack->top);
    stack->element[--stack->top];
}
void peek(struct Stack* stack){
    printf("%d",stack->top);
}

bool duplicateBrackets(struct Stack* stack){
    if(stack->top=='('){
        while(stack->top!=')'){
            struct Stack* stack.pop();
        }
    }
}