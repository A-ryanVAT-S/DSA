#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    // Correct constructor
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}


int main() {
    // Create a simple binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    //tree would look like this
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5


    // Preorder traversal
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    // Inorder traversal
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Postorder traversal
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    // Level order traversal
    cout << "Level Order Traversal: ";
    levelOrder(root);
    return 0;
}