// knapsack are problems that can be solved using dynamic programming
//  0-1 knapsack problem
//  in it we have to find the maximum value of items that can be put in a knapsack of given capacity
// given weights and values of items, we can either take or not take the item

// top-down approach
int knapsack(int n, int w, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    if (n == 0 || w == 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (wt[n - 1] <= w)
    {
        return dp[n][w] = max(knapsack(n - 1, w, val, wt, dp), knapsack(n - 1, w - wt[n - 1], val, wt, dp) + val[n - 1]);
    }
    else
    {
        return dp[n][w] = knapsack(n - 1, w, val, wt, dp);
    }
}

// Memoization Approach
#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}

// space optimization
int knapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
    vector<int> prev(w + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        vector<int> curr(w + 1, 0);
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] <= j)
            {
                curr[j] = max(prev[j], prev[j - wt[i - 1]] + val[i - 1]);
            }
            else
            {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    return prev[w];
}
// single array dp
int knapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
    vector<int> dp(w + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = w; j >= wt[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
        }
    }
    return dp[w];
}