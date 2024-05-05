
// // #include <iostream>
// // using namespace std;
// // int binarySearch(int arr[], int size, int k)
// // {
//     // int start = 0;
//     // int end = size - 1;
//     // while (start <= end)
//     // {
//     //     int mid = (end - start) / 2 + start;
//     //     if (arr[mid] == k)
//     //     {
//     //         return mid;
//     //     }
//     //     else if (k > arr[mid])
//     //     {
//     //         start = mid + 1;
//     //     }
//     //     else //(arr[mid] > k)
//     //     {
//     //         end = mid - 1;
//     //     }
        
//     // }
//     // return -1; // loop ki bahar aa gyi,means start>end , so we return -1;
// // }
// // int main()
// // {
// //     int arr[] = {1, 2, 5, 8, 10, 12};
// //     int size = sizeof(arr) / sizeof(arr[0]);
// //     int k;
// //     cout << "Enter the Element to Search\n";
// //     cin >> k;
// //     int ans=binarySearch(arr,size,k);
// //     if (ans == -1)
// //     {
// //         cout << "Element is Not Present\n";
// //     }
// //     else
// //     {
// //         cout << "Element is Present at index " <<ans<<endl;
// //     }
// //     return 0;
// // }

// #include<iostream>
// using namespace std;
// int binarySearch(int * arr,int n,int x ){
//     int s=0;
//     int e=n-1;
//     int mid=s+(e-s)/2;
//     while (s<=e)   
//     {
//         if (arr[mid]==x)
//         {
//             return mid;
//         }
//         else if(arr[mid]<x){
//             s=mid+1;
//         }
//         else{
//             e=mid-1;
//         }
//         mid=s+(e-s)/2;
        
//     }
//     return -1;
    

// }
// int main(){
//     int arr[]={1,3,6,7,9};
//     int n=sizeof(arr)/sizeof(int);
//     int x;
//     cout<<"Enter the number to search\n";
//     cin>>x;
//     int ans = binarySearch(arr, n, x);
//     if (ans == -1)
//     {
//         cout<<"Not found\n";
//     }else{
//         cout << "Found at " << ans<<endl;
//     }
    

    
//     return 0;
// }

// #include <iostream>
// using namespace std;
// void merge(int *arr, int s, int e)
// {
//     int mid = s + (e - s) / 2;
//     int len1 = mid - s + 1;
//     int len2 = e - mid;
//     int *first = new int[len1];
//     int *second = new int[len2];
//     int mainIndex = s;
//     for (int i = 0; i < len1; i++)
//     {
//         first[i] = arr[mainIndex++];
//     }
//     mainIndex = mid + 1;
//     for (int i = 0; i < len2; i++)
//     {
//         second[i] = arr[mainIndex++];
//     }
//     int ind1 = 0;
//     int ind2 = 0;
//     mainIndex = s;
//     while (ind1 < len1 && ind2 < len2)
//     {
//         if (first[ind1] < second[ind2])
//         {
//             arr[mainIndex++] = first[ind1++];
//         }
//         else
//         {
//             arr[mainIndex++] = second[ind2++];
//         }
//     }
//     while (ind1 < len1)
//     {
//         arr[mainIndex++] = first[ind1++];
//     }
//     while (ind2 < len2)
//     {
//         arr[mainIndex++] = second[ind2++];
//     }
//     delete[] first;
//     delete[] second;
// }
// void mergeSort(int *arr, int s, int e)
// {
//     if (s >= e)
//     {
//         return;
//     }
//     int mid = s + (e - s) / 2;
//     mergeSort(arr, s, mid);
//     mergeSort(arr, mid + 1, e);
//     merge(arr, s, e);
// }
// int main()
// {
//     // your code goes here
//     int T;
//     cin >> T;
//     for (int i = 0; i < T; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         int arr[] = {0};
//         for (int i = 0; i < x; i++)
//         {
//             cin >> arr[i];
//         }
//         int s = 0;
//         int e = x - 1;
//         mergeSort(arr, s, e);
//         cout << arr[x - y] - 1 << endl;
//     }
//     return 0;
// }



//Finding Square root using Binary Search
#include<iostream>
using namespace std;
long long int squareInteger(int n){
    int s=0;
    int e=n;
    long long int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        long long int square=mid*mid;
        if(square==n){
            return mid;
        }
        if(square<n){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
double morePrecision(int n,int precision,int tempSol){
    double factor=1;
    double ans=tempSol;
    for(int i=0;i<precision;i++){
        factor=factor/10;

        for(double j=ans;j*j<n;j+=factor){
            ans=j;
        }
    }
    return ans;

}
int main(){
    int n;
    cout<<"Enter number\n";
    cin>>n;
    
    // cout<<"root of "<<n<<" is "<<squareInteger(n)<<endl;
    int tempSol = squareInteger(n);
    cout << "Root is " << morePrecision(n,3,tempSol)<<endl;

        return 0;
}