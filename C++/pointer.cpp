// #include<iostream>
// using namespace std;
// int main(){
//     // int num=5;
//     // int *ptr=&num;
//     // cout<<num<<endl;
//     // cout<<"Address of num is "<<&num<<endl;
//     // cout<<"Size of integer is "<<sizeof(int)<<endl;
//     // cout<<"Size of pointer is "<<sizeof(ptr)<<endl;
//     // long long int n=5;
//     // long long int *p=&n;
//     // cout << "Size of Pointer is " << sizeof(p) << endl;
//     /*Pointer stores the address ,that's why size of pointer is same for
//      char,int double ,long long int ie. 8 byte */

//      //Initialization of a pointer
//      /*
//      int i=5;
//      int * ptr=&i;
//      //or
//      int *p=0;//p is pointing to NULL
//      p=&i;
//      cout<<ptr<<endl;
//      cout<<*ptr<<endl;
//      cout<<p<<endl;
//      cout<<*p<<endl;
//      */

//     /*
//     int num=5;
//     int a=num;
//     a++;
//     int *ptr=&num;
//     int b=*ptr;
//     b++;//this changes dose not affect in the value of num
//     cout<<b<<endl;
//     cout<<num<<endl;
//     cout<<a<<endl;
//     */
   
   
   
//    /*
//    int n=5;
//    int a=n;
//    cout<<"a before ->"<<n<<endl;
//    a++;//this change does not affect in the value of n
//    cout << "a after ->" << n << endl;
//    int *p=&n;
//    cout<<"Before->"<<n<<endl;
//    (*p)++;
//    cout<<"After->"<<n<<endl;

//    //Copying a pointer
//    int *q=p;
//    cout<<q<<" - "<<p<<endl;
//    cout<<*q<<" - "<<*p<<endl;

//    */

// //   //IMPORTANT CONCEPT->POINTER ARITHMETIC
// //   int i=5;
// //   int *p=&i;
// //   cout<<(*p)++<<endl;
// //   cout<<i<<endl;
// //   cout<<p<<endl;
// //   cout<<(p+1)<<endl;
  

  
   
   


// //     return 0;
// // }


// #include<iostream>
// using namespace std;
// int main(){
//     /*
//     int arr[10]={1,3};
//     int *ptr=&arr[0];
    
//     // cout<<"Address of first memory block of Array->" <<arr<<endl;//gives the address of 1st location of Array
//     // cout<<"Address of first memory block of Array->"<<&arr[0]<<endl;
//     // cout<<(arr+1)<<endl;
//     // cout<<"Value at 0th location "<<*arr<<endl;
//     // cout<<"Value "<<*arr+1<<endl;
//     // //line no 89 & 90 are same
//     // cout<<"Value 1st location: "<<*(arr+1)<<endl;
//     // cout<<"Value 1st location: "<<arr[1]<<endl;
//     // cout<<"Value 1st location: "<<0[arr]<<endl;//formula i[arr]=arr[i]
    
//    cout<<sizeof(ptr)<<endl;
//    cout<<sizeof(&ptr)<<endl;
//    cout<<sizeof(*ptr)<<endl;
//    cout<<sizeof(arr)<<endl;
//    */
//   /*
//   int a[10]={1,4,5};
//   cout<<&a[0]<<endl;
//   cout<<&a<<endl;
//   cout<<a<<endl;
//   int *ptr=&a[0];
//   cout<<ptr<<endl;
//   cout<<"Address of pointer p : "<<&ptr<<endl;//address of pointer
//   cout<<*ptr<<endl;
//   */
//  int arr[10];
//  //arr=arr+1; //address of array is not reassignable in Symbol Table 
//  cout<<arr<<endl;
//  //arr++;this operation can't be done in array

//  int *ptr=&arr[0];
//  cout<<ptr<<endl;
//  ptr=ptr+1;
//  cout<<ptr<<endl;



//   return 0;
// }

//CHARACTER ARRAY
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[10]={1,4,5};
//    // char ch[6]={'R','u','g','u','n','g'};
//     char ch[10]="Rugung D";
//     cout<<arr<<endl;//this prints the address of first location
//     cout<<ch<<endl;//this prints entire string
//     cout<<ch[0]<<endl; //this will print first character of string
//     char *c=&ch[0];
//     cout<<c<<endl; // this prints entire string
    
    
    
//     char temp='A';
//     char *t=&temp;
//     cout<<t<<endl;

//     return 0;
// }


//FUNCTION WITH POINTER
/*
#include<iostream>
using namespace std;
void print(int *p){
    cout<<p<<endl;
    cout<<*p<<endl;
}
void update(int *p){
  //  p=p+1;
   // cout<<"Inside-> "<<p<<endl;
    // cout<<*p<<endl;
    *p=*p+1;

}
int main(){
    int value=5;
    int *ptr=&value;

    print(ptr);
    cout<<"Before ptr-> "<<ptr<<endl;
    cout<<"Before ptr-> "<<*ptr<<endl;

    update(ptr);
    cout<<"After ptr-> "<<ptr<<endl;
    cout<<"After ptr-> "<<*ptr<<endl;
    
    return 0;
}
*/

/*The below Operation is INVALID
#include<iostream>
using namespace std;
void print(int &p){
    cout<<p<<endl;
   cout<<*p<<endl;

}
int main(){
    int value=5;
    int *ptr=&value;
    print(&value);
    
    return 0;
}
*/

// #include<iostream>
// using namespace std;
// //int arr[]=int *arr -> pointer pass
// int getSum(int arr[]/* (int *arr) */,int n){//here the array passed is actually a pointer
//     cout<<"Size of Array : "<<sizeof(arr)<<endl;//
//     int sum=0;
//     for (int i = 0; i <n; i++)
//     {
//        sum+=arr[i];

//     }
//     return sum;
    

// }
// int main(){
//     int arr[6]={1,4,2,5,6,8};
//     //int ans=getSum(arr,5);
//     int ans=getSum(arr+3,3);//{5,6,8} array part is sent through pointer
//     cout<<"The sum is : "<<ans<<endl;


    
//     return 0;
// }



//DOUBLE POINTER
/*
#include<iostream>
using namespace std;
int main(){
    int i=5;
    int* ptr=&i;
    int** p=&ptr;
    cout<<endl;
    cout<<"Address of i-> "<<&i<<endl;
    cout<<"Address of i/content of ptr-> "<<ptr<<endl;
    cout<<"Address of ptr-> "<<&ptr<<endl;
    cout<<"Address of ptr/content of p -> "<<p<<endl;
    cout<<"Address of p -> "<<&p<<endl;
    cout<<"Value -> "<<*p<<endl;//line no 234 & 238 are same

    cout<<endl;
    cout<<"Printing the value at i "<<endl;
    cout<<i<<endl;
    cout<<*ptr<<endl;
    cout<<**p<<endl;

    cout<<endl;
    cout<<"Printing the address of i "<<endl;
    cout<<&i<<endl;
    cout<<ptr<<endl;
    cout<<*p<<endl;

    cout<<endl;
    cout << "Printing the address of ptr " << endl;
    cout<<&ptr<<endl;
    cout<<p<<endl;

    return 0;
}
*/


/*
#include<iostream>
using namespace std;
void update(int **p2){
    //p2=p2+1;//No change in the value
    //cout<<p2<<endl;
    // *p2=*p2+1;//there is change in the value of p
    // cout<<*p2<<endl;
    
    **p2=**p2+1;//there is change in the value of i
    cout<<**p2<<endl;


}
int main(){
    int i=5;
    int *p=&i;
    int ** p2=&p;
    cout<<endl;
    cout<<"Before "<<i<<endl;
    cout<<"Before "<<p<<endl;
    cout<<"Before "<<p2<<endl;
    update(p2);
    cout<<endl;
    cout<<"After "<<i<<endl;
    cout<<"After "<<p<<endl;
    cout<<"After "<<p2<<endl;
    return 0;
}
*/


//MCQs

// #include<iostream>
// using namespace std;
// int main(){
//     int first=8;
//     int second=18;
//     int *ptr=&second;
//     *ptr=9;
//     cout<<first<<" "<<second<<endl;
    
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
//     int first=6;
//     int *p=&first;
//     int *q=p;//copy pointer
//     (*q)++;
//     cout<<first<<endl;
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
//     int first=8;
//     int *p=&first;
//     cout<<(*p)++<<endl;
//     cout<<first<<endl;
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
//     int *p=0;
//     int first=110;
//     *p=first;
//     cout<<*p<<endl;
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
//     int first=8;
//     int second=11;
//     int *third=&second;
//     first=*third;
//     *third=*third+2;
//     cout<<first<<" "<<second<<endl;
//     return 0;
// }

