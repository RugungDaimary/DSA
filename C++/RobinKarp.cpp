#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ll long long
#define mod1 1000000007
#define mod2 1000000009
#define base1 26
#define base2 27
using namespace std;

ll exp(ll a, ll b, ll mod) // log n
{
    if (b == 0)
        return 1LL;
    ll half = exp(a, b / 2, mod);
    half = (half * half) % mod;
    if (b & 1)
        return (half * a) % mod;
    return half;
}

class Hashing
{
    string s;
    int n;
    vector<ll> hashVal1, hashVal2;
    vector<ll> pow1, pow2;
    vector<ll> invPow1, invPow2;

public:
    Hashing(string s) // O(n)
    {
        this->s = s;
        n = s.length();
        hashVal1.resize(n);
        hashVal2.resize(n);
        pow1.resize(n + 1);
        pow2.resize(n + 1);
        invPow1.resize(n + 1);
        invPow2.resize(n + 1);

        pow1[0] = pow2[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            pow1[i] = (pow1[i - 1] * base1) % mod1;
            pow2[i] = (pow2[i - 1] * base2) % mod2;
        }

        // Finding Exponential -> O(n) as exp() is called for 2 times only
        invPow1[n] = exp(pow1[n], mod1 - 2, mod1);
        invPow2[n] = exp(pow2[n], mod2 - 2, mod2);
        for (int i = n - 1; i >= 0; i--)
        {
            invPow1[i] = (invPow1[i + 1] * base1) % mod1;
            invPow2[i] = (invPow2[i + 1] * base2) % mod2;
        }

        // Compute hash values
        // the hash value of the entire string s will be stored at hashValues1[n - 1]
        //  where n is the length of the string.This is because the hash values are
        // being accumulated in a prefix sum manner, where each hashValues1[i] contains
        // the hash of the substring from the start of the string up to the i - th character.
        // Thus, hashValues1[n - 1] will contain the hash of the entire string
        for (int i = 0; i < n; i++)
        {
            hashVal1[i] = ((s[i] - '0' + 1) * pow1[i]) % mod1;
            if (i > 0)
            {
                hashVal1[i] = (hashVal1[i] + hashVal1[i - 1]) % mod1;
            }

            hashVal2[i] = ((s[i] - '0' + 1) * pow2[i]) % mod2;
            if (i > 0)
            {
                hashVal2[i] = (hashVal2[i] + hashVal2[i - 1]) % mod2;
            }
        }
    }

    pair<ll, ll> findHash(int l, int r) // O(1)
    {
        if (l == 0)
        {
            return {hashVal1[r], hashVal2[r]};
        }
        ll hash1 = (hashVal1[r] - hashVal1[l - 1] + mod1) % mod1;
        hash1 = (hash1 * invPow1[l]) % mod1;

        ll hash2 = (hashVal2[r] - hashVal2[l - 1] + mod2) % mod2;
        hash2 = (hash2 * invPow2[l]) % mod2;

        return {hash1, hash2};
    }

    int findSubstring(string &text) // O(n−m+1)
    {
        int m = text.size();
        if (m > n)
            return -1; // Not found

        Hashing textHasher(text);
        pair<ll, ll> textVal = textHasher.findHash(0, m - 1);
        for (int i = 0; i <= n - m; i++)
        {
            pair<ll, ll> curr = findHash(i, i + m - 1);
            if (curr == textVal)
                return i;
        }
        return -1;
    }
};

int main()
{
    // O(n+n−m+1) Entire Implementation is
    fastio();
    string s = "abracadabra";
    string pattern = "cad";
    Hashing h(s);
    int index = h.findSubstring(pattern);
    cout << "Pattern found at index: " << index << endl;
    

    return 0;
}

/*
// Normal Robin Karp Code(useful for single pattern matching)
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

int stringMatching(string text, string pattern)
{
    ll n = text.length(), m = pattern.length();
    if (n < m)
        return -1;

    ll MAX_WEIGHT_1 = 1, MAX_WEIGHT_2 = 1;
    for (ll i = 0; i < m; i++)
    {
        MAX_WEIGHT_1 = (MAX_WEIGHT_1 * base_1) % MOD_1;
        MAX_WEIGHT_2 = (MAX_WEIGHT_2 * base_2) % MOD_2;
    }

    pair<ll, ll> hashPattern = hashPair(pattern, m);
    pair<ll, ll> hashText = {0, 0};

    for (ll i = 0; i < n - m + 1; i++)
    {
        if (i == 0)
        {
            hashText = hashPair(text, m);
        }
        else
        {
            hashText.first = (hashText.first * base_1 - (text[i - 1] - 'a' + 1) * MAX_WEIGHT_1 % MOD_1 + MOD_1) % MOD_1;
            hashText.first = (hashText.first + (text[i + m - 1] - 'a' + 1)) % MOD_1;
            hashText.second = (hashText.second * base_2 - (text[i - 1] - 'a' + 1) * MAX_WEIGHT_2 % MOD_2 + MOD_2) % MOD_2;
            hashText.second = (hashText.second + (text[i + m - 1] - 'a' + 1)) % MOD_2;

        }

        if (hashPattern.first == hashText.first && hashPattern.second == hashText.second)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    string text = "abxrcabddbhjwenwejroeic reo4ilktvoig njeabxrca";
    string pattern= "bdd";
    cout << stringMatching(text, pattern) << endl;
    return 0;

}


*/
