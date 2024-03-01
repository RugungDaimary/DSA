#include<iostream>
using namespace std;
int main(){
   //declaration
   int number[15];
   cout<<number[14]<<endl;// random value will store in container

   //initializing an array
   int arr[3]={2,1,9};
   cout<<arr[2]<<endl;

   int num[20]={1,2,7};
   cout<<num[9]<<endl;
   for (int i=0; i<=19; i++) {
       cout<<num[i]<<" ";
   }
   cout<<endl;

   int A[10]={0};//initializing all locations with 0
   for (int i=0; i<=9; i++) {
       cout<<A[i]<<" ";
   }
   cout<<endl;

   int X[10]={1};
   for (int i=0; i<=9; i++) {
       cout<<X[i]<<" ";
   }
   cout<<endl;
   cout<<"Everything is fine\n";

   
   return 0;
}

//WAP to enter price of three items and print their final cost with 18%of gst
//#include<iostream>
//using namespace std;
//int main(){
//    float price[3]={100.0,200.0,300.0};
////    cout<<"Enter three prices\n";
////    cin>>price[0]>>price[1]>>price[2];
//    cout<<"Total price of 1 "<<price[0]+(0.18*price[0])<<endl;
//    cout<<"Total price of 2 "<<price[1]+(0.18*price[1])<<endl;
//    cout<<"Total price of 3 "<<price[2]+(0.18*price[2])<<endl;
//
//    return 0;
//}


//***ARRAY WITH FUNCTION***//
//#include<iostream>
//using namespace std;
//void printArry(int arr[],int size){//size mentioning of an array is not compulsury
//    cout<<"\nPrinting the Array \n";
//    for (int i=0; i<size; i++) {
//        cout<<arr[i]<<" ";
//    }
//}
//int main(){
//    int arr[15]={1,3,4,9};//the actual length is 15 but here 4 out of 15 are occupied only
//    int size=15;
//    printArry(arr, size);//function call
//    int first[5]={4,5,6,3,1};
//    printArry(first, 5);
//    int arrSize=sizeof(arr)/sizeof(int);//1 block occupies 4 bytes
//    cout<<endl;
//    cout<<"The actual size of arr is : "<<arrSize<<endl;
//    return 0;
//}


//**** How do you initialize an entire array with the same value in C++ ****
//#include<iostream>
//using namespace std;
//int main()
//{
//    int n;
//    cin>>n;
//    int val=5;// declare array
//    int arr[n];
//    for (int i=0;i<n;i++){ // initialize array
//        arr[i]=val;
//        cout<<arr[i]<<" ";
//    }
//
//
//
//    return 0;
//}

//***DIFFERENT TYPES OF ARRAY*****//
//#include<iostream>
//using namespace std;
//void printArry(char arr[],int n){
//
//    for (int i=0; i<n; i++) {
//        cout<<arr[i]<<" ";
//
//    }
//    cout<<": Char Done\n";
//
//}
//void X(float arr[],int n){
//    for (int i=0; i<n; i++) {
//        cout<<arr[i]<<" ";
//
//    }
//    cout<<": Float Done\n";
//}
//void Y(bool arr[],int n){
//    for (int i=0; i<n; i++) {
//        cout<<arr[i]<<" ";
//    }
//    cout<<": Bool Done\n";
//    cout<<endl;
//}
//
//int main(){
//
//    char ch[4]={'a','b','d','z'};
//    for (int i=0; i<4; i++) {
//        cout<<ch[i]<<" ";
//
//    }
//    cout<<endl;
//    printArry(ch, 4);
//
//   // double first[5];
//    float second[10]={3.14,7.12};
//    bool third[6]={1,0,1};
//    Y(third, 6);
//    X(second,5);
//    return 0;
//}
//

//****Finding Maximum / Minimum element in an array***
//#include<iostream>
//using namespace std;
//int GetMax(int num[],int n){
//    int max=INT_MIN;
//    for (int i=0; i<n; i++) {
//        if (num[i]>max) {
//            max=num[i];
//        }
//
//    }
//    //returning max value
//    return max;
//
//}
//int GetMin(int num[],int n){
//    int min=INT_MAX;//min pe sabse maximum value padi hongi
//    for (int i=0; i<n; i++) {
//        if (num[i]<min) {
//            min=num[i];
//        }
//
//    }
//    //returning min value
//    return min;
//
//}
//int main(){
//    int size;
//    cin>>size;
//    int num[100];
//    cout<<"Enter the values\n";
//    for (int i=0; i<size; i++) {//taking input in array
//        cin>>num[i];
//    }
//    cout<<"Maximum value is "<<GetMax(num, size)<<endl;
//    cout<<"Minimum value is "<<GetMin(num, size)<<endl;
//    return 0;
//}


//**Another Method
//#include<iostream>
//using namespace std;
//int GetMax(int num[],int n){
//    int maxi=INT_MIN;
//    for (int i=0; i<n; i++) {
//        max=max(maxi,num[i]);
//    }
//    return max;
//
//}
//int main(){
//    int n;
//    cin>>n;
//    int arr[10];
//    for (int i=0; i<n; i++) {
//        cin>>arr[i];
//
//    }
//    GetMax(arr, 10);
//
//    return 0;
//}
//
//
//
