#include <bits/stdc++.h>
using namespace std;
// Finding the XOR value in subarray
vector<int> seg;
void build(int idx, int low, int high, vector<int> &nums)
{
    if (low == high)
    {
        seg[idx] = nums[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * idx + 1, low, mid, nums);
    build(2 * idx + 2, mid + 1, high, nums);
    seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
}
void updateSegmentTree(int idx, int low, int high, int pos, int val)
{
    if (low == high)
    {
        seg[idx] = val;
        return;
    }
    int mid = (low + high) / 2;
    if (pos <= mid)
    {
        updateSegmentTree(2 * idx + 1, low, mid, pos, val);
    }
    else
    {
        updateSegmentTree(2 * idx + 2, mid + 1, high, pos, val);
    }
    seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
}
int query(int idx, int low, int high, int l, int r)
{
    if (low >= l && high <= r) // completely lies condition means [low,high] completely lies inside [l,r]
    {
        return seg[idx];
    }
    if (high < l || low > r) // outside condition
        return INT_MIN;
    int mid = (low + high) / 2;
    // overlaps condition
    int left = query(2 * idx + 1, low, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, high, l, r);
    return left ^ right;
}

int main()
{

    vector<int> nums = {8, 2, 5, 1, 4, 5, 3, 9, 6, 10};
    int n = nums.size();
    seg.resize(4 * n); // it's found that the maximum no of nodes in Tree can be 4*n
    build(0, 0, n - 1, nums);
    int q;
    cin >> q;
    vector<int> XOR;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        XOR.push_back(query(0, 0, n - 1, l, r));
    }
   
    return 0;
}
