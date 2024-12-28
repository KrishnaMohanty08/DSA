import java.util.*;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Stack;

class Node {// Node class to represent a node in the binary tree
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

class BFS{// Method to perform BFS (Level-Order Traversal)
    public void levelOrderTraversal(Node root){
        if(root==null){
            System.out.println("The tree is empty");
            return;
        }

    Queue<Node> queue=new LinkedList<>();
    queue.add(root);

    while(!queue.isEmpty()){
        Node current=queue.poll();// Dequeue the front node
        System.out.println(current.data);

        if(current.left!=null){
            queue.add(current.left);
        }
        if(current.right!=null){
            queue.add(current.right);
        }
    }
    }
}

class DFS{
    
    public void DFS_traversal(Node root){
        
        System.out.println("Enter the traversal technique\n 1.Preorder 2.Inorder 3.Postorder");
        Scanner sc =new Scanner(System.in);
        int n=sc.nextInt();

        switch(n){
            case 1:
                System.out.println("Preorder Traversal ");
                preorder(root);
                break;
            case 2:
                System.out.println("Inorder Traversal ");
                Inorder(root);
                break;
            case 3:
                System.out.println("Postorder Traversal ");
                postorder(root);
                break;
            }
        }
        public void preorder(Node root){
            if (root==null){
                return;
            }
            System.out.print(root.data);
            preorder(root.left);
            preorder(root.right);
        }
        public void Inorder(Node root){
            if (root==null){
                return;
            }
            Inorder(root.left);
            System.out.print(root.data);
            Inorder(root.right);
        }
        public void postorder(Node root){
            if (root==null){
                return;
            }
            postorder(root.left);
            postorder(root.right);
            System.out.print(root.data);
        }
}

class iterative_DFS {
    public void DFS_traversal(Node root) {
        System.out.println("Enter the traversal technique\n 1.Preorder 2.Inorder 3.Postorder");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        List<Integer> result = new ArrayList<>();
        switch (n) {
            case 1:
                System.out.println("Preorder Traversal ");
                result = Preorder(root);
                break;
            case 2:
                System.out.println("Inorder Traversal ");
                result = Inorder(root);
                break;
            case 3:
                System.out.println("Postorder Traversal ");
                result = Postorder(root);
                break;
            default:
                System.out.println("Invalid choice.");
        }
        System.out.println(result);
    }

    public List<Integer> Preorder(Node root) {
        List<Integer> preorderList = new ArrayList<>();
        if (root == null) {
            return preorderList;
        }

        Stack<Node> stack = new Stack<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            Node current = stack.pop();
            preorderList.add(current.data);

            if (current.right != null) {
                stack.push(current.right);
            }
            if (current.left != null) {
                stack.push(current.left);
            }
        }
        return preorderList;
    }

    public List<Integer> Inorder(Node root) {
        List<Integer> inorderList = new ArrayList<>();
        if (root == null) {
            return inorderList;
        }

        Stack<Node> stack = new Stack<>();
        Node current = root;

        while (current != null || !stack.isEmpty()) {
            while (current != null) {
                stack.push(current);
                current = current.left;
            }

            current = stack.pop();
            inorderList.add(current.data);
            current = current.right;
        }
        return inorderList;
    }

    public List<Integer> Postorder(Node root) {
        List<Integer> postorderList = new ArrayList<>();
        if (root == null) {
            return postorderList;
        }

        Stack<Node> stack1 = new Stack<>();
        Stack<Node> stack2 = new Stack<>();
        stack1.push(root);

        while (!stack1.isEmpty()) {
            Node current = stack1.pop();
            stack2.push(current);

            if (current.left != null) {
                stack1.push(current.left);
            }
            if (current.right != null) {
                stack1.push(current.right);
            }
        }

        while (!stack2.isEmpty()) {
            postorderList.add(stack2.pop().data);
        }
        return postorderList;
    }
}

public class traversal{

    public static void main(String args[]){
        Node root = new Node(1); // Root node with value 1
        root.left = new Node(2); 
        root.right = new Node(3); 
        root.left.left = new Node(4); 
        root.left.right = new Node(5); 
        root.right.left = new Node(6); 
        root.right.right = new Node(7); 
        
        /*System.out.println("Root node is: " + root.data);

        BFS bsf =new BFS();
        bsf.levelOrderTraversal(root);
        
        DFS dfs =new DFS();
        dfs.DFS_traversal(root);
        */
        iterative_DFS dfs = new iterative_DFS();
        dfs.DFS_traversal(root);
    }
}
