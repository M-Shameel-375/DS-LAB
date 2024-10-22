#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

// Function to create a new Node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a new node in the BST
Node* insert(Node* root, int value) {
    // If the tree is empty, create a new node
    if (root == nullptr) {
        return createNode(value);
    }
    
    // Recur down the tree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // Return the (unchanged) node pointer
    return root;
}

// Function for searching in the BST
bool search(Node* root, int value) {
    if (root == nullptr)
        return false;

    if (root->data == value)
        return true;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);  // Fix: search in the right subtree for values greater than root->data
}

int main() {
    Node* root = nullptr;

    // Insert nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    int key = 40;

    // Search in the BST
    cout << "Searching in the BST:\n";
    if (search(root, key)) {
        cout << key << " found in the BST.\n";
    } else {
        cout << key << " not found in the BST.\n";
    }

    return 0;
}
