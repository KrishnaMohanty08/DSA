//sample code
#include <stdio.h>
#include <stdlib.h>

//creating a structure node of DLL
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

//creating a structure to store mata data of the DLL 
//head pointing start  ,tail pointing end  ,total size of the DLL
typedef struct DoubleList {
    Node* head;
    Node* tail;
    int size;
} DoubleList;


//creating the 1st DLL and assigning values =NULL
DoubleList* createDoubleList() {
    //dll is the pointer to DLL struct 
    DoubleList* dll = (DoubleList*)malloc(sizeof(DoubleList));
    dll->head = NULL;
    dll->tail = NULL;
    dll->size = 0;
    return dll;
}

int size(DoubleList* dll) {
    return dll->size;
}

int isEmpty(DoubleList* dll) {
    return dll->size == 0;
}

void printForward(DoubleList* dll) {
    if (dll->head == NULL) {
        printf("Empty List\n");
        return;
    }
    Node* curr = dll->head;
    printf("head --> ");
    while (curr != NULL) {
        printf("%d --> ", curr->data);
        curr = curr->next;
    }
    printf("null\n");
}

void printBackward(DoubleList* dll) {
    if (dll->head == NULL) {
        printf("Empty List\n");
        return;
    }
    Node* curr = dll->tail;
    printf("head --> ");
    while (curr != NULL) {
        printf("%d --> ", curr->data);
        curr = curr->prev;
    }
    printf("null\n");
}

// Function to print the double-linked list in reverse order
void printBackward(DoubleList* dll) {
    // Check if the list is empty
    if (dll->head == NULL) {
        printf("Empty List\n");
        return;
    }

    // Start from the tail of the list
    Node* curr = dll->tail;

    // Print the list in reverse order
    printf("head --> ");
    while (curr != NULL) {
        printf("%d --> ", curr->data);
        curr = curr->prev; // Move to the previous node
    }
    printf("null\n");
}

// Function to insert a new node at the beginning of the list
void insertAtFirst(DoubleList* dll, int data) {
    // Create a new node
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;

    // Check if the list is empty
    if (isEmpty(dll)) {
        // If the list is empty, set the head and tail to the new node
        dll->head = dll->tail = n;
    } else {
        // If the list is not empty, insert the new node at the beginning
        n->next = dll->head;
        dll->head->prev = n;
        dll->head = n;
    }

    // Increment the size of the list
    dll->size++;
}

// Function to insert a new node at the end of the list
void insertAtLast(DoubleList* dll, int data) {
    // Create a new node
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;

    // Check if the list is empty
    if (isEmpty(dll)) {
        // If the list is empty, set the head and tail to the new node
        dll->head = dll->tail = n;
    } else {
        // If the list is not empty, insert the new node at the end
        dll->tail->next = n;
        n->prev = dll->tail;
        dll->tail = n;
    }

    // Increment the size of the list
    dll->size++;
}

// Function to insert a new node at a specific position in the list
void insertAtPos(DoubleList* dll, int data, int pos) {
    // Check if the position is at the beginning or end of the list
    if (pos == 1) {
        // If the position is at the beginning, call the insertAtFirst function
        insertAtFirst(dll, data);
    } else if (pos == dll->size + 1) {
        // If the position is at the end, call the insertAtLast function
        insertAtLast(dll, data);
    } else if (pos > 1 && pos <= dll->size) {
        // Create a new node
        Node* n = (Node*)malloc(sizeof(Node));
        n->data = data;

        // Find the node at the position before the insertion point
        Node* curr = dll->head;
        for (int i = 1; i < pos - 1; i++) {
            curr = curr->next;
        }

        // Insert the new node at the specified position
        n->next = curr->next;
        curr->next->prev = n;
        curr->next = n;
        n->prev = curr;

        // Increment the size of the list
        dll->size++;
    }
}

// Function to delete the first node in the list
void deleteAtFirst(DoubleList* dll) {
    // Check if the list is empty
    if (isEmpty(dll)) {
        printf("List is Already Empty\n");
    } else {
        // Store the first node in a temporary variable
        Node* temp = dll->head;

        // Update the head of the list to the next node
        dll->head = dll->head->next;

        // Free the memory allocated to the deleted node
        free(temp);

        // Decrement the size of the list
        dll->size--;
    }
}

// Function to delete the last node in the list
void deleteAtLast(DoubleList* dll) {
    // Check if the list is empty
    if (isEmpty(dll)) {
        printf("Empty List\n");
    } else if (dll->size == 1) {
        // If the list has only one node, free the memory and update the head and tail
        free(dll->head);
        dll->head = dll->tail = NULL;
        dll->size--;
    } else {
        // Store the last node in a temporary variable
        Node* curr = dll->tail;

        // Update the tail of the list to the previous node
        Node* prev = dll->tail->prev;
        curr->prev = NULL;
       
    }
}
void deleteNodeAfter(DoubleList* dll, int pos) {
    Node* curr = dll->head;
    for (int i = 1; i < pos; i++) {
        curr = curr->next;
    }
    Node* temp = curr->next->next;
    curr->next = temp;
    temp->prev = curr;
    free(curr->next->prev);
    dll->size--;
}

int main() {
    DoubleList* dll = createDoubleList();
    printf("\n\nSize : %d Is Empty : %d\n", size(dll), isEmpty(dll));
    insertAtFirst(dll, 4);
    insertAtFirst(dll, 3);
    insertAtLast(dll, 5);
    insertAtLast(dll, 6);
    insertAtLast(dll, 7);
    insertAtLast(dll, 8);
    insertAtLast(dll, 9);
    printf("\n\nSize : %d Is Empty : %d\n", size(dll), isEmpty(dll));
    printf("\n");
    printForward(dll);
    printf("\n");

    int n;
    printf("Enter the position to delete before the node : ");
    scanf("%d", &n);
    deleteNodeBefore(dll, n);
    printf("\n");
    printForward(dll);

    int n1;
    printf("Enter the position to delete after the node : ");
    scanf("%d", &n1);
    deleteNodeAfter(dll, n1);
    printf("\n");
    printForward(dll);

    return 0;
}