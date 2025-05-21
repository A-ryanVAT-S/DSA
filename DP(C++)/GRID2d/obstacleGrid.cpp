// obstacle grid problem
// you are given a grid of size m x n, where each cell can be either an obstacle or a free cell.
// The top-left cell is the starting point, and the bottom-right cell is the destination.
// You can only move down or right.
// Your task is to find the number of unique paths from the top-left cell to the bottom-right cell,avoiding obstacles.

// top-down approach
class Solution
{
public:
    int solveDP(vector<vector<int>> &dp, vector<vector<int>> &oG, int m, int n)
    {
        if (m == 0 && n == 0)
            return 1;
        if (m < 0 || n < 0)
            return 0;
        if (oG[m][n] == 1)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        dp[m][n] = solveDP(dp, oG, m - 1, n) + solveDP(dp, oG, m, n - 1);
        return dp[m][n];
    }

    int uniquePathsWithObstacles(vector<vector<int>> &oG)
    {
        if (oG[0][0] == 1)
            return 0;
        int m = oG.size();
        int n = oG[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = solveDP(dp, oG, m - 1, n - 1);
        return ans;
    }
};

// bottom-up approach
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &oG)
    {
        int m = oG.size();
        int n = oG[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (oG[0][0] == 1 || oG[m - 1][n - 1] == 1)
            return 0;
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (oG[i][j] == 1)
                    dp[i][j] = 0;
                else
                {
                    if (i > 0)
                        dp[i][j] += dp[i - 1][j];
                    if (j > 0)
                        dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// space optimization
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &oG)
    {
        int m = oG.size();
        int n = oG[0].size();
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        if (oG[0][0] == 1 || oG[m - 1][n - 1] == 1)
            return 0;
        prev[0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (oG[i][j] == 1)
                    curr[j] = 0;
                else
                {
                    if (i > 0)
                        curr[j] += prev[j];
                    if (j > 0)
                        curr[j] += curr[j - 1];
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
}