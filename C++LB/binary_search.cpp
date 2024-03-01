//****LINEAR SEARCH***
//#include<iostream>
//using namespace std;
//int print(int arr[],int n){
//    for (int i=0; i<n; i++) {
//        if (arr[i]==2) {
//            cout<<i<<"\n";
//            return i;
//        }
//
//    }
//    cout<<"0\n";
//    return 0;
//
//}
//int main(){
//    //int x=5;
//    int arr[]={0,1,4,2};
//    int result=print(arr,4);
//    cout<<result<<"\n";
//    if (result==0) {
//        cout<<"x is not present\n";
//    }else{
//        cout<<"x is present at index "<<result<<endl;
//    }
//
//    return 0;
//}

// C++ code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1

//#include <iostream>
//using namespace std;
//
//int search(int arr[], int n, int x)
//{
//    int i;
//    for (i = 0; i < n; i++)
//        if (arr[i] == x)
//            return i;
//    return -1;
//}
//
//// Driver code
//int main(void)
//{
//    int arr[] = { 2, 3, 4, 10, 40 };
//    int x = 10;
//    int n = sizeof(arr) / sizeof(arr[0]);
//    cout<<n;
//
//    // Function call
//    int result = search(arr, n, x);
//    (result == -1)
//        ? cout << "Element is not present in array"
//        : cout << "Element is present at index " << result;
//    return 0;
//}
//



//****BINARY SEARCH****
//#include<iostream>
//using namespace std;
//int binarySearch(int arr[],int size,int key){
//    int start=0;
//    int end=size-1;
//    int mid=start+(end-start)/2;
//    while (start<=end) {//minimum there should be array of one element
//        if (arr[mid]==key) {
//            return mid;
//        }
//        if (key>arr[mid] ) {//go to right part
//            start=mid+1;
//        }else{  //key <arr[mid] //go to left part
//            end=mid-1;
//        }
//        mid=start+(end-start)/2;
//
//    }
//    return -1;
//}
//int main(){
//    int even[6]={2,4,6,8,14,18};
//    int odd[5]={1,3,5,7,16};
//    int index=binarySearch(even, 6, 18);
//    cout<<index<<"\n";
//
//    return 0;
//}
//
//***OR***
//
//#include<iostream>
//using namespace std;
//int binarySearch(int arr[], int size, int key) {
//
//    int start = 0;
//    int end = size-1;
//
//    int mid = start + (end-start)/2;
//
//    while(start <= end) {
//
//        if(arr[mid] == key) {
//            return mid;
//        }
//
//        //go to right wala part
//        if(key > arr[mid]) {
//            start = mid + 1;
//        }
//        else{ //key < arr[mid]
//            end = mid - 1;
//        }
//
//        mid = start + (end-start)/2;
//    }
//
//    return -1;
//}
//
//
//int main() {
//
//    int even[6] = {2,4,6,8,12,18};
//    int odd[5] = {3, 8, 11, 14, 16};
//
//    int evenIndex = binarySearch(even, 6, 6);
//
//    cout << " Index of 6 is " << evenIndex << endl;
//
//    int oddIndex = binarySearch(odd, 5, 14);
//
//    cout << " Index of 14 is " << oddIndex << endl;
//
//
//    return 0;
//}
