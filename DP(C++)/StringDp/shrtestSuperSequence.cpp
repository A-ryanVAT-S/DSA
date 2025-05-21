// supersequence
//  Given two strings str1 and str2, find the length of their shortest supersequence.
// eg: str1 = "AGGTAB", str2 = "GXTXAYB"
//  Output: 9 string = "AGXGTXAYB"

// for length
// length = size of a+ size of b- lcs(a,b)

// for printing
//  we need to find the lcs and then we can use the lcs to find the supersequence using backtracking
// return as a string

string SSS(vector<vector<int>> &dp, string &s1, string &s2)
{
    int i = s1.size();
    int j = s2.size();
    string ans;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans += s1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += s1[i - 1];
                i--;
            }
            else
            {
                ans += s2[j - 1];
                j--;
            }
        }
    }
    while (i > 0)
    {
        ans += s1[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += s2[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}