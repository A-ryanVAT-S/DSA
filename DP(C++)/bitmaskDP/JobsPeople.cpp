// Let there be N workers and N jobs. Any worker can be assigned to perform any job,
// incurring some cost that may vary depending on the work-job assignment.
// It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in
// such a way that the total cost of the assignment is minimized.
// Input Format
// Number of workers and job: N
// Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.
// Sample Input
// 4
// 9 2 7 8
// 6 4 3 7
// 5 8 1 8
// 7 6 9 4

// Sample Output
// 13
// Constraints
// N <= 20

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

// Recursive function to assign jobs
int solve(int i, int mask, int n, const vector<vector<int>> &cost, vector<vector<int>> &dp)
{
    if (i == n)
        return 0; // All persons assigned

    if (dp[i][mask] != -1)
        return dp[i][mask];

    int answer = INT_MAX;

    // Try assigning each available job
    for (int j = 0; j < n; j++)
    {
        if (mask & (1 << j))
        {                                   // if job j is still available
            int new_mask = mask ^ (1 << j); // mark job j as assigned
            int current_cost = cost[j][i] + solve(i + 1, new_mask, n, cost, dp);
            answer = min(answer, current_cost);
        }
    }

    return dp[i][mask] = answer;
}

int main()
{
    int n;
    cin >> n;

    // Step 1: Input cost matrix
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    // Step 2: Create dp table and initialize to -1
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    // Step 3: Call solve from person 0 with all jobs available (mask = 2^n - 1)
    int result = solve(0, (1 << n) - 1, n, cost, dp);

    // Step 4: Output result
    cout << result << '\n';

    return 0;
}
