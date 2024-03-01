//#include<iostream>
//using namespace std;
//void printArry(int arr[],int n){
//    for (int i=0; i<n; i++) {
//        cout<<arr[i]<<" ";
//    }
//}
//void swapAlternate(int arr [],int size){
//    for (int i=0; i<size; i+=2) {
//        if (i+1<size) {
//            swap(arr[i], arr[i+1]);
//        }
//    }
//}
//int main(){
//    int even[]={5,2,9,4,7,6,1,0};
//    int odd[]={1,5,7,8,9};
//    swapAlternate(even, 8);
//    printArry(even, 8);
//    cout<<endl;
//    swapAlternate(odd, 5);
//    printArry(odd, 5);
//    cout<<endl;
//
//    return 0;
//}




//#include<iostream>
//using namespace std;
//int print(int arr[],int n){
//    int ans=0;
//
//    for (int i=0; i<5; i++) {
//        ans=ans^arr[i];
//
//    }
//    cout<<ans<<endl;
//    return ans;
//
//
//
//}
//int main(){
//
//    int arr[]={1,3,2,1,3};
//    print(arr,5);
//
//    return 0;
//}
//
//Qn)Array of integers containing N elements.Each integers is in the range of[1,N-1],with exactly one element repeated in an array
//#include<iostream>
//using namespace std;
//int X(int arr[ ],int N){
//    int ans=0;
//    //XORing all array elements
//    for (int i=0; i<N; i++) {
//        ans=ans^arr[i];
//    }
//    //XORing [1,N-1] elements `
//    for (int i=1; i<N; i++) {
//        ans=ans^i;
//    }
//    return ans;
//}
//int main(){
//    int A[5]={1,2,3,4,2};
//    int result=X(A, 5);
//    cout<<result<<endl;
//
//    return 0;
//}

//Qn)Sort 0 and 1

#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortOne(int arr[], int n) {

    int left = 0, right = n-1;

    while(left < right) {

        while(arr[left] == 0 && left < right )  {
            left++;
        }

        while(arr[right]==1 && left < right){
            right--;
        }

        //agar yha pohoch gye ho, iska matlab
        //arr[left]==1 and arr[right]==0
        if(left<right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

}

int main() {

    int arr[8] = {1,1,0,0,0,0,1,0};

    sortOne(arr, 8);
    printArray(arr, 8);


    return 0;
}

//Qn)Sort 0,1 and 2

