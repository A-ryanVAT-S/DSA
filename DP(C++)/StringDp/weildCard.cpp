// we have given a pattern string and a text string
// we have to say whether the pattern string is present in the text string or not
// the pattern string can contain * and ?
//? can be replaced by any character
//* can be replaced by any string
// we have to find whether the pattern string is present in the text string or not

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();

        vector<bool> prev(m + 1, false);
        vector<bool> curr(m + 1, false);
        prev[0] = true;
        for (int j = 1; j <= m; j++)
        {
            if (p[j - 1] == '*')
                prev[j] = prev[j - 1];
            else
                break;
        }
        for (int i = 1; i <= n; i++)
        {
            curr[0] = false;
            for (int j = 1; j <= m; j++)
            {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                {
                    curr[j] = prev[j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    curr[j] = prev[j] || curr[j - 1];
                }
                else
                {
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};
