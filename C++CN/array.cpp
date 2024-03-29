//Swap two adjacent elements
// #include<iostream>
// using namespace std;
// void swapTwo(int *arr,int n){
//     for (int i = 0; i < n; i+=2)
//     {
//         swap(arr[i],arr[i+1]);
//     }
    
// }
// int main(){
//     int arr[]={4,5,7,8};
//     int n=4;
//     swapTwo(arr, n);
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }
//Find duplicates in array
//pending
#include<iostream>
#include<vector>
using namespace std;
int findDuplicate(int* arr,int n){
  int a[]={0};
  for (int i = 0; i < n; i++)
  {
    int x=arr[i];
    a[x-1]++;
  }
  return 1;
    
}

int main(){
  int n;
  cin>>n;
    int arr[]={1,1,3,4,5,6};
    cout <<findDuplicate(arr,6)<<endl;

    return 0;
}