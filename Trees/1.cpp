#include <iostream>
#include <queue>
using namespace std;

// Creating a node for the tree
struct Node {
    int data;
    Node* left;
    Node* right;  
    
    // Constructor
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insertNode(Node* root, int value) {
    // If the tree is empty, return a new node
    if (root == nullptr) {
        return new Node(value);
    }
    
    // Otherwise, recur down the tree
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    
    // Return the (unchanged) node pointer
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

//preorder
void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
//postorder
void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
// Level Order Traversal
void LevelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* newNode = q.front();
        cout<<newNode->data<<" ";
        q.pop();
    if(newNode->left){
        q.push(newNode->left);
    }
    if(newNode->right){
        q.push(newNode->right);
    }
    }
}
// insertion
// deletion
// searching
// BFS
// DFS


int main() {
    Node* root = nullptr;  // Start with an empty tree
    
    // Insert nodes into the binary tree
    root = insertNode(root, 4);
    root = insertNode(root, 2);
    root = insertNode(root, 6);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = insertNode(root, 5);
    root = insertNode(root, 7);
    
    // Print the tree in inorder traversal (sorted order)
    cout<<"DFS traversal has 3 types" <<endl << "1.InOrder" <<endl << "2.PreOrder" <<endl << "3.PostOrder";
     cout<<endl;
    cout << "Inorder traversal of the binary tree: ";
    inorder(root);
    cout<<endl;
    cout << "preorder traversal of the binary tree: ";
    preorder(root);
    cout<<endl;
    cout << "postorder traversal of the binary tree: ";
    postorder(root);
    cout<<endl;
    cout << "Levelorder / BFS traversal of the binary tree: ";
    LevelOrder(root);
    cout<<endl;
    return 0;
}
