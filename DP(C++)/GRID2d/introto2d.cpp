// 2D DP or DP on a grid

#include <bits/stdc++.h>
using namespace std;

// basic idea:
// problem: count the number of ways to reach the bottom-right corner of a grid from the top-left corner

// 1. bottom-up approach
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // base case
    dp[0][0] = 1; // or some other base case
    // fill the dp table

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // dp[i][j] = dp[i-1][j] + dp[i][j-1];
            // or some other relation
        }
    }
    cout << dp[n][m] << endl;
}
// 2. top-down approach

int top_down(int i, int j, vector<vector<int>> &dp)
{
    // base case
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    // dp[i][j] = top_down(i - 1, j, dp) + top_down(i, j - 1, dp);
    // or some other relation
    return dp[i][j];
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << top_down(n, m, dp) << endl;
}

// 3. space optimization
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);
    // base case
    prev[0] = 1; // or some other base case
    // fill the dp table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // curr[j] = prev[j] + curr[j - 1];
            // or some other relation
        }
        prev = curr;
    }
    cout << prev[m] << endl;
}