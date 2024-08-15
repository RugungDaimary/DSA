#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<vector<int>> &adj)
{
    vector<int> indegree(n, 0);
    for (int u = 0; u < n; u++)
    {
        for (auto v : adj[u])
        {
            indegree[v]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int cnt = 1;
    vector<int> topoSorted;
    while (!q.empty())
    {
        int sz = q.size();
        cnt *= sz;
        while (sz--)
        {
            int fNode = q.front();
            topoSorted.push_back(fNode);

            q.pop();
            for (auto nbr : adj[fNode])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
    if (topoSorted.size() != n)
        return 0;
    return cnt;
}
int main()
{
    int n = 10;
    vector<vector<int>> edges{{0, 4}, {4, 7}, {7, 9}, {1, 4}, {4, 7}, {2, 5}, {5, 7}, {3, 6}, {6, 8}, {8, 9}};
    vector<vector<int>> adj(n);
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[v].push_back(u);
    }
    cout << solve(n, adj) << endl;

    return 0;
}