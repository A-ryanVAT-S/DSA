//vertical order traversal
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalOrder(Node* root) {
    vector<vector<int>> result;
    if (!root) return result;

    map<int, vector<int>> m;
    queue<pair<Node*, int>> q; // pair of node and its horizontal distance
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();
        m[hd].push_back(node->data);

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    for (auto& [hd, nodes] : m) {
        result.push_back(nodes);
    }

    return result;
}

//top view of binary tree
vector<int> topView(Node* root) {
    vector<int> result;
    if (!root) return result;

    map<int, int> m; // horizontal distance to node value
    queue<pair<Node*, int>> q; // pair of node and its horizontal distance
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        // Only add the first node at each horizontal distance
        if (m.find(hd) == m.end()) {
            m[hd] = node->data;
        }

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    for (auto& [hd, val] : m) {
        result.push_back(val);
    }

    return result;
}

//bottom view of binary tree
vector<int> bottomView(Node* root) {
    vector<int> result;
    if (!root) return result;

    map<int, int> m; // horizontal distance to node value
    queue<pair<Node*, int>> q; // pair of node and its horizontal distance
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        // Always update the node value at each horizontal distance
        m[hd] = node->data;

        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }

    for (auto& [hd, val] : m) {
        result.push_back(val);
    }

    return result;
}


//left view of binary tree
vector<int> leftView(Node* root) {
    vector<int> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Node* node = q.front();
            q.pop();
            if (i == 0) result.push_back(node->data); // First node at this level

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return result;
}

//right view of binary tree
vector<int> rightView(Node* root) {
    vector<int> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Node* node = q.front();
            q.pop();
            if (i == size - 1) result.push_back(node->data); // Last node at this level

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return result;
}