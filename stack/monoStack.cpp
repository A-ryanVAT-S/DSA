//Montonic Stack are data structures that maintain their elements in a sorted order, either increasing or decreasing.
//generally used to solve problems related to finding the next greater or smaller element in an array.
#include <bits/stdc++.h>
using namespace std;

//previous greater element in an array
//TC: O(n)
//SC: O(n)
class Solution3 {
public:
    vector<int> prevGreaterElements(vector<int>& nums) {
        stack<int> pool;
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!pool.empty() && pool.top()<=nums[i]){
                pool.pop();
            }
            ans[i]=pool.empty()? -1 : pool.top();
            pool.push(nums[i]);
        }
        return ans;
    }
};

//next greater element in an array
//TC: O(n)
//SC: O(n)
class Solution4 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> pool;
        int n = nums.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!pool.empty() && pool.top()<=nums[i]){
                pool.pop();
            }
            ans[i]=pool.empty()? -1 : pool.top();
            pool.push(nums[i]);
        }
        return ans;
    }
};

//next greater element in an a circular array
//TC: O(n)
//SC: O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> pool;
        int n = nums.size();
        vector<int> ans(n);
        for(int i=2*n-1;i>=0;i--){
            int idx=i%n;
            while(!pool.empty() && pool.top()<=nums[idx]){
                pool.pop();
            }
            if(i<n){
                ans[i]=pool.empty()? -1 : pool.top();
            }
            pool.push(nums[idx]);
        }
        return ans;
    }
};

//sum of subarray ranges
// calculate the minimum and maximum of all subarrays
// and then calculate the difference between the maximum and minimum for each subarray.
//TC: O(n)
//SC: O(n)
class Solution2 {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int> pool;
        vector<long long> minSum(n, 0), maxSum(n, 0);
        
        for(int i=0;i<n;i++){
            while(!pool.empty() && nums[pool.top()]>=nums[i]){
                pool.pop();
            }
            minSum[i] = pool.empty() ? -1 : pool.top();
            pool.push(i);
        }
        
        while(!pool.empty()) pool.pop();
        
        for(int i=0;i<n;i++){
            while(!pool.empty() && nums[pool.top()]<=nums[i]){
                pool.pop();
            }
            maxSum[i] = pool.empty() ? -1 : pool.top();
            pool.push(i);
        }
        
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans += (long long)(maxSum[i] - minSum[i]);
        }
        
        return ans;
    }
};
