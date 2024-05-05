#include<iostream>
using namespace std;
int bubbleSort(int arr,int n){
    int minIndex = 0;
    for (int j = 1; j <n; j++)
    {
        
        for (int i = 1; i < n; i++)
        {
        if (arr[i-1]>arr[i])
        {
            swap(arr[i-1],arr[i]);
           
        }
        }
    }
    return minIndex;
}  
int main(){
    int arr[]={5,4,1,2};
    int n=sizeof(arr)/sizeof(int);
    bubbleSort(arr[],n);
    
    
    return 0;
}