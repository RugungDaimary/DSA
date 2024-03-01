#include<iostream>//Some errors are present
using namespace std;
void selectionSort(int arr[],int n){
    for (int i=0; i<n-1; i++) {
        int minIndex=i;  // Find the minimum element in unsorted array
        for (int j=i+1; j<n; j++) {//loop for finding minimum value in unsorted array
            if (arr[j]<arr[i])
                minIndex=j;


        }
        swap(arr[minIndex], arr[i]); // Swap the found minimum element with the first element


    }


}

void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int Array[]={5,7,1,6,9,4,0,2,8,3};
    //int n=sizeof(Array)/sizeof(Array[0]);
    selectionSort(Array,10);
    cout<<"Sorted Array: by SelectionSort\n";
    printArray(Array, 10);

    return 0;
}





//
//// C++ program for implementation of
//// selection sort
//#include <iostream>
//using namespace std;
//
////Swap function
//void swap(int *xp, int *yp)
//{
//    int temp = *xp;
//    *xp = *yp;
//    *yp = temp;
//}
//
//void selectionSort(int arr[], int n)
//{
//    int i, j, min_idx;
//
//    // One by one move boundary of
//    // unsorted subarray
//    for (i = 0; i < n-1; i++)
//    {
//
//        // Find the minimum element in
//        // unsorted array
//        min_idx = i;
//        for (j = i+1; j < n; j++)
//        if (arr[j] < arr[min_idx])
//            min_idx = j;
//
//        // Swap the found minimum element
//        // with the first element
//        if(min_idx!=i)
//            swap(&arr[min_idx], &arr[i]);
//    }
//}
//
////Function to print an array
//void printArray(int arr[], int size)
//{
//    int i;
//    for (i=0; i < size; i++)
//        cout << arr[i] << " ";
//    cout << endl;
//}
//
//// Driver program to test above functions
//int main()
//{
//    int arr[] = {5,7,1,6,9,4,0,2,8,31};
//    int n = sizeof(arr)/sizeof(arr[0]);
//    selectionSort(arr, n);
//    cout << "Sorted array: \n";
//    printArray(arr, n);
//    return 0;
//}
//// This is code is contributed by rathbhupendra
//
