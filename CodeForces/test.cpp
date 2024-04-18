//****** Rugung Daimary *********
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // increasing                                                                                            //  greater<int> //for decreasing
// for multi_set ,     use less_equal<int>
//  find_by_order(value at index k), order_of_key(no of elments smaller than,k)
using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define INF 1e18
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
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
void _print(unordered_set<T> v)
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
template <class T>
void _print(unordered_multiset<T> v)
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
template <class T, class V>
void _print(unordered_map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(unordered_multimap<T, V> v)
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
int hcf(int a, int b) { return (b == 0 ? a : hcf(b, a % b)); }
int lcm(int x, int y) { return (x * y) / hcf(x, y); }
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
int pow(int x, int y, int p = 1e9 + 7) // time complexity O(log(min(x,y)))
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
map<int, vector<int>> factor(int x)
{
    map<int, vector<int>> f;
    for (int prime = 2; prime * prime <= x; ++prime)
    {
        if (x % prime == 0)
        {
            f[prime].push_back(prime);
            if (prime * prime != x)
            {
                f[x].push_back(x / prime);
            }
        }
    }
    return f;
}
bool cmp(const pair<int, int> &a, const pair<int, int> &b) // sorting for priority queue(reverse of vector<pair<int,int>> sorting)
{
    if (a.first == b.first)
    {
        return a.second < b.second; // Sort ascending by second parameter when first parameters are equal
    }
    return a.first > b.first; // Otherwise, sort descending by first parameter
}
map<char, int> findSubstring(string &s)
{ // finding substring of same character of maximum length
    map<char, int> mp;

    int count = 1;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            count++;
        }
        else
        {
            mp[s[i]] = max(mp[s[i]], count);
            count = 1;
        }
        mp[s[i]] = max(mp[s[i]], count); // for last character
    }
    return mp;
}
ll arraySum(vector<int>&v){
    int acc=accumulate(v.begin(),v.end(),0);//third parameter is that from which no you wanna start with
    return acc;
}
vector<int> getDivisors(int n)
{
    vector<int> divisors;
    int sqrt_n = (int)(sqrt(n));

    for (int i = 1; i <= sqrt_n; ++i)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            if (i != n / i)
            {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

void solve()
{

    
    
     int n, m, k;
     cin >> n >> m >> k;
     vi a(n);
     vi b(m);
     map<int, int> slideWind;
     for (int i = 0; i < n; i++)
     {
         cin >> a[i];
     }
     for (int i = 0; i < m; i++)
     {
         cin >> b[i];
     }
     ll count = 0;

     for (int i = 0; i < m; i++)
     {
         slideWind[a[i]]++;
     }
     map<int,int>mp;
     for(int i=0;i<m;i++){
         mp[b[i]]++;
     }
     debug(slideWind);
     int i = 0, j = m - 1;

     while (j < n)
     {
         int cnt = 0;
         for (auto x : mp)
         {
             if (slideWind.find(x.first) != slideWind.end())
             {
                 cnt+=min(slideWind[x.first],mp[x.first]);
             }
             if (cnt >= k)
             {
                 count++;
                 break;
             }
         }
         slideWind[a[i]]--;
         if (slideWind[a[i]] == 0)
         {
             slideWind.erase(a[i]);
         }
         i++;
         j++;
         slideWind[a[j]]++;
         // if (slideWind.find(a[i]) != slideWind.end()){

         // }
     }
     cout << count << endl;
     return;
     
}
int main()
{
#ifndef ONLINE_JUDGE

    freopen("Output.txt", "w", stdout);
    freopen("Input.txt", "r", stdin);
    freopen("Error.txt", "w", stderr);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
