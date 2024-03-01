#include<bits/stdc++.h>
using namespace std;
int maxLengthSubArray(vector<int> v, int k)
{
    int sum = 0;
    int maxLen = 0;
    unordered_map<int, int> preSum;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        int rem = sum - k;
        if (preSum.find(rem) != preSum.end())
        {
            int len = i - preSum[rem];
            maxLen = max(maxLen, len);
        }
        if (preSum.find(sum) == preSum.end())//if 0's occur in array like [2,0,0,3] k=3
            preSum[sum] = i;
    }
    return maxLen;
}

int countSubArrays(vector<int>&v,int k){
    unordered_map<int,int>prevSum;
    int sum=0;
    int count=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        if(sum==k){
            count++;
        }
        int diff=sum-k;
        if(prevSum.find(diff)!=prevSum.end()){
            count+=prevSum[diff];
        }
        prevSum[sum]++;
    }
    return count;
}
// int countSubArrays(vector<int>&v,int k){
//     int count = 0;
//     int sum = 0;
//     unordered_map<int, int> preSum;
//     preSum[0] = 1;//for if sum==k
//     for (int i = 0; i < v.size(); i++)
//     {
//         sum += v[i];
//         int diff = sum - k;
//         count += preSum[diff];
//         preSum[sum]++;
//     }
//     return count;
// }
int main(){
    vector<int>v{3,4,7,2,-3,1,4,2};
    int k=7;
    cout<<"Number od Sub Arrays : "<<countSubArrays(v,k)<<endl;

    cout<<ceil(5*1.0/2)<<endl;
    
    return 0;
}