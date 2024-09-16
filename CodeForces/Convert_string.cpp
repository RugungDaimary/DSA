
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
ll pow(ll x, ll y, ll p = 1e9 + 7)
{
    if (y == 0)
    {
        return 1;
    }
    ll half = pow(x, y / 2, p);
    half = (half * half) % p;
    // If y is odd, multiply by x once more
    if (y % 2 == 1)
    {
        half = (half * x) % p;
    }

    return half;
}
long long expo(long long base, long long exp, long long mod)
{
    base = base % mod;
    // Base case: when exponent is 0
    if (exp == 0)
    {
        return 1;
    }
    // If exponent is odd, multiply base with result of expo(base, exp-1, mod)
    if (exp % 2 == 1)
    {
        return (base * expo(base, exp - 1, mod)) % mod;
    }
    else
    {
        // If exponent is even, compute the result for half of the exponent
        long long half = expo(base, exp / 2, mod);
        return (half%mod * half%mod) % mod;
    }
}
struct Hashing
{
    string s;
    int n;
    vector<ll> hashValues1, hashValues2;
    vector<ll> powersOfBase1, powersOfBase2;
    vector<ll> inversePowersOfBase1, inversePowersOfBase2;
    Hashing(string a)
    {
        s = a;
        n = s.length();
        hashValues1.resize(n);
        hashValues2.resize(n);
        powersOfBase1.resize(n + 1);
        powersOfBase2.resize(n + 1);
        inversePowersOfBase1.resize(n + 1);
        inversePowersOfBase2.resize(n + 1);

        // Compute powers and inverse powers of bases
        powersOfBase1[0] = powersOfBase2[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            powersOfBase1[i] = (powersOfBase1[i - 1] * base1) % MOD1;
            powersOfBase2[i] = (powersOfBase2[i - 1] * base2) % MOD2;
        }
        inversePowersOfBase1[n] = expo(powersOfBase1[n], MOD1 - 2, MOD1);
        inversePowersOfBase2[n] = expo(powersOfBase2[n], MOD2 - 2, MOD2);
        for (int i = n - 1; i >= 0; i--)
        {
            inversePowersOfBase1[i] = (inversePowersOfBase1[i + 1] * base1) % MOD1;
            inversePowersOfBase2[i] = (inversePowersOfBase2[i + 1] * base2) % MOD2;
        }

        // Compute hash values
        for (int i = 0; i < n; i++)
        {
            hashValues1[i] = ((s[i] - '0' + 1LL) * powersOfBase1[i]) % MOD1;
            if (i > 0)
                hashValues1[i] = (hashValues1[i] + hashValues1[i - 1]) % MOD1;

            hashValues2[i] = ((s[i] - '0' + 1LL) * powersOfBase2[i]) % MOD2;
            if (i > 0)
                hashValues2[i] = (hashValues2[i] + hashValues2[i - 1]) % MOD2;
        }
    }

    pair<ll, ll> substringHash(int l, int r) // O(1)
    {
        ll hash1 = hashValues1[r];
        ll hash2 = hashValues2[r];
        if (l > 0)
        {
            hash1 = (hash1 - hashValues1[l - 1] + MOD1) % MOD1;
            hash2 = (hash2 - hashValues2[l - 1] + MOD2) % MOD2;
        }
        hash1 = (hash1 * inversePowersOfBase1[l]) % MOD1;
        hash2 = (hash2 * inversePowersOfBase2[l]) % MOD2;
        return {hash1, hash2};
    }

    int containsSubstring(string pattern)
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

/*--------------------------------------------------------------------------------------------------------------------------*/
void solve()
{
    
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