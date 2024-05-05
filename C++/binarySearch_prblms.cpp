//***In a given sorted array find the index of first and last occurrence of 'K' in the array
#include<iostream>
using namespace std;
int firstOcc(int arr[],int n,int key){
  int s=0,e=n-1;
  int mid=s+(e-s)/2;
  int ans=-1;
  while (s<=e) {
      if (arr[mid]==key) {
          ans=mid;
          e=mid-1;
      }else if (arr[mid]>key){
          e=mid-1;//left part
      }else if(arr[mid]<key){
          s=mid+1;//right part
      }
      mid=s+(e-s)/2;
  }
  return ans;
}
int lastOcc(int arr[],int n,int key){
  int s=0,e=n-1;
  int mid=s+(e-s)/2;
  int ans=-1;
  while (s<=e) {
      if (arr[mid]==key) {
          ans=mid;
          s=mid+1;
      }else if (arr[mid]>key){
          e=mid-1;//left part
      }else if(arr[mid]<key){
          s=mid+1;//right part

      }
      mid=s+(e-s)/2;
  }
  return ans;
}
int main(){
  int odd[10]={1,2,2,3,3,3,3,3,3,5};
  cout<<"First Occurrence of 3 is at index "<<firstOcc(odd, 10, 3)<<endl;
  cout<<"Last Occurrence of 3 is at index "<<lastOcc(odd, 10, 3)<<endl;

  return 0;
}


//Qn)Finding peak element in a mountain array
// #include<iostream>
// using namespace std;
// int peak(int arr[ ],int n){
//    int s=0;
//    int e=n-1;
//    int mid=s+(e-s)/2;
//    while (s<e) {//here <= sign is not used
//        if (arr[mid]<arr[mid+1]) {
//            s=mid+1;
//        }else{
//            e=mid;
//        }
//        mid=s+(e-s)/2;
//    }
//    return s;


// }
// int main(){
//    int odd[10]={1,3,5,6,8,10,12,15,50,2};

//    cout<<"The peak element is present at index "<<peak(odd, 10)<<endl;

//    return 0;
// }


//Qn) Finding pivot element in a sorted rotated array
//#include<iostream>
//using namespace std;
//int getPivot(int arr[],int n){
//    int s=0,e=n-1;
//    int mid=s+(e-s)/2;
//    while (s<e) {
//        if (arr[mid]>=arr[0]) {
//            s=mid+1;
//        }else{//arr[mid]<=arr[0]
//            e=mid;
//        }
//        mid=s+(e-s)/2;
//
//    }
//    return s;//return e;
//}
//int main(){
//    int arr[]={5,8,9,10,1};
//    cout<<"Pivot is "<<getPivot(arr,5)<<endl;
//
//    return 0;
//}
//
//

//Qn)Finding the square root of an integer using Binary search
//#include<iostream>
//using namespace std;
//long long int SqrtN(int n){
//    long long int s=0;
//    long long int e=n;
//    long long int ans=0;
//    long long int m=s+(e-s)/2;
//    while (s<=e) {
//        long long int square=m*m;
//        if (square==n) {
//            return m;
//        }
//        if (square<n) {
//            ans=m;
//            s=m+1;
//        }else{
//            e=m-1;
//        }
//        m=s+(e-s)/2;
//    }
//    return ans;
//}
//int main(){
//    long long int result=SqrtN(1000000);
//    cout<<result<<endl;
//
//    return 0;
//}
//


//***With more precision**//for double numbers
// #include<iostream>
// using namespace std;
// long long int SqrtN(int n){
//     long long int s=0;
//     long long int e=n;
//     long long int ans=0;
//     long long int mid=s+(e-s)/2;
//     while (s<=e) {
//         long long int square=mid*mid;
//         if (square==n) {
//             return mid;
//         }
//         if (square<n) {
//             ans=mid;
//             s=mid+1;
//         }else{
//             e=mid-1;
//         }
//         mid=s+(e-s)/2;
//     }
//     return ans;
// }
// double morePrecision(int n,int precision,int tempSol){
//     double factor =1;
//     double ans=tempSol;
//     for (int i=0; i<precision; i++) {
//         factor=factor/10;//0.1
//                          //0.01
//                          //0.001
//         for (double j=ans; j*j<n; j=j+factor) {
//             ans=j;
//         }
//     }
//     return  ans;
    
// }
// int main(){
//     int n;
//     cout<<"Enter the value of n\n";
//     cin>>n;
//     int tempSol=SqrtN(n);
//     cout<<"Answer is "<<morePrecision(n,5,tempSol)<<endl;
//     return 0;
// }

