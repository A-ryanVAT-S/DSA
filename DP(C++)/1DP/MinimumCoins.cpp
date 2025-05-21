// //You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum.
// You have to tell the minimum number of elements you have to take to reach the target sum ‘X’.
// Note:
// You have an infinite number of elements of each type.

#include <bits/stdc++.h>
using namespace std;
int minimumElements(vector<int> &num, int x)
{
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - num[j]] + 1);
            }
        }
    }
    return dp[x] == INT_MAX ? -1 : dp[x];
}

// explanation of the code:

// Recursive Approach
// Time Complexity: Exponential
// Space Complexity: O(target) (due to recursion stack)
int minCoinsRecursive(vector<int> &coins, int n, int target)
{
    // Base case: If target is 0, no coins are needed
    if (target == 0)
        return 0;

    // If target becomes negative, return a large value (infinity)
    if (target < 0)
        return INT_MAX;

    int minCoins = INT_MAX;

    // Try every coin
    for (int i = 0; i < n; i++)
    {
        int res = minCoinsRecursive(coins, n, target - coins[i]);
        if (res != INT_MAX)
        {
            minCoins = min(minCoins, res + 1);
        }
    }

    return minCoins;
}

// Top-Down Approach (Memoization)
// Time Complexity: O(n * target)
// Space Complexity: O(target) (for dp array + recursion stack)
int minCoinsTopDown(vector<int> &coins, int n, int target, vector<int> &dp)
{
    // Base case: If target is 0, no coins are needed
    if (target == 0)
        return 0;

    // If target becomes negative, return a large value (infinity)
    if (target < 0)
        return INT_MAX;

    // If already computed, return the stored result
    if (dp[target] != -1)
        return dp[target];

    int minCoins = INT_MAX;

    // Try every coin
    for (int i = 0; i < n; i++)
    {
        int res = minCoinsTopDown(coins, n, target - coins[i], dp);
        if (res != INT_MAX)
        {
            minCoins = min(minCoins, res + 1);
        }
    }

    // Store the result in dp array
    dp[target] = minCoins;
    return dp[target];
}

// Bottom-Up Approach (Tabulation)
// Time Complexity: O(n * target)
// Space Complexity: O(target)
int minCoinsBottomUp(vector<int> &coins, int n, int target)
{
    vector<int> dp(target + 1, INT_MAX);

    // Base case: 0 coins are needed to make sum 0
    dp[0] = 0;

    // Build the dp array iteratively
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[target] == INT_MAX ? -1 : dp[target];
}

int main()
{
    vector<int> coins = {1, 2, 5}; // Example coins
    int target = 11;               // Example target

    // Recursive Approach
    int resultRecursive = minCoinsRecursive(coins, coins.size(), target);
    if (resultRecursive == INT_MAX)
    {
        cout << "Recursive: Not possible to form the target sum." << endl;
    }
    else
    {
        cout << "Recursive: Minimum coins required: " << resultRecursive << endl;
    }

    // Top-Down Approach
    vector<int> dp(target + 1, -1);
    int resultTopDown = minCoinsTopDown(coins, coins.size(), target, dp);
    if (resultTopDown == INT_MAX)
    {
        cout << "Top-Down: Not possible to form the target sum." << endl;
    }
    else
    {
        cout << "Top-Down: Minimum coins required: " << resultTopDown << endl;
    }

    // Bottom-Up Approach
    int resultBottomUp = minCoinsBottomUp(coins, coins.size(), target);
    if (resultBottomUp == -1)
    {
        cout << "Bottom-Up: Not possible to form the target sum." << endl;
    }
    else
    {
        cout << "Bottom-Up: Minimum coins required: " << resultBottomUp << endl;
    }

    return 0;
}

// //Explanation of Changes:
// Recursive Approach:

// Added a function minCoinsRecursive to solve the problem using recursion.
// This approach is simple but inefficient due to overlapping subproblems.
// It has exponential time complexity and can lead to stack overflow for large inputs.
// The base case checks if the target is 0 (no coins needed) or negative (impossible).
// The function iterates through all coins and recursively calls itself with the reduced target.    \
// It keeps track of the minimum number of coins needed.
// The result is returned as the minimum number of coins needed to form the target sum.
// The function returns INT_MAX if it's not possible to form the target sum with the given coins.
// This is a naive approach and not recommended for large inputs due to its exponential time complexity.

// Top-Down Approach:

// Added a function minCoinsTopDown that uses memoization to optimize the recursive approach.
// A dp array is used to store results of subproblems.

// Bottom-Up Approach:

// Added a function minCoinsBottomUp that uses tabulation to iteratively solve the problem.
// This is the most efficient approach in terms of time and space.
// The dp array is built iteratively, ensuring all subproblems are solved before solving the main problem.
// The function returns the minimum number of coins needed to form the target sum.

// Why Bottom-Up Works:
// It avoids recursion and stack overflow issues.
// It builds the solution iteratively, ensuring all subproblems are solved before solving the main problem.
// It has optimal time and space complexity for this type of problem.