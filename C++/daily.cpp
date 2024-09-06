#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = abs(abs(nums[i]) - abs(nums[j]));
            int add = abs(nums[i]) + abs(nums[j]);
            if (diff <= min(abs(nums[i]), abs(nums[j])) && add >= max(abs(nums[i]), abs(nums[j])))
                cnt++;
        }
    }
    return cnt;
}
int main()
{
    vector<int> nums = {2, 5, -3};
    cout << solve(nums) << endl;

    return 0;
}