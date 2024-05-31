
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define MOD1 1000000009
#define MOD2 100000007
#define base1 26
#define base2 27
typedef long long ll;
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
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
            hashValues1[i] = ((s[i] - 'a' + 1LL) * powersOfBase1[i]) % MOD1;
            if (i > 0)
                hashValues1[i] = (hashValues1[i] + hashValues1[i - 1]) % MOD1;

            hashValues2[i] = ((s[i] - 'a' + 1LL) * powersOfBase2[i]) % MOD2;
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

    int containsSubstring(string needle)
    {
        int m = needle.length();
        if (m > n)
            return -1;

        // Compute the hash of the needle
        Hashing needleHasher(needle);
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

int main()
{
    fastio();
    string text = "abxrcabddbhjwenwejroeicreo4ilktvoignjeabxrca";
    string pattern = "abdd";
    Hashing hasher(text);
    int index = hasher.containsSubstring(pattern);
    if (index != -1)
    {
        cout << " starting at index " << index << ".\n";
    }
    else
    {
        cout << "Not present\n";
    }

    return 0;
}

/*
// Priyansh Code
#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18

typedef long long ll;

ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}

struct Hashing
{
    string s;
    int n;
    int primes;
    vector<long long> hashPrimes = {1000000009, 100000007};

    const long long base = 31;
    vector<vector<long long>> hashValues;
    vector<vector<long long>> powersOfBase;
    vector<vector<long long>> inversePowersOfBase;
    Hashing(string a)
    {
        primes = (hashPrimes.size());
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = s.length();
        for (int i = 0; i < (hashPrimes.size()); i++)
        {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for (int j = 1; j <= n; j++)
            {
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = expo(powersOfBase[i][n], hashPrimes[i] - 2, hashPrimes[i]);
            for (int j = n - 1; j >= 0; j--)
            {
                inversePowersOfBase[i][j] = (inversePowersOfBase[i][j + 1] * base) % hashPrimes[i];
            }
        }
        for (int i = 0; i < (hashPrimes.size()); i++)
        {
            hashValues[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    vector<long long> substringHash(int l, int r) // O(1)
    {
        vector<long long> hash(primes);
        for (int i = 0; i < primes; i++)
        {
            long long val1 = hashValues[i][r];
            long long val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = (val1 - val2 + hashPrimes[i]) % hashPrimes[i];
            hash[i] = (hash[i] * inversePowersOfBase[i][l]) % hashPrimes[i];
        }
        return hash;
    }


};

int main()
{
    fastio();
    string s = "abxrcabddbhjwenwejroeic reo4ilktvoig njeabxrca";
    Hashing h(s);
    cout<<s.size()<<endl;

    vector<long long> hash = h.substringHash(0, 6);
    vector<long long> hash1 = h.substringHash(39, 45);

    for(auto i:hash)cout<<i<<" ";
    cout<<endl;
    for(auto i:hash1)cout<<i<<" ";


    return 0;
}

*/

/*

// Normal Robin Karp Code
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll base_1 = 26;
const ll MOD_1 = 1000000007;
const ll base_2 = 27;
const ll MOD_2 = 1000000033;

pair<ll, ll> hashPair(string s, ll n)
{
    ll hash1 = 0, hash2 = 0;
    ll factor1 = 1, factor2 = 1;

    for (ll i = n - 1; i >= 0; i--)
    {
        hash1 = (hash1 + (s[i] - 'a' + 1) * factor1) % MOD_1;
        factor1 = (factor1 * base_1) % MOD_1;
        hash2 = (hash2 + (s[i] - 'a' + 1) * factor2) % MOD_2;
        factor2 = (factor2 * base_2) % MOD_2;
    }

    return {hash1, hash2};
}

int strStr(string haystack, string needle)
{
    ll n = haystack.length(), m = needle.length();
    if (n < m)
        return -1;

    ll MAX_WEIGHT_1 = 1, MAX_WEIGHT_2 = 1;
    for (ll i = 0; i < m; i++)
    {
        MAX_WEIGHT_1 = (MAX_WEIGHT_1 * base_1) % MOD_1;
        MAX_WEIGHT_2 = (MAX_WEIGHT_2 * base_2) % MOD_2;
    }

    pair<ll, ll> hashNeedle = hashPair(needle, m);
    pair<ll, ll> hashHay = {0, 0};

    for (ll i = 0; i < n - m + 1; i++)
    {
        if (i == 0)
        {
            hashHay = hashPair(haystack, m);
        }
        else
        {
            hashHay.first = (hashHay.first * base_1 - (haystack[i - 1] - 'a' + 1) * MAX_WEIGHT_1 % MOD_1 + MOD_1) % MOD_1;
            hashHay.first = (hashHay.first + (haystack[i + m - 1] - 'a' + 1)) % MOD_1;

            hashHay.second = (hashHay.second * base_2 - (haystack[i - 1] - 'a' + 1) * MAX_WEIGHT_2 % MOD_2 + MOD_2) % MOD_2;
            hashHay.second = (hashHay.second + (haystack[i + m - 1] - 'a' + 1)) % MOD_2;

        }

        if (hashNeedle.first == hashHay.first && hashNeedle.second == hashHay.second)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    // string s = "abxrcabddbhjwenwejroeic reo4ilktvoig njeabxrca";
    string haystack = "abxrcabddbhjwenwejroeic reo4ilktvoig njeabxrca", needle = "bdd";
    cout << strStr(haystack, needle) << endl;
    return 0;
}



*/