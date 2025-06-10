// suppose we want to find the maximum value's index in a vector

#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = start; // Store index of the maximum value
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            int leftIndex = tree[2 * node + 1];
            int rightIndex = tree[2 * node + 2];
            tree[node] = (arr[leftIndex] >= arr[rightIndex]) ? leftIndex : rightIndex;
        }
    }

    int query(int node, int start, int end, int l, int r, const vector<int>& arr) {
        if (r < start || end < l) {
            return -1; // Out of range
        }
        if (l <= start && end <= r) {
            return tree[node]; // Current segment is completely within the range
        }
        int mid = (start + end) / 2;
        int leftIndex = query(2 * node + 1, start, mid, l, r, arr);
        int rightIndex = query(2 * node + 2, mid + 1, end, l, r, arr);
        if (leftIndex == -1) return rightIndex;
        if (rightIndex == -1) return leftIndex;
        return (arr[leftIndex] >= arr[rightIndex]) ? leftIndex : rightIndex;
    }
};
//RMIQ question example
// given an array , and a range [l, r], find the index of the maximum value in that range leftmost index
class Solution {
public:
    int build(vector<int>& heights, int start, int end, vector<int>& st, int node) {
        if (start == end) {
            st[node] = start;
            return start;
        }

        int mid = (start + end) / 2;
        int left = build(heights, start, mid, st, 2 * node + 1);
        int right = build(heights, mid + 1, end, st, 2 * node + 2);

        st[node] = (heights[left] >= heights[right]) ? left : right;
        return st[node];
    }

    int query(vector<int>& heights, vector<int>& st, int start, int end, int l, int r, int node) {
        if (r < start || l > end) return -1;
        if (l <= start && end <= r) return st[node];

        int mid = (start + end) / 2;
        int left = query(heights, st, start, mid, l, r, 2 * node + 1);
        int right = query(heights, st, mid + 1, end, l, r, 2 * node + 2);

        if (left == -1) return right;
        if (right == -1) return left;
        return (heights[left] >= heights[right]) ? left : right;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> st(4 * n);
        build(heights, 0, n - 1, st, 0);

        vector<int> result;

        for (auto& q : queries) {
            int a = q[0], b = q[1];
            int minIdx = min(a, b);
            int maxIdx = max(a, b);

            if (a == b) {
                result.push_back(a);
            } else if (heights[maxIdx] > heights[minIdx]) {
                result.push_back(maxIdx);
            } else {
                int l = maxIdx + 1, r = n - 1;
                int ans = -1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    int idx = query(heights, st, 0, n - 1, maxIdx + 1, mid, 0);
                    if (idx != -1 && heights[idx] > heights[minIdx]) {
                        ans = idx;
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                }
                result.push_back(ans);
            }
        }

        return result;
    }
};
