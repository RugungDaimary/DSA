/* Qn)Given two integers M & N, calculate and return
 their multiplication using recursion. You can 
 only use subtraction and addition for your calculation.
  No other operators are allowed.
 */
// #include<iostream>
// using namespace std;
// // int multi(int m ,int n){
// //     //base case
// //     if (n==0)
// //     {
// //         return 0;
// //     }
// //     int smallPrblm=m*(n-1);
// //     int bigPrblm=m+smallPrblm;
// //     return bigPrblm;
    
// // }
// int multi(int m ,int n){
//     if (n==0)
//     {
//         return 0;
//     }
//     int a=m*(n-1);
//     return a+m;
// }
// int main(){
//     int m,n;
//     cin>>m>>n;
//     int ans=multi(m,n);
//     cout<<"Multiplication : "<<m<<"*"<<n<<" is " <<ans<<endl;
    
//     return 0;
// }

/*
Given an integer N, count and return the number of
 zeros that are present in the given integer 
 using recursion.*/
// #include<iostream>
// using namespace std;
// int CountZero(int n){
//     //base case
//     if (n == 0 )
//     {
        
//         return 1;
//     }
//     if (n % 10 == 0)
//     {
//         return CountZero(n/10)+1;
//     }
    
//     if (n>0 && n<10){
//         return 0;
//     }
//     else
//     {
//         int small = CountZero(n / 10);
//         return small;
//     }
// }
// int main(){
//     int n;
//     cout<<"Enter n\n";
//     cin>>n;
//     int ans=CountZero(n);
//     cout<<"Number of Zeros-> "<<ans<<endl;

    
//     return 0;
// }


/*Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) */
// #include<iostream>
// #include<math.h>
// using namespace std;
// float gSum(int k){
//     //base case
//     if (k==0)   
//     {
//         return 1;
//     }
//     float small=gSum(k-1);
//     float big=1/pow(2,k)+small;
//     return big;

// }
// int main(){
//     int k;
//     cin>>k;
//     cout<<gSum(k)<<endl;
//     return 0;
// }

/*Write a recursive function that returns 
the sum of the digits of a given integer.*/
// #include<iostream>
// using namespace std;
// int digitSum(int n){
//     //base case
//     if (n==0)
//     {
//         return 0;
//     }
//     //recursive relation
//     if (n>0 && n<10)
//     {
//         return n;
//     }
//     else{
//         int a=n%10;//if here we take static int a what happens then? think about it
//         int small=digitSum(n/10);
//         return small+a;
//     }
    

// }
// int main(){
//     int n;
//     cout<<"Enter n : ";
//     cin>>n;
//     cout<<"Digits Sum -> "<<digitSum(n)<<endl;

    
//     return 0;
// }

//FIBONACCI SERIES using recursion
// #include<iostream>
// using namespace std;
// int fib(int n){//finding n th number in fibonacci series
//     //base case
//     if (n==0)
//     {
//         return 0;
//     }
//     if (n==1)
//     {
//         return 1;
//     }
    
//     // int small2=fib(n-2);
//     // int small1=fib(n-1);
//     // return small1+small2;
//     int small=fib(n-1)+fib(n-2);
//     return small;


// }
// int main(){
//     int n;
//     cout<<"Enter the value of n\n";
//     cin>>n;
//     int ans=fib(n);
//     cout<<"n th Fibonacci number is "<<ans<<endl;
    
//     return 0;
// }

//Printing the numbers

// #include<iostream>
// using namespace std;
// int print (int n){
   
//     if (n==1)
//     {
//        //cout<<n<<" ";
//        cout<<n<<" ";
//        return 1;
//     }
//     //recursive call
//     //cout << n << " ";//will reverse the order
//     int small=print(n-1);
//     cout << n << " ";
   
//     return small;


// void print(int n)
// {
//     cout << n << " ";
//     if (n > 1)
//     {
//         print(n - 1);
//     }

// }


// int main(){
//     int n;
//     cout<<"Enetr n\n";
//     cin>>n;
//     print(n);
//     cout << endl;
//     return 0;
// }


//counting the number of digits
// #include<iostream>
// using namespace std;
// int CountDigits( int n){
//     //base case
//     if (n>=0 && n<10)
//     {
//         return 1;
//     }
//     //recursive call
//     else{

//         int small = CountDigits(n / 10);
//         return small+1;
//     }

// int digit(int n)
// {
//     if (n / 10 == 0)
//     {
//         return 1;
//     }
//     else
//     {
//         int small = digit(n / 10);
//         return small + 1;
//     }
// }

// }
// int main(){
//     int n;
//     cout<<"Enter n\n";
//     cin>>n;
//     cout<<"Number of digits "<< CountDigits(n)<<endl;
    
//     return 0;
// }


//checking if an array is sorted or not
// #include<iostream>
// using namespace std;
// bool arraySort(int arr[],int size){
//     //base case
//     if (size==0 || size==1)
//     {
//         return true;
//     }
//     //checking first two elements
//     if (arr[0]>arr[1])
//     {
//         return false;
//     }
//     bool isSmallerSorted=arraySort(arr+1,size-1);
//     return isSmallerSorted;
//     /*
//     if (isSmallerSorted)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
//     */    
// }
// int main(){
    
//     int arr[5]={1,8,5,7,9};
//     int ans=arraySort(arr,5);
//     cout<<endl;
//     if (ans==0)
//     {
//         cout<<"Not sorted\n";
//     }else{
//         cout<<"Sorted\n";
//     }
    
//     return 0;
// }

//Array Sum
// #include<iostream>
// using namespace std;
// int arraySum(int a[],int n){
//     if (n==0)
//     {
//         return 0;
//     }
//     //recursive call
//     int smaller=arraySum(a+1,n-1);
//     return smaller+a[0];
    
// }
// int sum(int *a, int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     if (n == 1)
//     {
//         return a[0];
//     }
//     else
//     {
//         int smallSum = sum(a + 1, n - 1);
//         return smallSum + a[0];
//     }
// }
// int main(){
//     int a[3]={4,2,1};
//     cout<<arraySum(a,2)<<endl;

//     return 0;
// }

// 

// finding the factorial using recursion
// #include <iostream>
// using namespace std;
// int fact(int n)
// {
//     cout << n << endl;
//     // base case
//     if (n == 0)
//     {
//         return 1;
//     }
//     int smallPrblm = fact(n - 1);
//     int bigPrblm = n * smallPrblm;
//     return bigPrblm;
// }

// int main()
// {
//     int n;
//     cout << "Enter n\n";
//     cin >> n;
//     cout << endl;
//     int ans = fact(n);
//     cout << endl;
//     cout << ans << endl;

//     return 0;
// }

//Checking x is present or not in an array
// #include<iostream>
// using namespace std;
// bool isPresent(int a[],int n,int x){
//     //base case
//     if (n==0)
//     {
//         return false;
//     }
//     // small calculation
//     if (a[0]==x)
//     {
//         return true;
//     }
    
//     //recursive call
//     bool isPresentinSmaller=isPresent(a+1,n-1,x);
//     return isPresentinSmaller;
    
// }
// int main(){
//     int a[3]={9,8,10};
//     int x=2;
//     int ans=isPresent(a,3,x);
//     if (ans==1)
//     {
//         cout<<"Is Present\n";
//     }else{
//         cout<<"Not Present\n";
//     }
    
    
//     return 0;
// }

//1st Index
// #include <iostream>
// using namespace std;
// int firstIndex(int *a, int n, int k)
// {
//     if (n == 0)
//     {
//         return -1;
//     }
//     if (a[0] == k)
//     {
//         return 0;
//     }
//     else
//     {
//         int small = firstIndex(a + 1, n - 1, k);
//         if (small == -1)
//         {
//             return small;
//         }
//         else
//         {
//             return small + 1;
//         }
//     }
// }
// int main()
// {
//     int a[] = {1, 2, 3, 4, 5};
//     int k = 1;
//     cout << firstIndex(a, 5, k) << endl;

//     return 0;
// }


//LAST INDEX of X
// #include<iostream>
// using namespace std;
// int lastIndex(int *a,int n,int k){
    //base case
//     if(n==0){
//         return -1;
//     }
//small calculation
//     if(a[n-1]==k){
//         return n-1;
//     }else{
//         int small=lastIndex(a,n-1,k);//recursive call
//         return small;
//     }
// }
// other appraoch
// int lastIndex(int*a ,int n,int k){
//     //base case
//     if(n==0){
//         return -1;
//     }
//     //recursive call
//     int small=lastIndex(a+1,n-1,k);
//     //small calculation
//     if(small==-1){
//         if(a[0]==k){
//             return 0;
//         }else{
//             return -1;
//         }
//     }else{
//         return small+1;
//     }

// }
// int main(){
//     int a[]={1,3,5,1,7};
//     int k=10;
//     cout<<lastIndex(a,5,k)<<endl;
    
//     return 0;
// }


//ALL INDECES
#include<iostream>
#include<vector>
using namespace std;
int allIndex(int *a,int n,int k,vector<int> &output){
    
    if(n==0){
        return 0; 
    }
    int small=allIndex(a,n-1,k,output);
    
    if(a[n-1]==k){
        output.push_back(n-1);
       
        return output.size();


    }else{
        return output.size();
    }

    

}

int main(){
    int a[]={1,3,3,4,3};
    int k=3;
    vector<int>v;
    cout<<allIndex(a,5,k,v)<<endl;
    cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    
    
    return 0;
}



//OR

// this is the better way
// #include <iostream>
// #include <vector>
// using namespace std;

// void allIndexes(int *arr, int size, int target, vector<int> &output)
// {
//     if (size == 0)
//     {
//         return;
//     }

//     allIndexes(arr, size - 1, target, output);

//     if (arr[size - 1] == target)
//     {
//         output.push_back(size - 1);
//     }
// }

// int main()
// {
//     int a[] = {1, 3, 3, 4, 3};
//     int k = 3;
//     vector<int> v;

//     allIndexes(a, 5, k, v);

//     if (v.empty())
//     {
//         cout << "Element not found." << endl;
//     }
//     else
//     {
//         for (int i = 0; i < v.size(); i++)
//         {
//             cout << v[i] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }
