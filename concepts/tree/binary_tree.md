# Complete Guide to Binary Trees

## Table of Contents
1. [Introduction](#introduction)
2. [Basic Concepts](#basic-concepts)
3. [Types of Binary Trees](#types-of-binary-trees)
4. [Basic Operations](#basic-operations)
5. [Tree Traversals](#tree-traversals)
6. [Implementation Examples](#implementation-examples)
7. [Common Algorithms](#common-algorithms)
8. [Binary Search Trees (BST)](#binary-search-trees-bst)
9. [Balanced Trees](#balanced-trees)
10. [Time & Space Complexity](#time--space-complexity)
11. [Common Interview Problems](#common-interview-problems)
12. [Best Practices](#best-practices)

## Introduction

A **binary tree** is a hierarchical data structure where each node has at most two children, referred to as the left child and right child. Binary trees are fundamental in computer science and form the basis for many other data structures and algorithms.

### Why Binary Trees?
- Efficient searching, insertion, and deletion
- Natural recursive structure
- Foundation for databases, file systems, and expression parsing
- Excellent for divide-and-conquer algorithms

## Basic Concepts

### Node Structure
```
    Node
   /    \
 Left   Right
 Child  Child
```

### Key Terminology
- **Root**: The topmost node
- **Leaf**: A node with no children
- **Parent**: A node with children
- **Siblings**: Nodes with the same parent
- **Subtree**: A tree formed by any node and its descendants
- **Height**: Longest path from node to leaf
- **Depth**: Distance from root to node
- **Level**: All nodes at same depth

### Tree Properties
- **Height of tree**: Height of root node
- **Size**: Total number of nodes
- **Diameter**: Longest path between any two nodes

## Types of Binary Trees

### 1. Full Binary Tree
Every node has either 0 or 2 children (no nodes with exactly 1 child).

```
    A
   / \
  B   C
 / \ / \
D  E F  G
```

### 2. Complete Binary Tree
All levels are filled except possibly the last level, which is filled from left to right.

```
    A
   / \
  B   C
 / \ /
D  E F
```

### 3. Perfect Binary Tree
All internal nodes have two children and all leaves are at the same level.

```
    A
   / \
  B   C
 / \ / \
D  E F  G
```

### 4. Balanced Binary Tree
Height difference between left and right subtrees is at most 1 for every node.

### 5. Degenerate Tree
Every internal node has only one child (essentially a linked list).

```
A
 \
  B
   \
    C
     \
      D
```

## Basic Operations

### 1. Insertion
Add a new node to the tree following specific rules.

### 2. Deletion
Remove a node while maintaining tree properties.

### 3. Search
Find a specific value in the tree.

### 4. Traversal
Visit all nodes in a specific order.

## Tree Traversals

### 1. Depth-First Search (DFS)

#### Inorder Traversal (Left → Root → Right)
- Visit left subtree
- Visit root
- Visit right subtree
- **Use case**: Get sorted order in BST

#### Preorder Traversal (Root → Left → Right)
- Visit root
- Visit left subtree  
- Visit right subtree
- **Use case**: Copy/clone tree, prefix expressions

#### Postorder Traversal (Left → Right → Root)
- Visit left subtree
- Visit right subtree
- Visit root
- **Use case**: Delete tree, postfix expressions, calculate directory size

### 2. Breadth-First Search (BFS)

#### Level Order Traversal
Visit nodes level by level from left to right.
- **Use case**: Print tree by levels, shortest path

## Implementation Examples

### Node Class (Python)
```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
```

### Node Class (JavaScript)
```javascript
class TreeNode {
    constructor(val, left = null, right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
```

### Node Struct (C++)
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

### Basic Binary Tree Class (Python)
```python
class BinaryTree:
    def __init__(self):
        self.root = None
    
    def insert(self, val):
        if not self.root:
            self.root = TreeNode(val)
        else:
            self._insert_recursive(self.root, val)
    
    def _insert_recursive(self, node, val):
        # Insert in level-order fashion
        from collections import deque
        queue = deque([self.root])
        while queue:
            current = queue.popleft()
            if not current.left:
                current.left = TreeNode(val)
                return
            elif not current.right:
                current.right = TreeNode(val)
                return
            else:
                queue.append(current.left)
                queue.append(current.right)
```

## Common Algorithms

### 1. Tree Height/Depth
```python
def max_depth(root):
    if not root:
        return 0
    return 1 + max(max_depth(root.left), max_depth(root.right))
```

### 2. Tree Diameter
```python
def diameter(root):
    def helper(node):
        if not node:
            return 0, 0  # height, diameter
        
        left_height, left_diameter = helper(node.left)
        right_height, right_diameter = helper(node.right)
        
        current_height = 1 + max(left_height, right_height)
        current_diameter = max(
            left_diameter,
            right_diameter,
            left_height + right_height
        )
        
        return current_height, current_diameter
    
    return helper(root)[1]
```

### 3. Level Order Traversal
```python
def level_order(root):
    if not root:
        return []
    
    result = []
    queue = deque([root])
    
    while queue:
        level_size = len(queue)
        level = []
        
        for _ in range(level_size):
            node = queue.popleft()
            level.append(node.val)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        result.append(level)
    
    return result
```

### 4. Inorder Traversal (Iterative)
```python
def inorder_iterative(root):
    result = []
    stack = []
    current = root
    
    while stack or current:
        while current:
            stack.append(current)
            current = current.left
        
        current = stack.pop()
        result.append(current.val)
        current = current.right
    
    return result
```

## Binary Search Trees (BST)

A BST is a binary tree where:
- Left subtree values < root value
- Right subtree values > root value
- Both subtrees are also BSTs

### BST Operations

#### Search
```python
def search_bst(root, val):
    if not root or root.val == val:
        return root
    
    if val < root.val:
        return search_bst(root.left, val)
    else:
        return search_bst(root.right, val)
```

#### Insert
```python
def insert_bst(root, val):
    if not root:
        return TreeNode(val)
    
    if val < root.val:
        root.left = insert_bst(root.left, val)
    else:
        root.right = insert_bst(root.right, val)
    
    return root
```

#### Delete
```python
def delete_bst(root, val):
    if not root:
        return root
    
    if val < root.val:
        root.left = delete_bst(root.left, val)
    elif val > root.val:
        root.right = delete_bst(root.right, val)
    else:
        # Node to delete found
        if not root.left:
            return root.right
        elif not root.right:
            return root.left
        
        # Node has both children
        min_node = find_min(root.right)
        root.val = min_node.val
        root.right = delete_bst(root.right, min_node.val)
    
    return root

def find_min(node):
    while node.left:
        node = node.left
    return node
```

## Balanced Trees

### AVL Trees
Self-balancing BST where height difference between left and right subtrees ≤ 1.

**Rotations:**
- Left Rotation (LL)
- Right Rotation (RR) 
- Left-Right Rotation (LR)
- Right-Left Rotation (RL)

### Red-Black Trees
Self-balancing BST with additional color property ensuring balanced height.

**Properties:**
- Every node is red or black
- Root is black
- Red nodes have black children
- All paths from root to leaves have same number of black nodes

## Time & Space Complexity

### Binary Tree Operations

| Operation | Average | Worst Case |
|-----------|---------|------------|
| Search    | O(log n)| O(n)       |
| Insert    | O(log n)| O(n)       |
| Delete    | O(log n)| O(n)       |
| Traversal | O(n)    | O(n)       |

### Space Complexity
- **Storage**: O(n)
- **Traversal**: O(h) where h is height
  - Balanced tree: O(log n)
  - Skewed tree: O(n)

## Common Interview Problems

### 1. Validate BST
```python
def is_valid_bst(root):
    def validate(node, min_val, max_val):
        if not node:
            return True
        
        if node.val <= min_val or node.val >= max_val:
            return False
        
        return (validate(node.left, min_val, node.val) and 
                validate(node.right, node.val, max_val))
    
    return validate(root, float('-inf'), float('inf'))
```

### 2. Lowest Common Ancestor
```python
def lowest_common_ancestor(root, p, q):
    if not root or root == p or root == q:
        return root
    
    left = lowest_common_ancestor(root.left, p, q)
    right = lowest_common_ancestor(root.right, p, q)
    
    if left and right:
        return root
    
    return left if left else right
```

### 3. Symmetric Tree
```python
def is_symmetric(root):
    def is_mirror(left, right):
        if not left and not right:
            return True
        if not left or not right:
            return False
        
        return (left.val == right.val and
                is_mirror(left.left, right.right) and
                is_mirror(left.right, right.left))
    
    return is_mirror(root.left, root.right) if root else True
```

### 4. Path Sum
```python
def has_path_sum(root, target_sum):
    if not root:
        return False
    
    if not root.left and not root.right:
        return root.val == target_sum
    
    remaining = target_sum - root.val
    return (has_path_sum(root.left, remaining) or 
            has_path_sum(root.right, remaining))
```

### 5. Binary Tree Maximum Path Sum
```python
def max_path_sum(root):
    max_sum = float('-inf')
    
    def max_gain(node):
        nonlocal max_sum
        if not node:
            return 0
        
        left_gain = max(max_gain(node.left), 0)
        right_gain = max(max_gain(node.right), 0)
        
        price_newpath = node.val + left_gain + right_gain
        max_sum = max(max_sum, price_newpath)
        
        return node.val + max(left_gain, right_gain)
    
    max_gain(root)
    return max_sum
```

## Best Practices

### 1. Design Considerations
- Choose appropriate tree type based on use case
- Consider balance requirements for performance
- Plan for concurrent access if needed

### 2. Implementation Tips
- Always handle null/empty cases
- Use recursion carefully (stack overflow risk)
- Consider iterative solutions for deep trees
- Implement proper error handling

### 3. Testing Strategies
- Test with empty trees
- Test with single node
- Test with balanced and skewed trees
- Test edge cases (duplicates, negative values)

### 4. Optimization Techniques
- Use iterative traversals for memory efficiency
- Implement tail recursion where possible
- Consider thread-local storage for traversal state
- Use bit manipulation for certain tree properties

### 5. Common Pitfalls
- Forgetting to handle null nodes
- Incorrect recursion base cases
- Memory leaks in manual memory management
- Not considering tree balance in performance analysis

## Conclusion

Binary trees are fundamental data structures that provide efficient solutions for many computational problems. Understanding their properties, operations, and variations is crucial for:

- Algorithm design and analysis
- Database implementation
- Compiler design
- File system organization
- Decision-making systems

Master the basic operations and traversals first, then explore specialized variants like BSTs, AVL trees, and other balanced trees based on your specific needs.