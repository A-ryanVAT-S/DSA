// There are N stones, numbered 1,2,…,N. For each
// i (1≤i≤N), the height of Stone i is hi.There is a frog who is initially on Stone 1
// He will repeat the following action some number of times to reach Stone N:
// If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2. Here, a cost of
// ∣h i​−h j ∣ is incurred, where j is the stone to land on.
// Find the minimum possible total cost incurred before the frog reaches Stone
// N.

#include <bits/stdc++.h>
using namespace std;

int solveDP(int n, vector<int> &dp, vector<int> &arr)
{
    if (n == 0)
        return arr[0];
    if (n == 1)
        return abs(arr[1] - arr[0]);
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = min(solveDP(n - 1, dp, arr) + abs(arr[n] - arr[n - 1]), solveDP(n - 2, dp, arr) + abs(arr[n] - arr[n - 2]));
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solveDP(n - 1, dp, arr) << endl;
    return 0;
}