#include <bits/stdc++.h>
using namespace std;
void updateFreq(int op, int val, vector<int> &freqBits)
{
    int i = 0;
    while (val > 0)
    {
        if ((val & 1))
        {
            freqBits[i] += op; //+1 in case of adding and -1 in case of removing
        }

        val = val >> 1;
        i++;
    }
}
int minimumDifference(vector<int> &nums, int k)
{
    vector<int> freqBits(32, 0);

    int n = nums.size();

    int i = 0;
    int j = 0;
    int windowAnd = nums[0];
    int result = INT_MAX;

    while (j < n)
    {
        windowAnd = windowAnd & nums[j];
        updateFreq(1, nums[j], freqBits);

        result = min(result, abs(k - windowAnd));

        if (windowAnd > k)
        {
            j++;
        }
        else if (windowAnd == k)
        { // can't get a better answer than 0 (we are dealing with absolute difference)
            return 0;
        }
        else // shrink the window
        {
            while (i <= j && windowAnd < k)
            {
                updateFreq(-1, nums[i], freqBits);
                i++;
                windowAnd = 0;
                for (int b = 0; b < 32; b++)
                {
                    if ((j - i + 1) == freqBits[b])
                    { // jth bit of all numbers in the window (j-i+1) are set to 1
                        windowAnd = windowAnd | (1 << b);
                    }
                }
                result = min(result, abs(k - windowAnd));
            }
            j++;
        }
    }

    return result;
}

class Solution
{
public:
    // create segment tree
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
        seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
    }
    // AND operation in range follows non increasing graph
    int query(int idx, int low, int high, int l, int r)
    {
        if (low >= l && high <= r) // completely lies condition means [low,high] completely lies inside [l,r]
        {
            return seg[idx];
        }
        if (high < l || low > r) // outside condition
            return INT_MAX;
        int mid = (low + high) / 2;
        // overlaps condition
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return left | right;
    }

    int minimumDifference(vector<int> &nums, int k)
    {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = nums.size();
        /*
        seg.resize(4*n);
        build(0,0,n-1,nums);
        int minDiff=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<=k){
                minDiff=min(minDiff,k-nums[i]);
            }else{//now we can binary search
                int low=i,high=n-1;//try to achieve maxAnd in range
                while(low<=high){
                    int mid=(low+high)/2;
                    int rangeAnd=query(0,0,n-1,i,mid);
                    minDiff=min(minDiff,abs(rangeAnd-k));
                    if(rangeAnd<=k){
                        high=mid-1;
                    }else{
                        low=mid+1;
                    }

                }
            }
            if(minDiff==0)return 0;
        }
        return minDiff;
        */

        // Now using Sliding Windiow as AND in range is monotonically decreasing curve
    }
};

int main()
{

    return 0;
}