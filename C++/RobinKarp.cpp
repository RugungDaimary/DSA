#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define MOD1 1000000009
#define MOD2 100000007
#define base1 26
#define base2 27
#define ll long long
ll expo(ll a, ll b, ll mod)
{
    // ll res = 1;
    // while (b > 0)
    // {
    //     if (b & 1)
    //         res = (res * a) % mod;
    //     a = (a * a) % mod;
    //     b = b >> 1;
    // }
    // return res;
    if(b==0) return 1;
    ll ans=expo(a,b/2,mod);
    if(b&1) return (((ans*ans)%mod)*a)%mod;
    return (ans*ans)%mod;
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
        // the hash value of the entire string s will be stored at hashValues1[n - 1]
        //  where n is the length of the string.This is because the hash values are
        // being accumulated in a prefix sum manner, where each hashValues1[i] contains
        // the hash of the substring from the start of the string up to the i - th character.
        // Thus, hashValues1[n - 1] will contain the hash of the entire string
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

        // Compute the hash of the pattern
        Hashing patternHasher(pattern);
        pair<ll, ll> patternHash = patternHasher.substringHash(0, m - 1);

        // Check each substring of length m in the text
        for (int i = 0; i <= n - m; i++)
        {
            pair<ll, ll> currentHash = substringHash(i, i + m - 1);
            if (currentHash == patternHash)
                return i;
        }
        return -1;
    }
};

int main()
{
    fastio();
    string text = "abcde";
    string pattern = "e";
    Hashing textHasher(text);
    int index = textHasher.containsSubstring(pattern);
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
