#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9 + 7;

int solve(vector<int> &v, int n, int m)
{
    vector<int> dp(m + 1, 0), prev_dp(m + 1, 0), cr(n, -1);

    // Base cases when v[0] == 0
    if (v[0] == 0)
    {
        for (int i = 1; i <= m; ++i)
        {
            dp[i] = 1;
        }
    }
    else
    {
        dp[v[0]] = 1;
    }

    for (int idx = 1; idx < n; ++idx)
    {
        prev_dp = dp;
        fill(dp.begin(), dp.end(), 0); // Reset dp for the current idx

        for (int i = 1; i <= m; ++i)
        {
            if (v[idx] != 0 && v[idx] != i)
                continue;
            if (i > 1)
                dp[i] = (dp[i] + prev_dp[i - 1]) % mod;
            dp[i] = (dp[i] + prev_dp[i]) % mod;
            if (i < m)
                dp[i] = (dp[i] + prev_dp[i + 1]) % mod;
        }
    }

    ll result = 0;
    if (v[n - 1] == 0)
    {
        for (int i = 1; i <= m; ++i)
        {
            result = (result + dp[i]) % mod;
        }
    }
    else
    {
        result = dp[v[n - 1]];
    }

    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << solve(v, n, m) << endl;
}
