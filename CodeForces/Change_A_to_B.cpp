
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
