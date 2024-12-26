# Tree in Data Structures and Algorithms (DSA)

A **tree** is a hierarchical data structure that consists of nodes connected by edges. It is a special kind of graph with the following characteristics:

1. **Root Node**: The topmost node in the tree, serving as the starting point of the structure.
2. **Parent-Child Relationship**: Each node (except the root) has one parent, and it can have multiple children.
3. **Leaf Nodes**: Nodes with no children are called leaf nodes.
4. **Edges**: The connections between nodes are called edges.
5. **Acyclic**: A tree does not contain any cycles.
6. **Connected**: There is exactly one path between any two nodes.

## Key Properties
- **Number of Edges**: If there are `n` nodes in a tree, it will have `n-1` edges.
- **Levels**: The level of a node is its depth in the tree (starting from the root at level 0).
- **Height**: The height of a tree is the number of edges on the longest path from the root to a leaf.

## Types of Binary Trees
- **Full Binary Tree**:Either has 0 or 2 children
- **Complete Binary Tree**:All levels are completely filled except the last level.The last level has all nodes m left as possible
- **Perfect Binary Tree**:All leaf nodes are at the same level
- **Degenerate Binary Tree**:Every node have a single children
- **Balanced Binary Tree**:Height of the tree at m on log(nodes) 

