#include <bits/stdc++.h>
using namespace std;

//TC to insert a value into the BST is O(h) where h is the height of the tree,h=log(n) for a balanced BST and h=n for a skewed BST
//SC to insert a value into the BST is O(h) where h is the height of the tree,h=log(n) for a balanced BST and h=n for a skewed BST

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

//` Function to insert a value into the BST
//why & , as we are passing the address of the root node
//if we pass the root node by value then it will create a copy of the root node
void insert(Node*& root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return;
    }
    if (val < root->data) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}
// in BST , values less than the current node go to the left subtree
// and values greater than the current node go to the right subtree.


//so in order traversal of BST we get sorted order of elements
//in preorder traversal of BST we get the elements in the order of insertion
//in postorder traversal of BST we get the elements in the order of del xetions