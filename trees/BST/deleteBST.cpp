#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// This function is used to find the minimum value node in a BST
  TreeNode* getMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==NULL) return NULL;

        // Traverse the tree to find the node to be deleted
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            //node with only right child or no child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            //node with only left child 
            else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            //node with two children: get the inorder successor (smallest in the right subtree)
            // Copy the inorder successor's content to this node
            TreeNode* succ = getMin(root->right);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }

    //we can also take max value from left subtree and replace it with the node to be deleted
    //both methods are valid