// in it we have to find the maximum profit we can make by selling the stock at different times
//  we can buy and sell the stock multiple times,but can hold only one stock at a time

// topdown approach
class Solution
{
public:
    int solve(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (ind == prices.size())
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        if (buy)
        {
            return dp[ind][buy] = max(-prices[ind] + solve(ind + 1, 0, prices, dp), 0 + solve(ind + 1, 1, prices, dp));
        }
        else
        {
            return dp[ind][buy] = max(prices[ind] + solve(ind + 1, 1, prices, dp), 0 + solve(ind + 1, 0, prices, dp));
        }
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};

// space optimization
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<long long> ahead(2, 0);
        vector<long long> curr(2, 0);
        for (int ind = n - 1; ind >= 0; ind--) // opposite loop of topdown(simple h jo
        // topdown mai hota hai uska ulta bottom up mai hota hai)
        {
            for (int buy = 0; buy <= 1; buy++) // buy = 0 means we are selling the stock and buy = 1 means we are buying the stock
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);
                }
                else
                {
                    profit = max(prices[ind] + ahead[1], 0 + ahead[0]);
                }
                curr[buy] = profit; // profit is the maximum profit we can make by selling the stock at different times
            }
            ahead = curr; // we are not using the curr array anymore so we can use ahead array to store the values of curr
        }
        return ahead[1];
    }
};
// more better space optimization with variable only instead of vector
class Solution
{
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        long long ahead0 = 0;
        long long ahead1 = 0;
        for (int ind = n - 1; ind >= 0; ind--)
        {
            long long curr0 = 0;
            long long curr1 = 0;
            curr1 = max(-prices[ind] + ahead1, 0 + ahead0);
            curr0 = max(prices[ind] + ahead0, 0 + ahead1);
            ahead0 = curr0;
            ahead1 = curr1;
        }
        return ahead1;
    }
};