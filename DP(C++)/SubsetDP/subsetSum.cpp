// Subset Sum Equal To Target
// Given an integer array nums and an integer target, return true if you can choose the elements of the array such that their
// sum equals target or false otherwise.

// Recursive Approach
#include <bits/stdc++.h>

bool func(int idx, int target, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (idx == 0)
        return (arr[0] == target);
    bool nttake = func(idx - 1, target, arr);
    bool take = false;
    if (arr[idx] <= target)
        take = func(idx - 1, target - arr[idx], arr);
    return take | nttake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return func(n, k, arr);
}

// Memoization Approach
#include <bits/stdc++.h>
bool func(int idx, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (idx == 0)
        return (arr[0] == target);
    if (dp[idx][target] != -1)
        return dp[idx][target];
    bool nttake = func(idx - 1, target, arr, dp);
    bool take = false;
    if (arr[idx] <= target)
        take = func(idx - 1, target - arr[idx], arr, dp);
    return dp[idx][target] = take | nttake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return func(n - 1, k, arr, dp);
}

// Tabulation Approach
#include <bits/stdc++.h>
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= k)
        dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool nttake = dp[i - 1][j];
            bool take = false;
            if (arr[i] <= j)
                take = dp[i - 1][j - arr[i]];
            dp[i][j] = take | nttake;
        }
    }
    return dp[n - 1][k];
}
// Space Optimization Approach
#include <bits/stdc++.h>
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, false), curr(k + 1, false);
    prev[0] = true;
    if (arr[0] <= k)
        prev[arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        curr[0] = true;
        for (int j = 1; j <= k; j++)
        {
            bool nttake = prev[j];
            bool take = false;
            if (arr[i] <= j)
                take = prev[j - arr[i]];
            curr[j] = take | nttake;
        }
        prev = curr;
    }
    return prev[k];
}