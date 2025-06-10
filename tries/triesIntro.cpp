#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26]={};// nullptr for each character
    bool flag = false;

    bool contains(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) { 
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string &word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->contains(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]); 
        }
        node->setEnd();
    }

    bool search(string &word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->contains(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool isPrefix(string &word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->contains(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }
};
    //we can somtime write delete function to delte entire trie to save memory
void deleteTrie(Node* node) {
    for (int i = 0; i < 26; i++) {
        if (node->links[i] != nullptr) {
            deleteTrie(node->links[i]);
        }
    }
    delete node;
}

//use example
//word search 2 lc 212
//we have given a matrix of characters and a list of words, we need to find all the words that can be formed by adjacent characters in the matrix


class Solution {
public:
    struct Node {
        Node* links[26] = {};
        string word = "";
        bool flag = false;
    };

    Node* getNode() {
        return new Node();
    }

    Node* root = getNode();

    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (node->links[ch - 'a'] == nullptr) {
                node->links[ch - 'a'] = getNode();
            }
            node = node->links[ch - 'a'];
        }
        node->flag = true;
        node->word = word;
    }

    void dfs(int i, int j, vector<vector<char>>& board, Node* node, vector<string>& result) {
        char ch = board[i][j];
        if (ch == '#' || node->links[ch - 'a'] == nullptr) return;

        node = node->links[ch - 'a'];
        if (node->flag) {
            result.push_back(node->word);
            node->flag = false; 
        }

        board[i][j] = '#'; 

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for (int d = 0; d < 4; ++d) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size()) {
                dfs(ni, nj, board, node, result);
            }
        }

        board[i][j] = ch; 
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (const string& word : words) {
            insert(word);
        }

        vector<string> result;
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dfs(i, j, board, root, result);
            }
        }

        return result;
    }
};


