// //You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.
// Each time, you can climb either one step or two steps.
// You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.

// simple(tle)
#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int countWays(int i)
{
    if (i <= 1)
        return 1;
    return (countWays(i - 1) % MOD + countWays(i - 2) % MOD) % MOD;
}

int countDistinctWays(int n)
{
    return countWays(n);
}

// topdown
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int DP(int i, vector<int> &dp)
{
    if (i <= 1)
        return 1;
    if (dp[i] == -1)
    {
        dp[i] = (DP(i - 1, dp) % MOD + DP(i - 2, dp) % MOD) % MOD;
    }
    return dp[i];
}
int countDistinctWays(int n)
{
    vector<int> dp(n + 1, -1);
    return DP(n, dp);
}

// bottomup
int countDistinctWays(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] % MOD + dp[i - 2] % MOD) % MOD;
    }
    return dp[n];
}

// space optimized
int countDistinctWays(int n)
{
    if (n <= 1)
        return 1;
    int prev2 = 1;
    int prev1 = 1;
    for (int i = 2; i <= n; i++)
    {
        int curr = (prev1 % MOD + prev2 % MOD) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}