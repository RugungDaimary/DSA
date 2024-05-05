//finding the subarray with maximum sum
#include<bits/stdc++.h>
using namespace std;
// Kadane Algo in 2D matrix,finding submatrix having maximum sum

int maxSumRectangle(vector<vector<int>> &arr, int n, int m)
{
    vector<vector<int>> mat = arr;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            arr[i][j] += arr[i][j - 1];
        }
    }
    // for printing
    int sRow = -1;
    int eRow = -1;
    int sCol = -1;
    int eCol = -1;

    int ans = INT_MIN;
    for (int s_c = 0; s_c < m; s_c++)
    {
        for (int e_c = s_c; e_c < m; e_c++)
        {
            int sum = 0;
            int r = -1;
            for (int row = 0; row < n; row++)
            {
                if (sum == 0)
                {
                    r = row;
                }
                sum += arr[row][e_c] - (s_c > 0 ? arr[row][s_c - 1] : 0);
                if (sum > ans)
                {
                    ans = sum;
                    sRow = r;
                    eRow = row;
                    sCol = s_c;
                    eCol = e_c;
                }
                if (sum < 0)
                {
                    sum = 0;
                }
            }
        }
    }

    cout << "Printing Submatrix : \n";
    for (int i = sRow; i <= eRow; i++)
    {
        for (int j = sCol; j <= eCol; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return ans;
}

void printMaxSubArraySum(vector<int>&nums){
    auto i = 0;
    auto sum = 0;
    auto maxi = INT_MIN;
    auto start=-1;
    auto sIndex=-1;
    auto eIndex=-1;
    while (i < nums.size())
    {
        if(sum==0) start=i;
        sum += nums[i];
        if(sum>maxi){
            maxi=sum;
            sIndex=start;
            eIndex=i;
        }
       
        if (sum < 0)
        {
            sum = 0;
        }
        i++;
    }
    for(int j=sIndex;j<=eIndex;j++){
        cout<<nums[j]<<" ";
    }
    
}
int maxSubArray(vector<int> &nums)
{
    auto i = 0;
    auto sum = 0;
    auto maxi = INT_MIN;
    while (i < nums.size())
    {
        sum += nums[i];
        maxi = max(maxi, sum);
        if (sum < 0)
        {
            sum = 0;
        }
        i++;
    }
    return maxi;
}
int main(){
    // vector<int>nums{-2,1,-3,4,-1,2,1,-5,4};
    // cout<<maxSubArray(nums)<<endl;
    // printMaxSubArraySum(nums);
    vector<vector<int>>arr = {{1, 2, -1, -4, -20},
        { -8, -3, 4, 2, 1},
        {3, 8, 10, 1, 3},
        { -4, -1, 1, 7, -6}
    };
    maxSumRectangle(arr,4,5);
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    
}
