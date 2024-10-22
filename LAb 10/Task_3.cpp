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

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }  
    return root;
}
void inOrderTraversal(Node* root) {
    if (root == nullptr)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

bool search(Node* root, int value) {
    if (root == nullptr)
        return false;

    if (root->data == value)
        return true;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);  
}
int main() {
    Node* root = nullptr;

  int n;
    cout<<" how many value do you want to add : ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
    int val;
    cout<<"Enter the value "<<i+1<<"\t";
    cin>>val;
    root = insert(root, val);
    }
    cout<<endl;
    cout<<"Inordertraversal binary tree:\t ";
    inOrderTraversal(root);
    cout<<endl;
    int key ;
    cout<<"Enter the valve do you want to search :\t";
    cin>>key;
    if (search(root, key)) {
        cout << key << "\t found in the BST.\n";
    } else {
        cout << key << " \nnot found in the BST.\n";
    }
    return 0;
}
