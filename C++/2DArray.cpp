// #include<iostream>
// using namespace std;
// //column wise traverse
// // bool isPresent(int arr[][4],int target,int row ,int col){
// //     for (int col = 0; col < 4; col++)
// //     {
// //         for (int row = 0; row < 3; row++)
// //         {
// //             if(arr[row][col]==target){
// //                 return 1;
// //             }
            
// //         }
        
// //     }
// //     return false;
// // }


// //row wise traverse
// bool isPresent(int arr[][4],int target,int row,int col){
//     for (int row = 0; row < 3; row++)
//     {
//         for (int col = 0; col < 4; col++)
//         {
//             if (arr[row][col]==target)
//             {
//                 return true;
//             }else{
                
//             }
            
//         }
        
//     }
//     return false;
// }
// int main(){
//     //creation of 2D array

//     int arr[3][4];/* = {1 ,2, 3 ,4 ,5 ,6 ,7, 8, 9, 1, 2 ,3};*/
//     // takes row-wise input
//     // int arr[3][4]={0};//initialize with 0
//     // int arr[3][4]={{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};
//     // cout << "Enter the values  : \n";
    
//     for (int row=0; row<3; row++) {
//         for (int col=0; col<4; col++) {
//             cin>>arr[row][col];

//         }
        
//     }
//     //Taking column wise input
//     //int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3};
    

//     // for (int col = 0; col <4; col++)
//     // {
//     //     for (int row = 0; row <3; row++)
//     //     {
//     //         cin>>arr[row][col];
//     //     }
        
//     // }
//     //Linear Search
//     cout<<"Enter the target\n";
//     int target;

//     cin>>target;
    
//     //Printing
//     // for (int row=0; row<3; row++) {
//     //     for (int col=0; col<4; col++) {
//     //         cout<<arr[row][col]<<" ";
//     //     }
//     //     cout<<endl;
        
//     // }
//     int ans=isPresent(arr,target,3,4);
//     if (ans==1)
//     {
//         cout<<"Element is present\n";
//     }else{
//         cout<<"Element is not present\n";
//     }
    
    
    
//     return 0;
// }

//Qn)Linear Search
// #include <iostream>
// using namespace std;
// bool isPresent(int arr[][4], int target, int row, int col)
// {
//     for (int col = 0; col < 4; col++)
//     {
//         for (int row = 0; row < 3; row++)
//         {
//             if (arr[row][col] == target)
//             {
//                 return 1;
//             }
//         }
//     }
//     return false;
// }
// int main(){
//     int arr[3][4];
//     //taking input
//     for (int row = 0; row < 3; row++)
//     {
//         for (int col = 0; col < 4; col++)
//         {
//             cin >> arr[row][col];
//         }
//     }
//     //for printing
//     cout<<endl;

//     for (int row=0; row<3; row++) {
//             for (int col=0; col<4; col++) {
//                 cout<<arr[row][col]<<" ";
//             }
//             cout<<endl;

//         }



//     cout << "Enter the target\n";
//     int target;

//     cin >> target;

//     int ans = isPresent(arr, target, 3, 4);
//     if (ans == 1)
//     {
//         cout << "Element is present\n";
//     }
//     else
//     {
//         cout << "Element is not present\n";
//     }
//     return 0;
// }

////Qn)Row wise sum
// #include<iostream>
// using namespace std;
// void printSum(int arr[][3],int row,int col){
//     cout<<"Printing Sum row wise--> \n";
//     for (int row = 0; row < 3; row++)

//     {
//         int sum = 0;
//         for (int col = 0; col < 3; col++)
//         {
//             sum+= arr[row][col];
//         }
//         cout<<"Sum : "<<sum<<endl;
//     }
//     cout<<endl;
// }
// // column wise sum
// // void printSum(int arr[][4], int row, int col)
// // {
// //         cout<<"Printing Sum column  wise--> \n";
// //         for (int col = 0; col < 4; col++)

// //         {
// //             int sum = 0;
// //             for (int row = 0; row < 3; row++)
// //             {
// //                 //sum+= arr[row][col];
// //                 sum=sum+arr[row][col];
// //             }
// //             cout<<"Sum : "<<sum<<endl;
// //         }
// //         cout<<endl;
// //     }
// int largestRowSum(int arr[][3],int row,int col){
//     int maxi=INT_MIN;
//     int rowIndex=-1;
//     for (int row = 0; row < 3; row++)

//     {
//         int sum = 0;
//         for (int col = 0; col < 3; col++)
//         {
//             sum += arr[row][col];
//         }
//         if (sum>maxi)
//         {

//             maxi=sum;
//             rowIndex=row;
//         }

//     }
//     cout <<"The maximum Sum is "<<maxi<< endl;
//     return rowIndex;
// }
// int main()
//     {
//         int arr[3][3];
//         cout << "Enter the elements\n";
//         // for taking inputs
//         for (int row = 0; row < 3; row++)
//         {
//             for (int col = 0; col < 3; col++)
//             {
//                 cin >> arr[row][col];
//             }
//         }
//         // printing the 2D array
//         cout<<endl;
//         for (int row = 0; row < 3; row++)
//         {
//             for (int col = 0; col < 3; col++)
//             {
//                 cout << arr[row][col] << " ";
//             }
//             cout << endl;
//         }
//         printSum(arr, 3, 3);
//         int ansIndex = largestRowSum(arr, 3, 3);
//         cout<<"Max rowSum is at index "<<ansIndex<<endl;

//         return 0;
//     }


//Wave Print problems
// #include<iostream>
// using namespace std;
// void printWave(int arr[3][3],int row,int col){
//     for (int col = 0; col < 3; col++)
//     {
//         if (col & 1)
//         {
//             // odd column index->bottom to top
//             for (int row = 3 - 1; row >= 0; row--)
//             {
//                 cout << arr[row][col] << " ";
//             }
//         }
//         else
//         {
//             // 0 or Even index
//             for (int row = 0; row < 3; row++)
//             {
//                 cout << arr[row][col] << " ";
//             }
//         }
//     }
// }

// void printArray(int arr[3][3],int row,int col){
//     for (int row = 0; row <3; row++)
//     {
//         for (int col  = 0; col < 3; col++)
//         {
//             cout<<arr[row][col]<<" ";
//         }
//         cout<<endl;
        
//     }
    

// }

// int main(){
//     int arr[3][3]={1,2,3,4,4,6,7,8,9};
//     printArray(arr,3,3);
//     cout<<endl;
//     printWave(arr,3,3);
//     cout<<endl;
    

//     return 0;
// }


// Rotation of a Matrix in anti clock wise
// #include <iostream>
// using namespace std;
// void printBeforeRotation(int arr[][3], int row, int col)
// {
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }
// void inplaceRotate(int arr[][3], int row, int col)
// {
//     // int row = inputArray.size();
//     // int col = inputArray[0].size();
//     // transpose:-
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = i; j < col; j++)
//         {
//             swap(arr[i][j], arr[j][i]);
//         }
//     }




//     // reverse row wise:-
//     for (int i = 0; i < row; i++)
//     {
//         int s = 0;
//         int e = row - 1;
//         while (s <= e)
//         {
//             swap(arr[s][i], arr[e][i]);
//             s++;
//             e--;
//         }
//     }
//     return;
// }
// void printAfterRotation(int arr[][3], int row, int col)
// {
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }
// int main()
// {
//     int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     printBeforeRotation(arr, 3, 3);
//     inplaceRotate(arr, 3, 3);
//     cout << endl;
//     printAfterRotation(arr, 3, 3);
//     return 0;
// }

// Rotation of a Matrix in clock wise 90 degree
#include <iostream>
using namespace std;
void printBeforeRotation(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void inplaceRotate(int arr[][3], int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    // reverse col wise:-
    for (int i = 0; i < col; i++)
    {
        int s = 0;
        int e = col- 1;
        while (s <= e)
        {
            swap(arr[i][s], arr[i][e]);
            s++;
            e--;
        }
    }
    return;
}
void printAfterRotation(int arr[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printBeforeRotation(arr, 3, 3);
    inplaceRotate(arr, 3, 3);
    cout << endl;
    printAfterRotation(arr, 3, 3);
    return 0;
}
//Spiral Print
// #include<iostream>
// using namespace std;
// void printSpiral(int &matrix){
    
     
// }
// int main(){
    
//     return 0;
// }

/* SOLUTION : 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int>ans;
        
    int row=matrix.size();
    int col=matrix[0].size();
    int count=0;
    int total=row*col;
    //index intialization
    int startingRow=0;
    int startingCol=0;
    int endingRow=row-1;
    int endingCol=col-1;

    while (count<total)
    {
        //print starting row
        for (int index = startingCol;count<total && index <= endingCol; index++)
        {
            ans.push_back(matrix[startingRow][index]);
            count++;
            
        }
        startingRow++;
        //printing ending column
        for(int index=startingRow;count<total && index<=endingCol;index++){
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;
        //printing ending row
        for(int index=endingCol;count<total && index>=startingCol;index-- ){
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;
        //printing 1st column
        for(int index=endingRow;count<total && index>=startingRow;index--){
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
        
    }
        return ans;
    
        
    }
};
*/
/* SPIRAL PRINT 
#include<iostream>
using namespace std;
void spiralPrint(int **input, int nRows, int nCols)
{
    int row = nRows;
    int col = nCols;
    int count = 0;
    int startingRow = 0;
    int startingCol = 0;
    int endingCol = nCols - 1;
    int endingRow = nRows - 1;
    int total = nRows * nCols;
    while (count < total)
    {
        // printing starting row
        for (int index = startingCol; count < total && index <= endingCol; index++)
        {
            cout<<index<<" ";
            count++;
        }
        startingRow++;
        for (int index = startingRow; count < total && index <= endingRow; index++)
        {
            cout << index << " ";
            count++;
        }
        endingCol--;
        for (int index = endingCol; count < total && index <= startingCol; index--)
        {
            cout << index << " ";
            count++;
        }
        endingRow--;
        for (int index = endingRow; count < total && index <= startingRow; index--)
        {
            cout << index << " ";
            count++;
        }
        startingCol++;
    }
}
int main(){
    int arr[3][3] = {1, 2, 3, 4, 4, 6, 7, 8, 9};
    spiralPrint(arr,3,3);

    return 0;

}
*/




//ROTATE MATRIX BY 90
// #include<iostream>
// #include<vector>
// using namespace std;
// void inplaceRotate(vector<vector<int> > &matrix)
// {
    
//     int row = matrix.size();//finding no of rows
//     int col = matrix[0].size();//finding no of columns
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = i; j < col; j++)
//         {
//             swap(matrix[i][j], matrix[j][i]);

//         }
//     }
//     for (int i = 0; i < row / 2; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             swap(matrix[i][j], matrix[row - i - 1][j]);
//         }
//     }
// }
// int main(){
    


    
//     return 0;

// }

//BINARY SEARCH IN 2D matrix
/* 
class solution{
    public:
    bool searchMatrix(vector<vector<int>>&matrix int target){
        int row=matrix.size();
        int col=matrix[0].size();
        int start=0;
        int end=row*col-1;
        int mid=start+(end-start)/2;
        while (start<=end)
        {
            int element=matrix[mid/col][mid%col];//finding mid element
            if (element==target)
            {
                return 1;
            }
            else if(element<target){
                start=mid+1;

            }else{
                end=mid-1;
            }
            mid=start+(end-start)/2;


        }
        return 0;
        

    }

};
*/

 
