// You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
// Once you pay the cost, you can either climb one or two steps.
// You can either start from the step with index 0, or the step with index 1.
// Return the minimum cost to reach the top of the floor.

#include <bits/stdc++.h>
using namespace std;

// TLE APPROACH
class Solution
{
public:
    int solve(vector<int> &cost, int i)
    {
        if (i == 0)
            return cost[0];
        if (i == 1)
            return cost[1];
        int ans = cost[i] + min(solve(cost, i - 1), solve(cost, i - 2));
        return ans;
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int ans = min(solve(cost, n - 1), solve(cost, n - 2));
        return ans;
    }
};

// TOP DOWN APPROACH
class Solution
{
public:
    int solve(vector<int> &cost, int i, vector<int> &dp)
    {
        if (i == 0)
            return cost[0];
        if (i == 1)
            return cost[1];
        if (dp[i] == -1)
            dp[i] = cost[i] + min(solve(cost, i - 1, dp), solve(cost, i - 2, dp));
        return dp[i];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int ans = min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
        return ans;
    }
};

// BOTTOM UP APPROACH
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i <= n; i++)
        {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};

// space optimized
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < n; i++)
        {
            int curr = min(prev1, prev2) + cost[i];
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }
};