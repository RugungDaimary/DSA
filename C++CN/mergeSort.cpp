// Merge Sort
#include<bits/stdc++.h>
using namespace std;
void mergeTwoSorted(vector<int>&nums, int s, int mid, int e)
{
    vector<int> a(e - s + 1);
    int index1 = s;
    int index2 = mid + 1;
    int mainIndex = 0;

    while (index1 <= mid && index2 <= e)
    {
        if (nums[index1] <= nums[index2])
        {
            a[mainIndex] = nums[index1];
            index1++;
        }
        else
        {
            a[mainIndex] = nums[index2];
            index2++;
        }
        mainIndex++;
    }

    while (index1 <= mid) // if 1st array if bigger than 2nd
    {
        a[mainIndex] = nums[index1];
        index1++;
        mainIndex++;
    }

    while (index2 <= e)
    {
        a[mainIndex] = nums[index2];
        index2++;
        mainIndex++;
    }

    mainIndex = 0;
    for (int i = s; i <= e; i++) // for copying the elements back to main array
    {
        nums[i] = a[mainIndex];
        mainIndex++;
    }
}
void mergeSort(vector<int>&nums,int s,int e){
    int mid=s+(e-s)/2;
    if(s>=e)return;
    //left part sort
    mergeSort(nums, 0, mid);
    // right part sort
    mergeSort(nums, mid + 1, e);

    //merge both sorted array
    mergeTwoSorted(nums,s,mid,e);
}

void merge(int *arr, int s, int e)
{

    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];
    // copying values
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }
    // merge two sorted arrays;
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;
    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }
    delete []first;
    delete []second;
   
}
void mergesort(int arr[], int s, int e)
{
    // base case
    int mid = s + (e - s) / 2;
    if (s >= e)
    {
        return ;
    }
    // left part sort
    mergesort(arr, 0, mid);
    // right part sort
    mergesort(arr, mid + 1, e);
    merge(arr, s, e);
    
}

int main()
{
    int arr[] = {3, 6, 10, 8, 1, 6};
    int n =6;
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    vector<int> nums = {1, 7, 2, 9, 0};

    return 0;
}