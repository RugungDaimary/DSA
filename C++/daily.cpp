#include <bits/stdc++.h>
using namespace std;
/*

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
long long findMaximumScore(vector<int> &nums)
{

    int n = nums.size();
    vector<pair<int, int>> v(n);
    long long int ans = 0;
    stack<pair<int, int>> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top().first <= nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            v[i] = st.top();
        }
        else
        {
            v[i] = {-1, -1};
        }
        st.push({nums[i], i});
    }
    // long long int ans=0;
    for (int i = 0; i < n; i++)
    {
        int gt_ele = v[i].first;
        int ind = v[i].second;
        //    cout<<ans<<endl;
        if (ind == -1)
        {
            ans += (1ll * nums[i] * (n - 1 - i));
            //  cout<<ans<<endl;
            return ans;
        }
        else
        {
            ans += (1LL * nums[i] * (ind - i));
            i = ind - 1;
            // cout<<ans<<endl;
        }
        if (ind == n - 1)
            break;
    }
    return ans;
}
*/

int xorQueries(vector<int> &arr, int l, int r)
{
    int n = arr.size();
    vector<int> xorVal;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x ^= arr[i];
        xorVal.push_back(x);
    }

    int val = xorVal[r] ^ (l >= 1 ? xorVal[l - 1] : 0);

    return val;
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
    vector<int> arr = {1, 3, 4, 8};
    int l, r;
    cin >> l >> r;
    cout<<xorQueries(arr,l,r)<<endl;
    // cout<<(3^4)<<endl;

    return 0;
}