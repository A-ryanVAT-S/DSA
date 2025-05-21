// falling path dp problem
// we have a grid of size n*m we can move down and left or down and right or down
// we need to find the minimum path sum from top to bottom

// top down does not work as we have to check the left and right elements so we will use bottom up dp as stack overflow many places
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Initialize first row
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = matrix[0][j];
        }

        // Fill dp table
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int left = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;
                int up = dp[i - 1][j];
                int right = (j < n - 1) ? dp[i - 1][j + 1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({left, up, right});
            }
        }

        // Find minimum in the last row
        int ans = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            ans = min(ans, dp[m - 1][j]);
        }

        return ans;
    }
};
