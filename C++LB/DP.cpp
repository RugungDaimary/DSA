
#include <iostream>
#include <vector>
using namespace std;
int N = 1e9 + 7;
// Count Derangement
// using memoization
long long int countDerangements_Helper(int n, vector<long long int> &dp)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    long long int ans = ((countDerangements_Helper(n - 1, dp) % N + countDerangements_Helper(n - 2, dp) % N) * (n - 1)) % N;
    return dp[n] = ans;
}

long long int countDerangements(int n)
{
    vector<long long int> dp(n + 1, -1);
    return countDerangements_Helper(n, dp);
}
//Using Tabulation
long long int Derangement(int n){
    vector<int>dp(n+1,-1);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++){
        dp[i]=((dp[i-1] % N + dp[i - 2] % N) * (i - 1)) % N;

    }
    return dp[n];
}


// Partition Equal Subset Sum
bool Helper_Rec(vector<int> &nums, int target, int index)
{
    if (target == 0)
    {
        return true;
    }
    if (index == nums.size())
    {
        return false;
    }
    if (target < 0)
    {
        return false;
    }
    bool include = Helper_Rec(nums, target - nums[index], index + 1);
    bool exclude = Helper_Rec(nums, target, index + 1);
    return include || exclude;
}
bool canPartition_Rec(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum & 1)
    { // sum is odd
        return false;
    }
    int target = sum / 2;
    return Helper_Rec(nums, target, 0);
}
bool Helper_Mem(vector<int> &nums, int target, int index,vector<vector<int>>&dp)
{
    if (target == 0)
    {
        return true;
    }
    if (index == nums.size())
    {
        return false;
    }
    if (target < 0)
    {
        return false;
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    bool include = Helper_Mem(nums, target - nums[index], index + 1,dp);
    bool exclude = Helper_Mem(nums, target, index + 1,dp);
    return dp[index][target]=include || exclude;
}
bool canPartition_Mem(vector<int>&nums){
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum & 1)
    { // sum is odd
        return false;
    }
    int target = sum / 2;
    vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
    return Helper_Mem(nums, target, 0,dp);
}
bool canPartition_Tabul(vector<int>&nums){
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum & 1)
    { // sum is odd
        return false;
    }
    int target = sum / 2;
    vector<vector<int>> dp(nums.size()+1, vector<int>(target + 1, 0));
    for(int i=0;i<nums.size();i++){
        dp[i][0]=1;//means true from above base condition

    }
    for(int index=nums.size()-1;index>=0;index--){
        for(int t=1;t<=target;t++){
            bool include=0;
            if(t-nums[index]>=0){
                include=dp[index+1][t-nums[index]];
            }
            bool exclude=dp[index+1][t];
            dp[index][t]=include||exclude;
        }

    }
    return dp[0][target];  

}
bool canPatition_spaceOptm(vector<int>&nums){
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum & 1)
    { // sum is odd
        return false;
    }
    int target = sum / 2;
    vector<bool>curr(target+1,false);
    vector<bool>next(target+1,false);
    curr[0]=1;
    next[0]=1;
    for(int index=nums.size()-1;index>=0;index--){
        for(int t=1;t<=target;t++){
            bool include=0;
            if(t-nums[index]>=0){
                include=next[t-nums[index]];
            }
            bool exclude=next[t];
            curr[t]=include||exclude;
        }
        //shift
        next=curr;//as in row we are moving from down to top

    }
    return next[target];  
}

int main()
{
    // cout << countDerangements(5) << endl;
    // cout << Derangement(5) << endl;
    vector<int>nums={1,5,11,5};
    cout << canPartition_Tabul(nums) << endl;
    cout << canPatition_spaceOptm(nums) << endl;
    return 0;
}
