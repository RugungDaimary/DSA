#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class DSU
{
public:
    vector<int> parent, size;

    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (size[rootX] < size[rootY])
            {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }

    int getSize(int x)
    {
        return size[find(x)];
    }
};

vector<int> sieve(int n)
{
    vector<int> spf(n + 1);
    for (int i = 2; i <= n; ++i)
    {
        if (spf[i] == 0)
        {
            for (int j = i; j <= n; j += i)
            {
                if (spf[j] == 0)
                {
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}

vector<int> findFriendCircles(const vector<int> &ratings)
{
    int n = ratings.size();
    int maxRating = *max_element(ratings.begin(), ratings.end());

    DSU dsu(n);
    vector<int> spf = sieve(maxRating);
    unordered_map<int, int> primeToIndex;

    for (int i = 0; i < n; ++i)
    {
        int num = ratings[i];
        unordered_map<int, bool> seen;

        while (num > 1)
        {
            int prime = spf[num];
            if (!seen[prime])
            {
                if (primeToIndex.count(prime))
                {
                    dsu.unite(i, primeToIndex[prime]);
                }
                else
                {
                    primeToIndex[prime] = i;
                }
                seen[prime] = true;
            }
            num /= prime;
        }
    }

    vector<int> result(n);
    for (int i = 0; i < n; ++i)
    {
        result[i] = dsu.getSize(i);
    }

    return result;
}

int main()
{
    // vector<int> ratings = {1, 2, 4};
    // vector<int> result = findFriendCircles(ratings);

    // for (int communitySize : result)
    // {
    //     cout << communitySize << " ";
    // }
    // cout << endl;
    

    return 0;
}