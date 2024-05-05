/*
#include<iostream>
using namespace std;
int getSum(int* arr,int n){
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    return sum;
    

}
int main(){
    // char ch='a';
    // cout<<sizeof(ch)<<endl;
    // char *c=&ch;
    
    // cout<<sizeof(c)<<endl;
    // char* c=new char;




    // int* arr=new int[5];
    // cout<<sizeof(arr)<<endl;
    // cout<<arr<<endl;
    // cout<<&arr[0]<<endl;
    // cout<<&arr[1]<<endl;

    //Dynamically Allocation
    int n;
    cout<<"Enter the size of array\n";
    cin>>n;
    int* arr=new int[n];
    //taking input in array
    for (int  i = 0; i <n; i++)
    {
       cin>>arr[i];
    }
    int ans=getSum(arr,n);
    cout<<"Sum is "<<ans<<endl;
    

    return 0;
}
*/


//2D array Creation Dynamically
#include<iostream>
using namespace std;
int main(){
    
    int n;
    cout<<"Enter the size\n";
    cin>>n;
    //creation of a 2D array Dynamically
    int** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        
    }
    //taking input
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    //Printing Output
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";

        }cout<<endl;
        
    }
    
    /*
    //For different size of rows and columns
    int row;
    int col;
    cout<<"Enetr Rows\n";
    cin>>row;
    cout << "Enter Columns\n";
    cin>>col;

    int**arr=new int*[row];
    for (int i = 0; i < row; i++)
    {
        arr[i]=new int[col];
    }

    // taking input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    // Printing Output
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    //Releasing memory 
    for(int i=0;i<row;i++){
        delete []arr[i]; 
    }
    delete []arr;
    */

    return 0;
}



//DYNAMIC MEMORY ALLOCATION using malloc function
// #include<iostream>
// #include<stdlib.h>//or cstdlib
// using namespace std;
// int main(){
//     int n=5;

//     int* ptr=(int*)malloc(5*sizeof(int));//Dynamically allocated 
//     for (int  i = 0; i < n; i++)
//     {
//         ptr[i]=i*2;
        
//     }
//     //Input taking
//     // cout<<"Enter the values\n";
//     // for (int i = 0; i <n; i++)

//     // {

//     //     cin>>ptr[i];
//     // }
    
//     //Printing
//     for (int i = 0; i < n; i++)
//     {
//         cout<<*ptr<<" ";
//         // cout<<*(ptr+i)<<" ";
//         ptr++;
//     }
//     cout<<endl;
//     free(ptr);
    
    
//     return 0;
// }

//DYNAMIC MEMORY ALLOCATION using calloc function
//By default all Global variables are stored using heap memory
// #include<iostream>
// #include<stdlib.h>//or #include<cstdlib>
// using namespace std;
// int main(){
//     int n=5;
//     int* ptr=(int*)calloc(5,sizeof(int));
//     for (int i = 0; i < n; i++)
//     {
//         cout<<ptr[i]<<" ";
//     }
//     cout<<endl;
//     free(ptr);
    
    
//     return 0;
// }


//NOTE:-Stack memory releases itself as the scope of variable gets over.
//but in case of heap memory ,it neds to be realesed manually at the last
//otherwise the memory gets accumulated and in the end leads to
//memory leakage.For this purpose we use 'delete' keyword

//Syntax for releasing an array
//delete []arr;

//syntax for releasing memory of a variable
//delete var;//hare var is a variable

