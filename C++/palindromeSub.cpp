// Count the no of substrings that are palindrome in string s
#include <bits/stdc++.h>
using namespace std;

// BLUEPRINT
int palindromeSubstring(string &s)
{
    int n = s.length();
    int cnt = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    // dp[i][j]=true means the substirng from i to j inclusive index is palindrome
    // all single length substring are palindrome
    // to check the 2 length substirng , if(i+1==j && dp[i][j]) then is palindrome

    for (int L = 1; L <= n; L++)
    {
        for (int i = 0; i + L - 1 < n; i++)
        { // substring form i to j
            int j = i + L - 1;
            if (i == j) // one length string
            {
                dp[i][j] = true;
            }
            else if (i + 1 == j)
            { // 2 length string
                dp[i][j] = (s[i] == s[j]);
            }
            else
            { // greater than 2 length
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
            if (dp[i][j])
                cnt++;
        }
    }
    return cnt;
}
int main()
{

    return 0;
}