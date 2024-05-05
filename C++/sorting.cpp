
// SELECTION SORT
/*
#include <iostream>
using namespace std;
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) // i represents the current round//for rounds
    {
        // find minimum element in the array
        int min = arr[i]; // assuming the first element as minimum
        int minIndex = i; // initialized with first index,index of min element
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {4, 7, 1, 0, 8, 6};

    print(arr, 6);
    selectionSort(arr, 6);
    print(arr, 6);

    return 0;
}
*/

//BUBBLE SORT
#include<iostream>
using namespace std;
void bubbleSort(int *arr,int n){
    for (int j = 0; j <n-1; j++)
    {
        for (int i = 0; i < n - 1-i; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
    
    
    
}

int main(){
    int arr[]={10,12,1,8,2,5};
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
     cout << endl;
    bubbleSort(arr,6);
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    

    
    return 0;
}
