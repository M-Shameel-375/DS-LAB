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

// Function for In-Order Traversal of the BST
void preorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    // Recur on the left subtree
    // Print the data of the node
    cout << root->data << " ";
    preorderTraversal(root->left);


    // Recur on the right subtree
preorderTraversal(root->right);
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

    // Display In-Order Traversal of the BST
    cout << "pre order traversal of the BST: ";
    preorderTraversal(root);

    return 0;
}
