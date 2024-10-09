
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
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

/*--------------------------------------------------------------------------------------------------------------------------*/
int N = 1000000;
bool sieve[1000000 + 1];
vector<int> primes;

void createSieve()
{
    for (int i = 2; i <= N; i++)
    {
        sieve[i] = true;
    }

    for (int i = 2; i * i <= N; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                sieve[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if (sieve[i])
        {
            primes.push_back(i);
        }
    }
}

bool isPerfectSquare(long long n)
{
    long long sqrt_n = sqrt(n);
    return sqrt_n * sqrt_n == n;
}

void solve()
{
    ll n;
    cin >> n;
    for (int i = 0; i < primes.size(); i++)
    {
        ll a = primes[i];
        ll x = a * a;
        if (x > n)
            break;

        for (int j = i + 1; j < primes.size(); j++)
        {
            ll b = primes[j];
            ll y = x + b * b;
            if (y > n)
                break;

            ll z = n - y;
            if (isPerfectSquare(z))
            {
                ll sqrt_z = sqrt(z);
                if (sqrt_z != a && sqrt_z != b  && sieve[sqrt_z] && z == sqrt_z * sqrt_z)
                {
                    cout << "YES\n";
                    return;
                }
            }
        }
    }
    no;
}

int32_t main()
{
    fastio();
    createSieve();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
