//
// 115. Distinct Subsequences
// we have to find the number of distinct subsequences of string t in string s.

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int l1 = s.size(), l2 = t.size();
        vector<unsigned long long> prev(l2 + 1, 0), curr(l2 + 1, 0);
        prev[0] = curr[0] = 1;

        for (int i = 1; i <= l1; i++)
        {
            for (int j = l2; j >= 1; j--)
            {
                if (s[i - 1] == t[j - 1])
                {
                    curr[j] = prev[j] + prev[j - 1];
                }
                else
                {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }
        return prev[l2];
    }
};

// In string DP, base cases usually answer the question:

// "What is the result when one or both strings are empty?"

// Let’s say you’re solving a 2D DP where:

// dp[i][j] = min operations to convert first i characters of word1 to first j characters of word2

// Then the base cases are:

// 🔹 dp[0][j] = j
// This means: you’re converting an empty word1 into first j characters of word2

// So, you need j insertions

// 🔹 dp[i][0] = i
// This means: you’re converting the first i characters of word1 into an empty word2

// So, you need i deletions

// These base cases fill the first row and first column of the DP table.