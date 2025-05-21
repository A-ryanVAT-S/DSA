// Leetcode 64. Minimum Path Sum
// you have to find a path from the top left to the bottom right, which minimizes the sum of the numbers along the path.
// You can only move either down or right at any point in time.

// bottom up approach
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = grid[i][j];
                }
                else
                {
                    int a = (i > 0) ? dp[i - 1][j] : INT_MAX;
                    int b = (j > 0) ? dp[i][j - 1] : INT_MAX;
                    dp[i][j] = min(a, b) + grid[i][j];
                }
            }
        }
        return dp[row - 1][col - 1];
    }
};

// space optimized bottom up approach
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> prev(col, 0);
        for (int i = 0; i < row; i++)
        {
            vector<int> curr(col, 0);
            for (int j = 0; j < col; j++)
            {
                if (i == 0 && j == 0)
                {
                    curr[j] = grid[i][j];
                }
                else
                {
                    int up = (i > 0) ? prev[j] : INT_MAX;
                    int left = (j > 0) ? curr[j - 1] : INT_MAX;
                    curr[j] = min(up, left) + grid[i][j];
                }
            }
            prev = curr;
        }
        return prev[col - 1];
    }
};

// top down approach
class Solution
{
public:
    int minPathSumUtil(vector<vector<int>> &grid, int i, int j, int row, int col, vector<vector<int>> &dp)
    {
        if (i == row - 1 && j == col - 1)
        {
            return grid[i][j];
        }
        if (i >= row || j >= col)
        {
            return INT_MAX;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int a = minPathSumUtil(grid, i + 1, j, row, col, dp);
        int b = minPathSumUtil(grid, i, j + 1, row, col, dp);
        return dp[i][j] = min(a, b) + grid[i][j];
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        return minPathSumUtil(grid, 0, 0, row, col, dp);
    }
};
