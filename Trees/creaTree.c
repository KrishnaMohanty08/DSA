#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *left; 
    int data;
    struct node *right;
};

struct node* createTree() {  // Correct return type
    int x;
    struct node *newNode;
    printf("Enter the value of the node :(enter -1 if no value to be inserted)\n");
    scanf("%d", &x);
    if (x == -1) {
        return NULL;  // Return NULL if no node is created
    }
    
    // Allocate memory for the new node and initialize data
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    printf("Creating left child of %d:\n", x);
    newNode->left = createTree();  // Recursively create the left subtree
    printf("Creating right child of %d:\n", x);
    newNode->right = createTree();  // Recursively create the right subtree
    return newNode;
}

void traverseInorder(struct node * node){
    if(node ==NULL){
        return;
    }traverseInorder(node->left);
    printf("%d ",node->data);
    traverseInorder(node->right);
}

void traversePreorder(struct node* node){
    if(node==NULL){
        return;
    }printf("%d ",node->data);
    traversePreorder(node->left);
    traversePreorder(node->right);
}

void traversePostorder(struct node* node){
    if(node==NULL){
        return;
    }traversePostorder(node->left);
    traversePostorder(node->right);
    printf("%d ",node->data);
}
 
struct node* insert(struct node* root,int x){
    if(root==NULL){
        root=malloc(sizeof(struct node));
        root->data=x;
        root->left=root->right=NULL;
        return root;
    }
    if(x <root->data){
        root->left=insert(root->left,x);
    }else if(x>root->data){
        root->right=insert(root->right,x);
    }
    return root;
}

struct node* minValueNode(struct node* node) {
    struct node* current = node;
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct node* deleteNode(struct node* root, int x) {
    if (root == NULL) {
        return root;  // Tree is empty, nothing to delete
    }

    // Traverse the tree to find the node to be deleted
    if (x < root->data) {
        root->left = deleteNode(root->left, x);
    } else if (x > root->data) {
        root->right = deleteNode(root->right, x);
    } else {
        // Node found
        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;  // Return the right child
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;  // Return the left child
        }

        // Case 2: Node with two children
        struct node* temp = minValueNode(root->right);  // Get the inorder successor
        root->data = temp->data;  // Copy the inorder successor's data to this node
        root->right = deleteNode(root->right, temp->data);  // Delete the inorder successor
    }
    return root;  // Return the (potentially unchanged) root pointer
}

struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

struct node* searchMin(struct node* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* searchMax(struct node* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

int main() {
    struct node* root = NULL;
    int choice, value;

    // Create the binary tree
    root = createTree();

    do {
        printf("\nMenu:\n");
        printf("1. Inorder Traversal\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Insert a Node\n");
        printf("5. Delete a Node\n");
        printf("6. Search\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Inorder Traversal: ");
                traverseInorder(root);
                printf("\n");
                break;
            case 2:
                printf("Preorder Traversal: ");
                traversePreorder(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder Traversal: ");
                traversePostorder(root);
                printf("\n");
                break;
            case 4:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted.\n", value);
                break;
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("%d deleted.\n", value);
                break;
            case 6:
                printf("Enter the key to search: ");
                scanf("%d", &value);
                struct node* foundNode = search(root, value);
                if (foundNode) {
                    printf("%d found in the tree.\n", value);
                } else {
                    printf("%d not found in the tree.\n", value);
                }
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}