#include <iostream>
using namespace std;

// Define the structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node(); // Allocate memory for a new node
    newNode->data = value;      // Set the data
    newNode->left = nullptr;    // Initialize left child as null
    newNode->right = nullptr;   // Initialize right child as null
    return newNode;             // Return the new node
}

// Function to insert data into the binary tree
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        // If the tree is empty, create a new node
        return createNode(value);
    }

    if (value < root->data) {
        // Insert in the left subtree
        root->left = insertNode(root->left, value);
    } else {
        // Insert in the right subtree
        root->right = insertNode(root->right, value);
    }

    return root; // Return the (unchanged) root pointer
}

// In-order traversal: Left -> Root -> Right
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);          // Traverse left subtree
        cout << root->data << " ";             // Visit node
        inorderTraversal(root->right);         // Traverse right subtree
    }
}

// Pre-order traversal: Root -> Left -> Right
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";             // Visit node
        preorderTraversal(root->left);         // Traverse left subtree
        preorderTraversal(root->right);        // Traverse right subtree
    }
}

// Post-order traversal: Left -> Right -> Root
void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);        // Traverse left subtree
        postorderTraversal(root->right);       // Traverse right subtree
        cout << root->data << " ";             // Visit node
    }
}

int main() {
    Node* root = nullptr; // Initialize the root of the tree

    // Insert data into the binary tree
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Display the tree traversals
    cout << "In-order Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
