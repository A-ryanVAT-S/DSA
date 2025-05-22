#include <bits/stdc++.h>
using namespace std;

class Node {
public:
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


//iterative preorder traversal
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node* current = s.top();
            s.pop();
            result.push_back(current->data);

            // Push right child first so that left child is processed first
            if (current->right) s.push(current->right);
            if (current->left) s.push(current->left);
        }

        return result;
    }
};

//iterative inorder traversal
class Solution {
public:
    vector<int> inorder(Node* root) {
        vector<int> result;
        stack<Node*> s;
        Node* current = root;

        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            result.push_back(current->data);
            current = current->right;
        }

        return result;
    }
};

//post order with 2 stacks
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<Node*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            Node* current = s1.top();
            s1.pop();
            s2.push(current);

            if (current->left) s1.push(current->left);
            if (current->right) s1.push(current->right);
        }

        while (!s2.empty()) {
            result.push_back(s2.top()->data);
            s2.pop();
        }

        return result;
    }
};
//post order with 1 stack
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<Node*> s;
        Node* current = root;
        Node* lastVisited = nullptr;

        while (!s.empty() || current != nullptr) {
            if (current != nullptr) {
                s.push(current);
                current = current->left;
            } else {
                Node* peekNode = s.top();
                // If the right child is null or has already been visited
                if (peekNode->right == nullptr || peekNode->right == lastVisited) {
                    result.push_back(peekNode->data);
                    lastVisited = s.top();
                    s.pop();
                } else {
                    current = peekNode->right;
                }
            }
        }

        return result;
    }
};



// all 3 in one go in iterative way using stack
class Solution
{
public:
    void allTraversals(Node* root, vector<int>& inorder, vector<int>& postorder, vector<int>& preorder) {
        if (root == nullptr) return;

        stack<pair<Node*, int>> s;
        s.push({root, 1});

        while (!s.empty()) {
            auto [current, state] = s.top();
            s.pop();

            if (state == 1) {
                preorder.push_back(current->data);
                s.push({current, 2});
                if (current->left) s.push({current->left, 1});
            } else if (state == 2) {
                inorder.push_back(current->data);
                s.push({current, 3});
                if (current->right) s.push({current->right, 1});
            } else {
                postorder.push_back(current->data);
            }
        }
    }
};
