#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define sz(x) ((int)(x).size())

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
        primes = sz(hashPrimes);
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = s.length();
        for (int i = 0; i < sz(hashPrimes); i++)
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
        for (int i = 0; i < sz(hashPrimes); i++)
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

cout<<"HII\n";
    return 0;
}
