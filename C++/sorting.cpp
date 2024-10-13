#include <bits/stdc++.h>
using namespace std;

// SELECTION SORT(in each iteration ith minimum element is placed at it's right place)
void selectionSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n-1; i++)
    {
        int mini = nums[i];
        int idx = i;
        for (int j = i; j < n; j++)
        {
            if (nums[j] < mini)
            {
                mini = nums[j];
                idx = j;
            }
        }
        swap(nums[i], nums[idx]);
    }
    for (auto it : nums)
    {
        cout << it << " ";
    }
}

//BUBBLE SORT(in each iteration ith largest element is placed in it's right place(opposite to selection sort))
void bubbleSort(vector<int>&nums) {
    
    int n=nums.size();
    int idx=n-1;
    while(idx>0){
        for(int j=0;j<idx;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
            }
        }
        idx--;
    }
    for(auto it:nums){
        cout<<it<<" ";
    }
}

//  INSERTION SORT(here for index i [0,i-1] array has sorted and i want to insert the current element in it's right position )
void insertionSort(vector<int>&nums)
{
    int n=nums.size();
    for(int i=0;i<n;i++){
        int idx=i;
        while(idx>0 && nums[idx-1]>nums[idx]){
            swap(nums[idx-1],nums[idx]);
            idx--;
        }
    }
    for (auto it : nums)
    {
        cout << it << " ";
    }
}
// count sort

// TC=>O(n+k)
// SC=>O(k)
// Non comparison algorithm
// this algorithm is not inPlace algorithm(uses extra space of k size,where k is the maximum element)
// all elements should be +ve only

void countSort(vector<int> &arr)
{
    int n = arr.size();
    // intially we make count array which will store the frequency of all elements
    int maxi = *max_element(arr.begin(), arr.end());
    vector<int> count(maxi + 1, 0); // means all numbers will be in range up to max element only
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    arr.resize(0);
    // we will change in original array only
    for (int i = 0; i < count.size(); i++)
    {
        if (count[i] > 0)
        {
            for (int j = 0; j < count[i]; j++)
            {
                arr.push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    vector<int>nums={5,3,2,1,0,9};
    cout<<"Before: ";
    for (auto it : nums)
    {
        cout << it << " ";
    }
    cout<<endl;
    // bubbleSort(nums);
    cout<<"After : ";
    // selectionSort(nums);
    // countSort(nums);
    insertionSort(nums);

    return 0;
}
