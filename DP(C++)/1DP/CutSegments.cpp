// Problem statement
// You are given an integer ‘N’ denoting the length of the rod. You need to
// determine the maximum number of segments you can make of this rod provided that
// each segment should be of the length 'X', 'Y', or 'Z'.

// top down approach
#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x, int y, int z, vector<int> &dp)
{
    if (n < 0)
        return INT_MIN;
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    dp[n] = max({solve(n - x, x, y, z, dp) + 1, solve(n - y, x, y, z, dp) + 1, solve(n - z, x, y, z, dp) + 1});
    return dp[n];
}

int cutSegments(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    int ans = solve(n, x, y, z, dp);
    return max(0, ans);
}

// bottom up approach
int cutSegments(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
            dp[i] = max(dp[i], dp[i - x] + 1);
        if (i - y >= 0)
            dp[i] = max(dp[i], dp[i - y] + 1);
        if (i - z >= 0)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }
    return max(0, dp[n]);
}
