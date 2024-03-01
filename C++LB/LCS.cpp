#include<bits/stdc++.h>
using namespace std;

int LCS(string &s, string &t, int i, int j, vector<vector<int>>& dp) {
    if (i == s.length()) {
        return 0;
    }
    if (j == t.length()) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans = 0;
    if (s[i] == t[j]) {
        ans = 1 + LCS(s, t, i + 1, j + 1, dp);
    } else {
        ans = max(LCS(s, t, i + 1, j, dp), LCS(s, t, i, j + 1, dp));
    }
    return dp[i][j] = ans;
}

int longestCommonSubsequence(string s, string t) {
    int m = s.length();
    int n = t.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return LCS(s, t, 0, 0, dp);
}
int lcs(string &s,string &t){
    int m=s.length();
    int n=t.length();

    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            int ans = 0;
            if (s[i] == t[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            else
            {
                ans = max(dp[i + 1][ j],dp[i][j + 1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int main() {
    string s = "abcd";
    string t = "xabz";
    cout << longestCommonSubsequence(s, t) << endl;
    cout<<lcs(s,t)<<endl;

    return 0;
}
