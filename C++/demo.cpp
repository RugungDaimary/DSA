#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
void fun(int i, char op, int n, vi &a, vi &arr)
{
    for (int j = i + 1; j < n; j++)
    {
        int val = (a[i] ^ a[j]);
        if (op == '+')
        {
            arr[val]++;
        }
        else
        {
            arr[val]--;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vi arr(20);
    fill(arr.begin(), arr.end(), 0);
    ll cnt = 0;
    for (int i = 1; i <= n - 2; i++)
    {
        fun(i, '+', n, a, arr);
    }
    ll ans = 0;
    for (int j = 1; j <= n - 3; j++)
    {
        fun(j, '-', n, a, arr);
        for (int i = 0; i < j; i++)
        {
            int val = a[i] ^ a[j];
            if(val!=0)
            ans += arr[val];
        }
    }

    cout << ans * 24 << endl;
}
int main()
{
    solve();

    return 0;
}