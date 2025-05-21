// Problem statement
// You are given an array/list of ‘N’ integers.
// You are supposed to return the maximum sum of the subsequence with the constraint that no
// two elements are adjacent in the given array/list.

// Note:
// A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list,
// leaving the remaining elements in their original order.

// for robbing house problem, use two seperate recursive calls
//  for the first and last element

// bottom-up approach
#include <iostream>
#include <vector>
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[n - 1];
}
// top-down approach
#include <bits/stdc++.h>
using namespace std;

int RecTop(vector<int> &nums, vector<int> &dp, int n)
{
    if (n == 0)
        return nums[0];
    if (n == 1)
        return max(nums[0], nums[1]);
    if (dp[n] != -1)
        return dp[n];

    dp[n] = max(RecTop(nums, dp, n - 1), RecTop(nums, dp, n - 2) + nums[n]);
    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return RecTop(nums, dp, n - 1);
    ;
}

// space optimized approach
#include <bits/stdc++.h>
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];

    int prev2 = nums[0];               // dp[i-2]
    int prev1 = max(nums[0], nums[1]); // dp[i-1]

    for (int i = 2; i < n; i++)
    {
        int curr = max(prev1, prev2 + nums[i]); // dp[i] = max(dp[i-1], dp[i-2] + nums[i])
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

// recursive approach
#include <bits/stdc++.h>
using namespace std;

int Rec(vector<int> &nums, int i)
{
    if (i == 0)
        return nums[0];
    if (i < 0)
        return 0;

    int pick = nums[i] + Rec(nums, i - 2); // include nums[i]
    int notPick = Rec(nums, i - 1);        // exclude nums[i]

    return max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    return Rec(nums, n - 1);
}
