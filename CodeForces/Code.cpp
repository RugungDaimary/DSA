
#include <bits/stdc++.h>
#include <numeric>
#include<cmath>
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define N 1e9 + 7
#define INF 1e18
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
    cerr << "\n";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

int max(int a, int b) { return a > b ? a : b; }

int min(int a, int b) { return a < b ? a : b; }

int hcf(int a, int b)
{
    return (b == 0 ? a : hcf(b, a % b));
}

int lcm(int x, int y)
{
    return (x * y) / hcf(x, y);
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int pow(int x, int y, int p = 1e9 + 7)
{
    int res = 1;

    while (y > 0)
    {
        if (y % 2 == 1)
        {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res % p;
}
bool cmp(const pair<int, int> &a, const pair<int, int> &b)//sorting for priority queue(reverse of vector<pair<int,int>> sorting)
{
    if (a.first == b.first)
    {
        return a.second < b.second; // Sort ascending by second parameter when first parameters are equal
    }
    return a.first > b.first; // Otherwise, sort descending by first parameter
}

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    string temp = "";
    temp += a[0];
    ll ans = 1;
    bool flag = false;
    for (int i = 0; i <= n - 2; i++) {
        if (a[i + 1] == b[i]) {
            temp += a[i + 1];
            ans++;
        } else if (a[i + 1] == '0') {
            if (ans > 1) ans--;
            temp += a[i + 1];

        } else {
            temp += b.substr(i);
            flag = true;
            break;
        }
    }
    if (!flag) {
        temp += b[n - 1];
    }
    cout << temp << endl;
    cout << ans << endl;


}



int main()
{

#ifndef ONLINE_JUDGE

    freopen("Output.txt", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Error.txt", "w", stderr);
#endif

    int t;
    cin >> t;
    while (t--) {
        solve();

    }
    return 0;
}


