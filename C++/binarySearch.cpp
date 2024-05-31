
#include <bits/stdc++.h>
using namespace std;
// will return smallest index such that (nums[idx]>=x)
// in case of many x occurrences return the first or smallest index
int lowerBound(int low, int high, vector<int> &nums, int x)
{
    int n = nums.size();
    int index = n; // if not found return size of nums
    int mid = (low + high) / 2;
    while (low <= high)
    {
        if (x > nums[mid])
        {
            low = mid + 1;
        }
        else
        {
            index = min(index, mid);
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }
    return index;
}

int searchSorted_I(vector<int> &nums, int target) // nums contains only unique values only
{
    // binary search logic here we need to identify that which part is sorted either left or right part by
    // cheking that if nums[l]<=nums[right],if this is true means,this part is sorted and other part is not sorted
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == target)
            return mid;
        // first identify the sorted part and check if target value lies in that part ,if does not lies then eliminate that part

        // it is gurateed that either one part is sorted
        if (nums[l] <= nums[mid])
        { // left part is sorted
            if (nums[l] <= target && target <= nums[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        { // (nums[mid]<=nums[r]) right part is sorted
            if (nums[mid] <= target && target <= nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    return -1;
}

bool searchRotated_II(vector<int> &nums, int target)
{
    //  0 1 2 3 4 5 6
    // [3,1,2,3,3,3,3] t=3 ,here (nums[l]=nums[mid]=nums[r]) try to trim down the array
    // nums contains duplicate values(here we can't return the index of target,this can only be done by linear search only)
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[l] == nums[mid] && nums[mid] == nums[r])
        {
            // trim down the search space
            l = l + 1;
            r = r - 1;
            continue;
        }
        if (nums[l] <= nums[mid])
        { // left part is sorted
            if (nums[l] <= target && target <= nums[mid])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        { // (nums[mid]<=nums[r]) right part is sorted
            if (nums[mid] <= target && target <= nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    return false;
}

int findPeak(vector<int> &nums)
{
    int n = nums.size();
    // checking that first and last element can be peak or not as they are the boundary elements and their one neightbour is for sure -infinity
    if (n == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    else if (nums[n - 1] > nums[n - 2])
        return n - 1;

    // now checking for range 1 to n-2
    int left = 1;
    int right = n - 2;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
            return mid;
        else if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1])
        { // increasing line so peak will be on right side
            left = mid + 1;
        }
        else
        { // decreasing line so peak will be on left side
            right = mid - 1;
        }
    }
    return -1;
}

int NthRoot(int n, int m)
{
    ll left = 1;
    ll right = m;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        ll temp = 1;
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            temp = (ll)(mid * temp);
            if (temp > m)
            {
                right = mid - 1;
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        if (temp <= m)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    ll t = 1;
    for (int i = 1; i <= n; i++)
    {
        t = (ll)(t * right);
    }
    if (t != m)
        return -1;
    return right;
}

//min(max) concept ->eg Book Allocation problem,Split Array Largest Sum





long long int squareInteger(int n)
{
    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        long long int square = mid * mid;
        if (square == n)
        {
            return mid;
        }
        if (square < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
double morePrecision(int n, int precision, int tempSol)
{
    double factor = 1;
    double ans = tempSol;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;

        for (double j = ans; j * j < n; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}
int main()
{

    // vector<int> nums = {1, 2, 3, 3,4, 5};
    // int x = 3;
    // int result = lowerBound(0, nums.size() - 1, nums, x);
    // cout << "Lower bound index: " << result << endl;

    // vector<int> nums = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    // cout << searchSorted_I(nums, 7) << endl;

    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << findPeak(nums) << endl;

    int tempSol = squareInteger(19);
    cout << "Root is " << morePrecision(n, 3, tempSol) << endl;

    return 0;
}
