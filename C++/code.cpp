#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>&nums){
    int n=nums.size();
    int idx=n-1;
    while(idx>0){
        for (int i = 0; i < idx; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                swap(nums[i], nums[i + 1]);
            }
        }
        idx--;
    }
    
}
void selectionSort(vector<int>&nums){
    int n=nums.size();
    for(int i=0;i<n;i++){
        int mini=nums[i];
        int idx=i;
        for(int j=i+1;j<n;j++){
            if(nums[j]<mini){
                mini=nums[j];
                idx=j;
            }
        }
        swap(nums[i],nums[idx]);
    }
}
void insertionSort(vector<int>&nums){
    int n=nums.size();
    for(int i=0;i<n;i++){
        int idx=i;
        while(idx>0 && nums[idx-1]>nums[idx]){
            swap(nums[idx],nums[idx-1]);
            idx--;
        }
    }
}
long long merge(int low,int mid,int high,vector<int>&nums){

    int i=low;
    int j=mid+1;
    vector<int>sorted;
    long long cnt=0;
    while(i<=mid && j<=high){
        if(nums[i]<=nums[j]){
            sorted.push_back(nums[i]);
            i++;
        }else{
            cnt+=(mid-i+1);
            sorted.push_back(nums[j]);
            j++;
        }

    }
    while(i<=mid){
        sorted.push_back(nums[i]);
        i++;
    }
    while(j<=high){
        sorted.push_back(nums[j]);
        j++;
    }
    int idx=0;
    for(int k=low;k<=high;k++){
        nums[k]=sorted[idx];
        idx++;

    }
    return cnt;

}
long long mergeSort(int low,int high,vector<int>&nums){
    if(low==high)return 0;
    int mid=(low+high)/2;
    long long left=mergeSort(low,mid,nums);
    long long right= mergeSort(mid+1,high,nums);
    return left+right+merge(low,mid,high,nums);
}
int partition(int low,int high,vector<int>&nums){
    int i = low;
    int j = high;
    int pivot = nums[low];
    while (i <= j)
    {
        while (i <=j && nums[i] <= pivot)
        {
            i++;
        }
        while (i<=j && nums[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {

            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    swap(nums[low], nums[j]);
    return j;
}

void quickSort( int low, int high,vector<int>&nums)
{
    if (low < high)
    {
        int pIdx = partition(low,high,nums);
        quickSort(low, pIdx - 1, nums);
        quickSort(pIdx + 1, high, nums);
    }
}
int main(){
    // vector<int>nums={2,4,1,3,5};
    // // cout<<mergeSort(0,nums.size()-1,nums)<<endl;
    // quickSort(0,nums.size()-1,nums);
    // for(auto it:nums){
    //     cout<<it<<" ";
    // }
    

    return 0;
}



