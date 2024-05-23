#include<bits/stdc++.h>
using namespace std;
//will return smallest index such that (nums[idx]>=x)
//in case of many x occurrences return the first or smallest index
int lowerBound(int low,int high,vector<int>&nums,int x){
    int n=nums.size();
    int index=n;//if not found return size of nums
    int mid = (low + high) / 2;
    while(low<=high){
        if(x>nums[mid]){
            low=mid+1;
        }else{
            index=min(index,mid);
            high=mid-1;
        }
        mid=(low+high)/2;
    }
    return index;

}
int main(){
    
    vector<int> nums = {1, 2, 3, 3,4, 5};
    int x = 3;
    int result = lowerBound(0, nums.size() - 1, nums, x);
    cout << "Lower bound index: " << result << endl;
    
    return 0;
}