// You are given two arrays of strings words and query.
// For each query[i], you need to find a string from words that has the longest common suffix with query[i].
//  If there are two or more strings in words that share the longest common suffix, find the string that is the smallest in length.
// If there are two or more such strings that have the same smallest length, find the one that occurred earlier in words.
// Return an array of integers ans, where ans[i] is the index of the string in words that has the longest common suffix with query[i].

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    struct Node {
        int idx;
        Node* next[26]={};
    };

    Node* getNode(int i) {
        Node* node = new Node();
        node->idx = i;
        for (int j = 0; j < 26; j++) node->next[j] = NULL;
        return node;
    }

    void insert(Node* root, int i, vector<string>& words) {
        string& word = words[i];
        int len = word.size();

        for (int j = len - 1; j >= 0; j--) {
            int ch = word[j] - 'a';

            if (root->next[ch] == NULL) {
                root->next[ch] = getNode(i);
            }
            root = root->next[ch];

            if (words[root->idx].size() > len) {
                root->idx = i;
            }
        }
    }

    int find(Node* root, string& word) {
        int res = root->idx;
        int len = word.size();

        for (int i = len - 1; i >= 0; i--) {
            int ch = word[i] - 'a';
            if (!root->next[ch]) return res;
            root = root->next[ch];
            res = root->idx;
        }
        return res;
    }

    vector<int> stringIndices(vector<string>& words, vector<string>& queries) {
        int n = words.size(), q = queries.size();
        vector<int> ans(q);

        Node* root = getNode(0);
        for (int i = 0; i < n; i++) {
            if (words[root->idx].size() > words[i].size()) {
                root->idx = i;
            }
            insert(root, i, words);
        }

        for (int i = 0; i < q; i++) {
            ans[i] = find(root, queries[i]);
        }

        return ans;
    }
};
