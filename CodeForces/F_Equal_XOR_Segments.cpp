
//******************************************************************
//	             Rugung Daimary
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
/*--------------------------------------------------------------------------------------------------------------------------*/
int hcf(int a, int b) { return (b == 0 ? a : hcf(b, a % b)); }
int lcm(int x, int y) { return (x * y) / hcf(x, y); }
int gcd(int a, int b){while (b != 0){int temp = b;b = a % b;a = temp;}return a;}
ll pow(ll x, ll y, ll p = 1e9 + 7) // time complexity O(log(min(x,y)))
{
    ll res = 1;
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
    int n,q;
    cin>>n>>q;
    vll a(n+1);
    map<ll,vll>mp;
    mp[0].push_back(0);//means to make 0 we have to take xor upto 0th index
    vll pf(n+1,0);//prefix xor
    pf[0]=0;
    for(int i=1;i<n+1;i++){
        cin>>a[i];
        pf[i]=pf[i-1]^a[i];
        mp[pf[i]].push_back(i); // means to make pf[i] value we have to take xor upto i th index
    }
    for(int i=0;i<q;i++){
        ll l,r;
        cin>>l>>r;
        ll x=pf[r]-pf[l-1];
        if(x==0){
            yes;
            continue;

        }
        //          x             y
        auto &v1=mp[pf[l-1]], &v2=mp[pf[r]];
        auto it1=lower_bound(v2.begin(),v2.end(),l+1);
        auto it2=--lower_bound(v1.begin(),v1.end(),r-1);
        if(*it1<*it2){
            yes;
           
        }else{
            no;
        }

    }
    cout<<endl;
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
}

;