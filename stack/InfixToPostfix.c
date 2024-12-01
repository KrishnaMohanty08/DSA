#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure for linked list
struct Node {
    char data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top, char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = *top;
    *top = node;
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Function to pop an element from the stack
char pop(struct Node** top) {
    if (isEmpty(*top)) {
        return '\0';
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

// Function to peek the top element of the stack
char peek(struct Node* top) {
    if (isEmpty(top)) { 
        return '\0';
    }
    return top->data;
}

// Function to check the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to check if the character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    struct Node* stack = NULL;
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        // If the character is an operand, add it to the postfix expression
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }
        // If the character is '(', push it onto the stack
        else if (infix[i] == '(') {
            push(&stack, infix[i]);
        }
        // If the character is ')', pop and output until '(' is found
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack); // pop '('
        }
        // If the character is an operator
        else if (isOperator(infix[i])) {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(infix[i])) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }
    // Pop all the operators from the stack
    while (!isEmpty(stack)) {
        postfix[k++] = pop(&stack);
    }
    postfix[k] = '\0'; // Null terminate the postfix expression
}

int main() {
    char infix[100], postfix[100];
    int n;

    printf("Enter the number of infix expressions: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter infix expression %d: ", i + 1);
        scanf("%s", infix);  // Read the infix expression
        infixToPostfix(infix, postfix);
        printf("\n");
        printf("Postfix expression %d: %s\n", i + 1, postfix);
    }
    return 0;
}
