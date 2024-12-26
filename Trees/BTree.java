import java.util.*;

// Node class to represent a node in the binary tree
class Node {
    int data;
    Node left;
    Node right;

    // Constructor to initialize a node with a key
    public Node(int key) {
        data = key;
        left = null;
        right = null;
    }
}

public class BTree {
    public static void main(String[] args) {
        Node root = new Node(1); // Root node with value 1

        root.left = new Node(2); 
        root.right = new Node(3); 
        
        root.left.left = new Node(4); 
        root.left.right = new Node(5); 
        
        root.right.left = new Node(6); 
        root.right.right = new Node(7); 
        
        System.out.println("Root node is: " + root.data);
    }
}
