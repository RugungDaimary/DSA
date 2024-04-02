
// Policy Based Data Structure
#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> adj;
int ans = 0;
bool dfs(int node, int parent, vector<bool> &hasApple)
{

    bool aage = false;
    for (auto nbr : adj[node])
    {

        if (parent != nbr)
        {
            // cout<<nbr<<" "<<node<<endl;
            aage = dfs(nbr, node, hasApple)||aage;
        }
    }
    if (hasApple[node] || aage)
    {
        ans += 2;
        return true;
    }
    return false;
}
int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
{
    for (vector<int> &s : edges)
    {
        int u = s[0];
        int v = s[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for (auto i : adj)
    // {
    //     cout << i.first << " : ";
    //     for (auto j : adj[i.first])
    //     {
    //         cout << j << ",";
    //     }
    //     cout << endl;
    // }
    dfs(0, -1, hasApple);
    return ans;
}
int main(){
    vector<vector<int>> edges { {0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
    vector<bool>hasApple = {false,false,true,false,true,true,false};
    int n=7;
    cout<<minTime(n,edges,hasApple)-2<<endl;
}