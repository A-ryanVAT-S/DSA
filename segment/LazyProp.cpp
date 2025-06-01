//we know segment tree take O(n) time to build and O(log n) time to query and update
//so for n operations it will take O(n log n) time
// and for q queries for those n updates  in that range  will take o(q*n*log n) time
//thus we optimize it by using lazy propagation

//for eg nums[start to end] -> update to all elements
//for eg arr={3,4,2,5,3,6,3,4} , range=[2,5] , add=2
//simple game h , l r check karte jayenge range mai h toh jitne subchilds h unko val se multiply karke add kar denge, aur ek dummytree banayenge
//and dummy mai woh subchilds ka update rahega for future queries

#include <bits/stdc++.h>
using namespace std;

class LazySegmentTree {
    vector<int> tree, lazy;
    int n;
    //building the segment tree code we would need to write here.

public:
    void updateRange(int start, int end, int val) {
        updateRangeUtil(start, end, 0, 0, n - 1, val, tree);  // start,end,node,left,right,val,tree
    }

    void updateRangeUtil(int start, int end, int node, int left, int right, int val, vector<int> &tree) {
        if (lazy[node] != 0) {  // If there are pending updates
            tree[node] += (right - left + 1) * lazy[node];  // Apply the pending update
            if (left != right) {  // Not a leaf node
                lazy[node * 2 + 1] += lazy[node];  // Propagate to left child
                lazy[node * 2 + 2] += lazy[node];  // Propagate to right child
            }
            lazy[node] = 0;  // Clear the lazy value
        }

        if (left > end || right < start) return;  // No overlap

        if (left >= start && right <= end) {  // Total overlap
            tree[node] += (right - left + 1) * val;
            if (left != right) {  // Not a leaf node
                lazy[node * 2 + 1] += val;  // Propagate to left child
                lazy[node * 2 + 2] += val;  // Propagate to right child
            }
            return;
        }

        int mid = (left + right) / 2;
        updateRangeUtil(start, end, node * 2 + 1, left, mid, val, tree);   // Update left child
        updateRangeUtil(start, end, node * 2 + 2, mid + 1, right, val, tree);   // Update right child
        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];   // Update current node value
    }
};