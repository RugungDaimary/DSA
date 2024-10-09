
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
// #define MOD 1000000007
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

/*--------------------------------------------------------------------------------------------------------------------------*/


#define M 998244353
vector<ll>factorial;
ll fact(ll n){
    if(n==1|| n==0)return factorial[n]=1ll;
    return factorial[n]=(n%M*fact(n-1)%M)%M;
}
ll expo(ll a, ll b)
{
    if (b == 0)
        return 1ll;
    ll half = expo(a * 1ll, (b / 2)*1ll);
    if (b & 1)
        return (a%M * half % M * half % M) % M;
    else
        return (half % M * half % M) % M;
}

void solve()
{
    ll n;
    cin>>n;
    vi p(2*n);
    for(int i=0;i<2*n;i++)cin>>p[i];
    ll left=n;
    ll right=n;
    ll c=0;
    for(int i=0;i<2*n;i++){
        
        if(i%2==0 && p[i]==0)c++;
        if(p[i]!=0){
            if(p[i]<=n)left--;
            else right--;

        }
        
    }
    ll pow_2=expo(2ll,c*1ll);

    ll ans=(1ll*factorial[left]%M*factorial[right]%M*pow_2%M)%M;
    cout<<ans<<endl;
    
}
int32_t main()
{
    fastio();
    ll n = 2e5;
    factorial.resize(n+1,1);
    fact(n);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
};