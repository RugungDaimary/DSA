#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
vector<int> Rank;

int find(int x)
{
    if (x == parent[x])
        return x;

    return parent[x] = find(parent[x]);
}

void Union(int x, int y)
{
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent)
        return;

    if (Rank[x_parent] > Rank[y_parent])
    {
        parent[y_parent] = x_parent;
    }
    else if (Rank[x_parent] < Rank[y_parent])
    {
        parent[x_parent] = y_parent;
    }
    else
    {
        parent[x_parent] = y_parent;
        Rank[y_parent]++;
    }
}
int main()
{

    // Initialize parent and rank vectors based on the size of the disjoint set
    int n; // Size of the disjoint set
    cin >> n;
    parent.resize(n);
    Rank.resize(n, 0);

    // Initialize parent vector
    for (int i = 0; i < n; ++i)
        parent[i] = i;
    cout<<"Hii\n";

    return 0;
}


