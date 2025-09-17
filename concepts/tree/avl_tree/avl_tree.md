# AVL Tree


## Issue with Binary Search Trees

- The final height of the binary search tree can be max n.
- When given a reversed sorted array, the tree will be skewed to one side. (left side)
- When given a sorted array, the tree will be skewed to one side. (right side)
- For the same array, we can have different shape and height of the tree depending on the order of insertion.

## Definition

- Simply, an AVL tree is a self-balancing binary search tree.
- A node in an AVL tree maintains an extra attribute called balance factor.
- Balance factor = height(left subtree) - height(right subtree)
- Balance factor can be -1, 0 or +1.
- Otherwise, the tree is unbalanced and needs to be rebalanced.

## Rebalancing

- There are four possible cases of unbalanced tree:
    1. Left Left Case
    2. Right Right Case
    3. Left Right Case
    4. Right Left Case

### Left Left Case

- When a node is inserted into the left subtree of the left child.
- Perform a right rotation on the unbalanced node.

### Right Right Case

- When a node is inserted into the right subtree of the right child.
- Perform a left rotation on the unbalanced node.

### Left Right Case

- When a node is inserted into the right subtree of the left child.
- Perform a left rotation on the left child, followed by a right rotation on the unbalanced node.

### Right Left Case

- When a node is inserted into the left subtree of the right child.
- Perform a right rotation on the right child, followed by a left rotation on the unbalanced node.

