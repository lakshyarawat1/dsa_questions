#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class AVLNode
{
public:
    int data;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
{
private:
    AVLNode *root;

    // Get height of node
    int getHeight(AVLNode *node)
    {
        return node ? node->height : 0;
    }

    // Get balance factor
    int getBalance(AVLNode *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // Update height of node
    void updateHeight(AVLNode *node)
    {
        if (node)
        {
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        }
    }

    // Right rotate
    AVLNode *rightRotate(AVLNode *y)
    {
        AVLNode *x = y->left;
        AVLNode *T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // Left rotate
    AVLNode *leftRotate(AVLNode *x)
    {
        AVLNode *y = x->right;
        AVLNode *T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // Insert helper
    AVLNode *insertHelper(AVLNode *node, int data)
    {
        // 1. Normal BST insertion
        if (!node)
        {
            return new AVLNode(data);
        }

        if (data < node->data)
        {
            node->left = insertHelper(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insertHelper(node->right, data);
        }
        else
        {
            // Duplicate values not allowed
            return node;
        }

        // 2. Update height
        updateHeight(node);

        // 3. Get balance factor
        int balance = getBalance(node);

        // 4. Perform rotations if needed

        // Left Left Case
        if (balance > 1 && data < node->left->data)
        {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && data > node->right->data)
        {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && data > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && data < node->right->data)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Find minimum value node
    AVLNode *findMin(AVLNode *node)
    {
        while (node->left)
        {
            node = node->left;
        }
        return node;
    }

    // Delete helper
    AVLNode *deleteHelper(AVLNode *node, int data)
    {
        // 1. Normal BST deletion
        if (!node)
        {
            return node;
        }

        if (data < node->data)
        {
            node->left = deleteHelper(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = deleteHelper(node->right, data);
        }
        else
        {
            // Node to be deleted found
            if (!node->left || !node->right)
            {
                AVLNode *temp = node->left ? node->left : node->right;
                if (!temp)
                {
                    temp = node;
                    node = nullptr;
                }
                else
                {
                    *node = *temp;
                }
                delete temp;
            }
            else
            {
                AVLNode *temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteHelper(node->right, temp->data);
            }
        }

        if (!node)
            return node;

        // 2. Update height
        updateHeight(node);

        // 3. Get balance factor
        int balance = getBalance(node);

        // 4. Perform rotations if needed

        // Left Left Case
        if (balance > 1 && getBalance(node->left) >= 0)
        {
            return rightRotate(node);
        }

        // Left Right Case
        if (balance > 1 && getBalance(node->left) < 0)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && getBalance(node->right) <= 0)
        {
            return leftRotate(node);
        }

        // Right Left Case
        if (balance < -1 && getBalance(node->right) > 0)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Search helper
    bool searchHelper(AVLNode *node, int data)
    {
        if (!node)
            return false;

        if (data == node->data)
            return true;

        if (data < node->data)
        {
            return searchHelper(node->left, data);
        }

        return searchHelper(node->right, data);
    }

    // Inorder traversal helper
    void inorderHelper(AVLNode *node)
    {
        if (node)
        {
            inorderHelper(node->left);
            cout << node->data << " ";
            inorderHelper(node->right);
        }
    }

    // Preorder traversal helper
    void preorderHelper(AVLNode *node)
    {
        if (node)
        {
            cout << node->data << " ";
            preorderHelper(node->left);
            preorderHelper(node->right);
        }
    }

    // Postorder traversal helper
    void postorderHelper(AVLNode *node)
    {
        if (node)
        {
            postorderHelper(node->left);
            postorderHelper(node->right);
            cout << node->data << " ";
        }
    }

    // Destroy tree helper
    void destroyTree(AVLNode *node)
    {
        if (node)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    AVLTree() : root(nullptr) {}

    ~AVLTree()
    {
        destroyTree(root);
    }

    // Insert operation
    void insert(int data)
    {
        root = insertHelper(root, data);
    }

    // Delete operation
    void remove(int data)
    {
        root = deleteHelper(root, data);
    }

    // Search operation
    bool search(int data)
    {
        return searchHelper(root, data);
    }

    // Traversal operations
    void inorder()
    {
        cout << "Inorder: ";
        inorderHelper(root);
        cout << endl;
    }

    void preorder()
    {
        cout << "Preorder: ";
        preorderHelper(root);
        cout << endl;
    }

    void postorder()
    {
        cout << "Postorder: ";
        postorderHelper(root);
        cout << endl;
    }

    // Level order traversal
    void levelOrder()
    {
        if (!root)
        {
            cout << "Level Order: Tree is empty" << endl;
            return;
        }

        cout << "Level Order: ";
        queue<AVLNode *> q;
        q.push(root);

        while (!q.empty())
        {
            AVLNode *current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        cout << endl;
    }

    // Get tree height
    int getTreeHeight()
    {
        return getHeight(root);
    }

    // Check if tree is empty
    bool isEmpty()
    {
        return root == nullptr;
    }

    // Display tree structure
    void displayTree()
    {
        if (!root)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        displayTreeHelper(root, "", true);
    }

private:
    void displayTreeHelper(AVLNode *node, string indent, bool last)
    {
        if (node)
        {
            cout << indent;
            if (last)
            {
                cout << "└── ";
                indent += "    ";
            }
            else
            {
                cout << "├── ";
                indent += "│   ";
            }
            cout << node->data << " (h:" << node->height << ", b:" << getBalance(node) << ")" << endl;

            if (node->left || node->right)
            {
                if (node->right)
                    displayTreeHelper(node->right, indent, !node->left);
                if (node->left)
                    displayTreeHelper(node->left, indent, true);
            }
        }
    }
};

// Demo function
int main()
{
    AVLTree avl;

    cout << "=== AVL Tree Operations Demo ===" << endl;

    // Insert operations
    cout << "\nInserting elements: 10, 20, 30, 40, 50, 25" << endl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    cout << "\nTree structure after insertions:" << endl;
    avl.displayTree();

    // Traversals
    cout << "\nTraversals:" << endl;
    avl.inorder();
    avl.preorder();
    avl.postorder();
    avl.levelOrder();

    // Search operations
    cout << "\nSearch operations:" << endl;
    cout << "Search 25: " << (avl.search(25) ? "Found" : "Not Found") << endl;
    cout << "Search 35: " << (avl.search(35) ? "Found" : "Not Found") << endl;

    // Tree properties
    cout << "\nTree properties:" << endl;
    cout << "Tree height: " << avl.getTreeHeight() << endl;
    cout << "Is empty: " << (avl.isEmpty() ? "Yes" : "No") << endl;

    // Delete operations
    cout << "\nDeleting element 30:" << endl;
    avl.remove(30);
    avl.displayTree();
    avl.inorder();

    cout << "\nDeleting element 40:" << endl;
    avl.remove(40);
    avl.displayTree();
    avl.inorder();

    return 0;
}