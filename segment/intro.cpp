//Segment Trees are data structures that allow for efficient range queries and updates on an array.
// They are particularly useful for problems involving range sums, minimums, maximums, and other associative operations.

//we will break arrays into parts and store the information in a tree-like structure
//where root node represents the whole array and each child node represents a segment of the array ,leaf nodes represent individual elements of the array.
//height of the tree is log(n) where n is the number of elements in the array. and height of two child nodes of any node will differ by at most 1.
//Segment trees are used to answer range queries in O(log n) time and update elements in O(log n) time.
//Because of this property, segment trees are called balanced binary trees.
// Total number of nodes in a segment tree is n+n/2+n/4......... total =2*n-1 = O(n) where n is the number of elements in the array.
//Segment trees are used in many applications such as:
//1. Range sum queries
//2. Range minimum/maximum queries
//3. Dynamic array problems
//4. Game development (e.g., for calculating scores over time)


#include <bits/stdc++.h>
using namespace std;

//we can build tree in O(n) time and answer queries in O(log n) time
//we can also update elements in O(log n) time 

//we can build it in a bottom-up manner or top-down manner
//bottom-up is more efficient in terms of memory usage

class SegmentTree {
private:
//Tree as an array has a root at index 0, left child at 2*i + 1, right child at 2*i + 2 if i is the index of the parent node.
    vector<int> tree;
    int n;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // sum operation
        }
    }
};
//as update in even prefix array takes o(n) time, we can use segment tree to update in O(log n) time
// like suppose we have array 3 1 2 7 now we want to update 2nd element to 5, we can do it in O(log n) time
//as only we have to update that element and then update the parent nodes accordingly till we reach the root node
// but in case of even prefix array, we have to update all the elements in the prefix array which takes O(n) time

// we will  update 2 to 5 , 2 and 7 which was earlier 9 now becomes 12
// void update(int idx, int value, int node, int start, int end) {
//     if (start == end) {
//         tree[node] = value;
//     } else {
//         int mid = (start + end) / 2;
//         if (idx <= mid) {
//             update(idx, value, 2 * node + 1, start, mid);
//         } else {
//             update(idx, value, 2 * node + 2, mid + 1, end);
//         }
//         tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; // sum operation
//     }
// }

//we take size of tree as 4*n to avoid overflow and to make sure we have enough space for all nodes
// as in worst case a complete binary tree will have 2^h - 1 nodes where h is the height of the tree(2*2^log(n)-1)
//as if n is not a power of 2, we need to have enough space for all nodes(suppose we have 9 nodes)
//8 would be pair, and 1 left and we will make dummy node for that to pair it(with 0 value)
//now we will have 5 pairs, then again for 2 pairs we will have 3rd pair as dummy
