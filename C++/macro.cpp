// #include<iostream>
// using namespace std;
// #define PI 3.14// No storage is taken for PI,it it will allocate 3.14 to PI before compilation
// int main(){
//     int r=5;
//     // double pi=3.14;//here we are taking storage for variable pi
//     // double area=pi*r*r;
//     double area =PI*r*r;
//     cout<<"Area is "<<area<<endl;
//     return 0;
// }

// C++ program to illustrate macros
// #include <iostream>
// using namespace std;
// // Macro definition
// #define LIMIT 5
// int main()
// {
//     // Print the value of macro defined
//     cout << "The value of LIMIT"
//          << " is " << LIMIT;

//     return 0;
// }

// C++ program to illustrate macros
// #include <iostream>
// using namespace std;
// // Macro definition
// #define AREA(L,B) (L * B)
// int main()
// {
//     // Given lengths L and B
//     // int L = 10, B = 5, area;
//     int L,B,Area;
//     cin>>L>>B;

//     // Find the area using macros
//     Area = AREA(L, B);

//     // Print the area
//     cout << "Area of rectangle"
//          << " is: " << area;

//     return 0;
// }



//GLOBAL VARIABLE
//-> don't make global variable ->Bad Practice
//If global variable is updated by any function then the updated value will reflect to other functions too
//In case of Variable sharing ,we call pass by reference 

//INLINE FUNCTIONS
#include<iostream>
using namespace std;
void fun(int a,int b){
    a++;
    b++;
    cout<<a<<" "<<b<<endl;

}
int main(){
    int a=1,b=4;
    fun(a,b);
    
    return 0;
}

/*
#include<iostream>
using namespace std;
inline int getMax(int& a,int& b){
    return (a > b) ? a : b;//tertiary Operation
}
int main(){
    int a=5,b=4;
    
    int ans=0;
    // if (a>b)
    // {
    //     ans=a;
    //     cout<<a<<endl;
    // }else{
    //     ans=b;
    //     cout<<b<<endl;
    // }

    // using tertiary operation
    // ans=(a>b)?a:b;
    ans=getMax(a,b);
    cout<<ans<<endl;
    // if (ans==a)
    // {
    //     cout << "a = " << a << endl;
    // }else{
    //     cout<<"b = "<<b<<endl;
    // }
    a=a+5;
    b=b+1;
    //ans = (a > b) ? a : b; //Not readable as using many times
    ans=getMax(a,b);
    cout<<ans<<endl;
    return 0;

}
*/

//inline function is used when the function body contains 
//only one line ,and it will replace the value in function call before compilation
//inline for single line in function body
//inline function may be used for 2-3 lines alse if compiler agrees
//inline function can not be used for mare than 3 lines of function body


//DEFALUT ARGUMENTS//
//default argument making(making equal to 0) is done from rightmost parameter in function call
// #include<iostream>
// using namespace std;
// void print(int arr[],int n, int start=0){
//     //here int start=0 means it becomes optional
//     //if we pass the value of start it will print according to the value passed
//     //otherwise it will print whole array as default
//     for (int  i =start; i < n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
    
    
// }
// int main(){
//     int arr[5]={1,5,7,3,4};
//     print(arr,5,3);
//     cout<<endl;
//     print(arr,5);//here no start value is passed,so 
//     //by default it will print whole array
//     cout<<endl;
    

//     return 0;
// }