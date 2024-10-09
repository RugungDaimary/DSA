#include<bits/stdc++.h>
using namespace std;
int partion(int low, int high,vector<int> &nums) {
   
    int pivot=nums[low];
    int i = low + 1;
    int j = high;
    while(i<=j){
        while(i<=j && nums[i]<=pivot){
            i++;
        }
        while (i <= j && nums[j] >= pivot)
        {
            j--;
        }
        if(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }

    }
    swap(nums[low],nums[j]);
    return j;
}
void quickSort(int low,int high,vector<int> &nums)
{

    if(low<=high){
        int pIndex=partion(low,high,nums);
        quickSort(low,pIndex-1,nums);
        quickSort(pIndex+1,high,nums);
    }
}
int main(){
    vector<int>nums={4,2,1,8,9,3};
    for(auto it:nums){
        cout<<it<<" ";
    }
    cout<<endl;
    int low=0;
    int high=nums.size()-1;

    quickSort(low,high,nums);
    for(auto it:nums){
        cout<<it<<" ";
    }
    return 0;
}