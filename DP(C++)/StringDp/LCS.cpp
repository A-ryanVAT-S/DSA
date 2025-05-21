// for two strings what would be the longest common subsequence

#include <bits/stdc++.h>
using namespace std;

// topdown
int lcs(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + lcs(s1, s2, i - 1, j - 1, dp);
    }
    else
    {
        return dp[i][j] = max(lcs(s1, s2, i - 1, j, dp), lcs(s1, s2, i, j - 1, dp));
    }
}
// bottomup(we need to do shifting as base case of dp is tricky)
int longestCommonSubsequence(string text1, string text2)
{
    int s1 = text1.size();
    int s2 = text2.size();

    vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));
    // base case
    for (int i = 0; i <= s1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= s2; j++)
    {
        dp[0][j] = 0;
    }
    // fill the dp table
    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[s1][s2];
}

// space optimizedint
longestCommonSubsequence(string text1, string text2)
{
    int s1 = text1.size();
    int s2 = text2.size();

    vector<int> prev(s2 + 1, 0);
    vector<int> curr(s2 + 1, 0);

    for (int i = 1; i <= s1; i++)
    {
        for (int j = 1; j <= s2; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = max(curr[j - 1], prev[j]);
            }
        }
        prev = curr;
    }

    return prev[s2];
}