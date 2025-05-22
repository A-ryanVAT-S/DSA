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

vector<int> preorder(Node* root,vector<int> &result) {
    if (root == nullptr) return result;
    result.push_back(root->data);
    preorder(root->left,result);
    preorder(root->right,result);
    return result;
}

vector<int> inorder(Node* root,vector<int> &result) {
    if (root == nullptr) return result;
    inorder(root->left,result);
    result.push_back(root->data);
    inorder(root->right,result);
    return result;
}

vector<int> postorder(Node* root,vector<int> &result) {
    if (root == nullptr) return result;
    postorder(root->left,result);
    postorder(root->right,result);
    result.push_back(root->data);
    return result;
}

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> result;
    if (root == nullptr) return result;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> level;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();
            level.push_back(current->data);
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        result.push_back(level);
    }
    return result;
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
    vector<int> preOrderResult;
    preorder(root, preOrderResult);
    for (int val : preOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    // Inorder traversal
    cout << "Inorder Traversal: ";
    vector<int> inOrderResult;
    inorder(root, inOrderResult);
    for (int val : inOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    // Postorder traversal
    cout << "Postorder Traversal: ";
    vector<int> postOrderResult;
    postorder(root, postOrderResult);
    for (int val : postOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    // Level order traversal
    cout << "Level Order Traversal: ";
    vector<vector<int>> levelOrderResult = levelOrder(root);
    for (const auto& level : levelOrderResult) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}