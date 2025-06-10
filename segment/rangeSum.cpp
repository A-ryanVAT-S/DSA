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
    tree[curr] = tree[2 * curr + 1] + tree[2 * curr + 2];  
}

int fxn(int s, int e, int L, int R, vector<int> &tree, int curr) {
    if (R < s || L > e) // al l outside range
        return 0;
    if (L <= s && e <= R) // completely inside range
        return tree[curr];

        
        // if partially inside range
    int mid = (s + e) / 2;
    int leftSum = fxn(s, mid, L, R, tree, 2 * curr + 1);
    int rightSum = fxn(mid + 1, e, L, R, tree, 2 * curr + 2);
    return leftSum + rightSum;
}

int main() {
    vector<int> nums = {3, 1, 2, 7, 2, 1, 2, 3};
    int size = nums.size();
    vector<int> trees(4 * size); 
    SegTree(trees, nums, 0, size - 1, 0);   

    int start, end;
    cout << "START : ";
    cin >> start;
    cout << "END : ";
    cin >> end;

    int ans = fxn(0, size - 1, start, end, trees, 0); 
    cout << "ANSWER : " << ans << endl;
    return 0;
}
