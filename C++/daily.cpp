#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first > b.first && a.first >= a.second;
}

int main()
{
    vector<pair<int, int>> v = {{1, 2}, {5, 3}, {5, 4}, {4, 4}, {1, 5}};
    sort(v.begin(), v.end(), cmp);
    for (auto [x, y] : v)
    {
        cout << x << " " << y << endl;
    }

    return 0;
}