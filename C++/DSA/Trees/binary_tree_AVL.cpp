#include <iostream>
using namespace std;

// AVL Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// Function to get the height of a node
int height(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Function to get the balance factor of a node
int getBalance(Node* node) {
    return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

// Right rotate the subtree rooted at node
Node* rightRotate(Node* node) {
    Node* newRoot = node->left;
    Node* temp = newRoot->right;
    newRoot->right = node;
    node->left = temp;

    // Update heights
    node->height = max(height(node->left), height(node->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}

// Left rotate the subtree rooted at node
Node* leftRotate(Node* node) {
    Node* newRoot = node->right;
    Node* temp = newRoot->left;
    newRoot->left = node;
    node->right = temp;

    // Update heights
    node->height = max(height(node->left), height(node->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}

// Insert a node into the AVL tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        return root; // Duplicate values are not allowed
    }

    // Update the height of the current node
    root->height = max(height(root->left), height(root->right)) + 1;

    // Check the balance factor to see if the tree has become unbalanced
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && value < root->left->data) {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && value > root->right->data) {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// In-order traversal to print the tree nodes
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int values[] = {20, 10, 30, 25, 5, 15, 40}; // Example input

    for (int value : values) {
        root = insert(root, value);
    }

    cout << "In-order traversal of the AVL tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
