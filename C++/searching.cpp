// LINEAR SEARCH
/*
#include<iostream>
using namespace std;
int LinearSearch(int arr[],int size,int x){
    for (int i = 0; i < size; i++)
    {
       if (arr[i]==x)
       {
        return i;
       }
      
    }
    return -1;
     
}
int main(){
    int arr[]={10,12,1,8,2,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    int x;
    cout<<"Enter the element to search\n";
    cin>>x;
    int ans=LinearSearch(arr,size,x);
    if (ans==-1)
    {
        cout<<"Not Found\n";
        cout<<"Index : "<<ans<<endl;

    }else{
        cout<<"Found\n";
        cout<<"Index : "<<ans<<endl;
    }
    
    
    return 0;
}
*/

//BINARY SEARCH
//Elemets should must be sorted
/*
#include<iostream>
using namespace std;
int binarySearch(int arr[],int size,int k){
    int start=0;
    int end=size-1;
    while (start<=end)
    {
        int mid = (end - start) / 2 + start;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (k>arr[mid])
        {
            start = mid + 1;
        }
        else // k<arr[mid]
        {
            end = mid - 1;
        }
      
    }
    return -1;//loop ki bahar aa gyi,means (start>end) , so we should return -1;
}
int main(){
    int arr[]={1,2,5,8,10,12};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<<"Enter the Element to Search\n";
    cin>>k;
    if (binarySearch(arr, size, k)==-1)
    {
        cout<<"Element is Not Present\n";
    }
    else{
        cout<<"Element is Present\n";
    }
    
    return 0;
}
*/

