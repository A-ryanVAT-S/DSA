// Ninja has a fence with 'N' posts and 'K' colors available.
// The task is to paint the fence such that no more than two adjacent posts have the same color.
// Your goal is to determine the number of ways to paint the fence while satisfying this condition.
// The result should be printed modulo 10^9 + 7.
// Example:Input: 'N' = 3, 'K' = 2  Output: 6
// Say we have the colors with the numbers 1 and 0. We can paint the fence with 3 posts with the following different combinations:
// 110, 001, 101, 100, 010, 011.110, 001, 101, 100, 010, 011.

#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int solveDP(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;
    if (n == 2)
        return (k * k) % mod;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = ((k - 1) * (solveDP(n - 1, k, dp) + solveDP(n - 2, k, dp))) % mod;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 1, -1);
    cout << solveDP(n, k, dp) << endl;
    return 0;
}

// bottom up approach
int solveDP(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return (k * k) % mod;
    vector<int> dp(n + 1, -1);
    dp[1] = k;
    dp[2] = (k * k) % mod;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % mod;
    }
    return dp[n];
}

// space optimized approach
int solveDP(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return (k * k) % mod;
    int prev1 = k;
    int prev2 = (k * k) % mod;
    for (int i = 3; i <= n; i++)
    {
        int curr = ((k - 1) * (prev1 + prev2)) % mod;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}