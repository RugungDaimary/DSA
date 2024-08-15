#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
using namespace std;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int common = 0;
    for (int i = a; i <= b; i++)
    {
        if (i >= c && i <= d)
        {
            common++;
        }
    }
    //    cout<<common<<endl;
    if (a > c && b < d || c > a && d < b)
    {
        cout << common + 1 << endl;
    }
    else if ((c > a && c < b && d > a && d > b) || (c < a && c < b && d > a && d < b) || (a > c && a < d && b > c && b > d) || (a < c && a < d && b > c && b < d))
    {
        cout << common + 1 << endl;
    }
    else if (a == c && b == d)
    {
        cout << common - 1 << endl;
    }
    else if ((c > a && c < b && d > a && d == b) || (c == a && c < b && d > a && d < b) || (a == c && a < d && b > c && b < d) || (a > c && a < d && b > c && b == d))
    {
        cout << common << endl;
    }
    else if ((b == c) || (a == d))
    {
        cout << 1 << endl;
    }
    else if (common == 0)
    {
        cout<<1<<endl;
    }
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}