//we will create a minimum segment tree for a given array

#include <bits/stdc++.h>
using namespace std;

void SegTree(vector<int> &tree, vector<int> &arr, int start, int end, int curr) {
    if (start == end) {
        tree[curr] = arr[start];  
        return;
    }
    int mid = (start + end) / 2;
    SegTree(tree, arr, start, mid, 2 * curr + 1);
    SegTree(tree, arr, mid + 1, end, 2 * curr + 2);
    tree[curr] = min(tree[2 * curr + 1], tree[2 * curr + 2]);  
}

    int main(){
    vector<int> nums = {3, 1, 2, 7, 2, 1, 2, 3};
    int size = nums.size(); 
    vector<int> trees(4 * size);
    SegTree(trees, nums, 0, size - 1, 0);
    int start, end;
    cout << "START : ";
    cin >> start;
    cout << "END : ";
    cin >> end;
    int ans = trees[0]; // Initialize with the root value
    for (int i = start; i <= end; ++i) {
        ans = min(ans, nums[i]); // Find the minimum in the specified range
    }
    cout << "ANSWER : " << ans << endl;
    return 0;
}