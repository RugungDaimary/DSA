
//******************************************************************
//             Rugung Daimary
//******************************************************************
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // strictly increasing                                                                                            //  greater<int> //for decreasing
//                      (less_equal<int>)=> for increasing(multi_set)
// =>find_by_order(value at index k), order_of_key(no of elments smaller than(k))
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MOD 1000000007
#define INF 1e18
#define nline '\n'
#define ll long long
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define vi vector<int>
#define vll vector<long long>
#define ff first
#define ss second
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define MOD1 1000000009
#define MOD2 100000007
#define base1 26
#define base2 27
/*--------------------------------------------------------------------------------------------------------------------------*/
int hcf(int a, int b) { return (b == 0 ? a : hcf(b, a % b)); }
int lcm(int x, int y) { return (x * y) / hcf(x, y); }
int gcd(int a, int b){while (b != 0){int temp = b;b = a % b;a = temp;}return a;}
long long expo(long long a, long long b, long long mod=MOD)
{
    a = a % mod;
    if (b == 0)
    {
        return 1;
    }
    long long half = expo(a, b / 2, mod);
    if (b&1)
    {
        return (a%mod * half%mod *half%mod) % mod;
    }
    else
    {
        return (half%mod * half%mod) % mod;
    }
}
struct Hashing
{
    string s;
    int n;
    vector<ll> hashVal1, hashVal2;
    vector<ll> pow1, pow2;
    vector<ll> invPow1, invPow2;
    Hashing(string a)
    {
        s = a;
        n = s.length();
        hashVal1.resize(n);
        hashVal2.resize(n);
        pow1.resize(n + 1);
        pow2.resize(n + 1);
        invPow1.resize(n + 1);
        invPow2.resize(n + 1);

        // Compute powers and inverse powers of bases
        pow1[0] = pow2[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            pow1[i] = (pow1[i - 1] * base1) % MOD1;
            pow2[i] = (pow2[i - 1] * base2) % MOD2;
        }
        invPow1[n] = expo(pow1[n], MOD1 - 2, MOD1);
        invPow2[n] = expo(pow2[n], MOD2 - 2, MOD2);
        for (int i = n - 1; i >= 0; i--)
        {
            invPow1[i] = (invPow1[i + 1] * base1) % MOD1;
            invPow2[i] = (invPow2[i + 1] * base2) % MOD2;
        }

        // Compute hash values
        for (int i = 0; i < n; i++)
        {
            hashVal1[i] = ((s[i] - '0' + 1LL) * pow1[i]) % MOD1;
            if (i > 0)
                hashVal1[i] = (hashVal1[i] + hashVal1[i - 1]) % MOD1;

            hashVal2[i] = ((s[i] - '0' + 1LL) * pow2[i]) % MOD2;
            if (i > 0)
                hashVal2[i] = (hashVal2[i] + hashVal2[i - 1]) % MOD2;
        }
    }

    pair<ll, ll> substringHash(int l, int r) // O(1)
    {
        ll hash1 = hashVal1[r];
        ll hash2 = hashVal2[r];
        if (l > 0)
        {
            hash1 = (hash1 - hashVal1[l - 1] + MOD1) % MOD1;
            hash2 = (hash2 - hashVal2[l - 1] + MOD2) % MOD2;
        }
        hash1 = (hash1 * invPow1[l]) % MOD1;
        hash2 = (hash2 * invPow2[l]) % MOD2;
        return {hash1, hash2};
    }

    int findSubstring(string &pattern)
    {
        int m = pattern.length();
        if (m > n)
            return -1;

        // Compute the hash of the needle
        Hashing needleHasher(pattern);
        pair<ll, ll> needleHash = needleHasher.substringHash(0, m - 1);

        // Check each substring of length m in the haystack
        for (int i = 0; i <= n - m; i++)
        {
            pair<ll, ll> currentHash = substringHash(i, i + m - 1);
            if (currentHash == needleHash)
                return i;
        }
        return -1;
    }
};

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

struct cmp // (all the logic  here will be reverse for Priority Queue)
{
    // sort(v.begin(),v.end(),cmp()); //for vector
    // priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq; //for PQ

    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second; // Sort in decreasing order  by second parameter
        }
        return a.first < b.first; //sort in increasing order by first parameter
    }
};
/*--------------------------------------------------------------------------------------------------------------------------*/
void solve()
{
    
    int n;
    cin>>n;
    vector<vector<int>>a(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }

    }
    int op=0;
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            int mini=0;
            for(int i=0;i<n;i++){
                if(row+i<n && col+i<n && a[row+i][col+i]<0){
                    mini=min(mini,a[row+i][col+i]);
                    a[row+i][col+i]=1;
                }
            }
            op+=abs(mini);
        }
    }
   
    cout<<op<<endl;
}
int32_t main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
};