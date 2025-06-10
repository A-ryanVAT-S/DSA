// Given an array of integers, find the maximum value of nums[i] ^ nums[j] where i ≠ j.

// Why Not Brute Force?
// Brute force = O(n²) time by trying every pair.
// Too slow for large inputs (up to 10⁵ elements).

// Why Trie (Prefix Tree) of Bits?
// We want to maximize XOR.

// XOR is largest when bits differ: 1 ^ 0 = 1, 1 ^ 1 = 0, etc.
// So, to get max XOR with a number, we try to choose the opposite bit at each position starting from most significant bit (MSB).

// Approach Summary:
// Insert all numbers into a binary Trie (each level = 1 bit from MSB to LSB).
// For each number, try to maximize XOR by greedily picking the opposite bit in Trie.
// This gives O(32n) time, where 32 = max bit-length of int.

// Overall Time Complexity = O(32 * n).
// Space Complexity = O(32 * n) for the Trie.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    // Node of the binary Trie: left for 0, right for 1
    struct BNode {
        BNode *left = nullptr, *right = nullptr; 
    };

    // Root of the Trie
    BNode* root = new BNode();

    // Insert number into the Trie in 32-bit binary form
    void insert(int x) {
        BNode* curr = root;
        for (int i = 31; i >= 0; i--) { // from MSB to LSB
            int bit = (x >> i) & 1; // extract the ith bit
            if (bit == 0) {
                if (curr->left == nullptr) {
                    curr->left = new BNode(); // create new node for bit 0
                }
                curr = curr->left;
            } else {
                if (curr->right == nullptr) {
                    curr->right = new BNode(); // create new node for bit 1
                }
                curr = curr->right;
            }
        }
    }

    // Find max XOR for a given number by walking through the Trie
    int findMAX(int &num) {
        int maxi = 0;
        BNode* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            // To maximize XOR, we want to go opposite direction
            if (bit == 1) {
                if (curr->left != nullptr) {
                    maxi += (1 << i); // XOR at this bit is 1
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            } else {
                if (curr->right != nullptr) {
                    maxi += (1 << i); // XOR at this bit is 1
                    curr = curr->right;
                } else {
                    curr = curr->left;
                }
            }
        }
        return maxi;
    }

    // Main function to find maximum XOR of any two numbers
    int findMaximumXOR(vector<int>& nums) {
        // Step 1: Insert all numbers into the Trie
        for (int num : nums) {
            insert(num);
        }

        int maxi = 0;

        // Step 2: For each number, find the max XOR with any number in Trie
        for (int i = 0; i < nums.size(); i++) {
            int currXor = findMAX(nums[i]);
            maxi = max(maxi, currXor);
        }

        return maxi;
    }
};
