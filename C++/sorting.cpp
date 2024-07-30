
// SELECTION SORT
#include <bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) // i represents the current round//for rounds
    {
        // find minimum element in the array
        int min = arr[i]; // assuming the first element as minimum
        int minIndex = i; // initialized with first index,index of min element
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
//BUBBLE SORT
void bubbleSort(int *arr,int n){
    for (int j = 0; j <n-1; j++)
    {
        for (int i = 0; i < n - 1-i; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
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
    for (int i = 0; i < count.size(); i++)
    {
        cout << count[i] << " ";
    }
    cout << endl;
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
    int arr[]={10,12,1,8,2,5};
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
     cout << endl;
    bubbleSort(arr,6);
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    return 0;
}
