# Binary Search tree (BST)

## Definition

- A binary search tree (BST) is a data structure that maintains a dynamic set of ordered elements, allowing for efficient insertion, deletion, and lookup operations.
- Each node in a BST has at most two children, referred to as the left and right child.
- Left subtree contains only nodes with values less than the parent node's value.
- Right subtree contains only nodes with values greater than the parent node's value.
- Both the left and right subtrees must also be binary search trees.    

- BST doesnot allow duplicate values.
- Inorder traversal of a BST yields the elements in sorted order.
- 

## Search Operation

- Start at the root node.
- Compare the target value with the value of the current node.
- If the target value is equal to the current node's value, the search is successful.
- If the target value is less than the current node's value, move to the left child and repeat the process.
- If the target value is greater than the current node's value, move to the right child and repeat the process.
- If a null reference is reached, the target value is not present in the tree.
- The search operation has a time complexity of O(h), where h is the height of the tree.

### Pseudocode

- In cpp

```cpp
Node* search(Node* root, int target) {
    // Base case: root is null or target is present at root
    if (root == nullptr || root->value == target) {
        return root;
    }
    // Target is greater than root's value
    if (target > root->value) {
        return search(root->right, target);
    }
    // Target is smaller than root's value
    return search(root->left, target);
}
```

## Recursive Insertion Operation

- Start at the root node.
- Compare the value to be inserted with the value of the current node.
- If the value to be inserted is less than the current node's value, move to the left child.
- If the value to be inserted is greater than the current node's value, move to the right child.
- If a null reference is reached, insert the new node at that position.

### Pseudocode

- In cpp

```cpp
Node* insert(Node* root, int value) {
    // If the tree is empty, return a new node
    if (root == nullptr) {
        return new Node(value);
    }
    // Otherwise, recur down the tree
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    // Return the unchanged node pointer
    return root;
}
```

## Creating BST from Sorted Array

- Start from root node.
- Find the middle element of the array and make it the root
- Recursively do the same for the left half and right half of the array to create left and right subtrees respectively.

