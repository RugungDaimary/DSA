#include<iostream>
using namespace std;
void bubbleSort(int arr[ ],int n){
    for (int i=1; i<n; i++) {//for round 1 to n-1
        bool swapped=false;// if the arry is already sorted,then the outer loop runs only once
        for (int j=0; j<n-i; j++) {//(n-i) in each i th round i th largest element is right placed
            //process element till n-i th index
            if (arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped=true;
            }
        }
        if (swapped==false) {//already sorted
            break;
        }
    }

}
void printArray(int arr[], int size)
{
    
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main(){
    int arr[] = { 5,1,4,2,8,10,0,3,7,6};
   // int N = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, 10);//(arr,N);
    cout << "Sorted array: by BubbleSort \n";
    printArray(arr, 10);//(arr,N);

    return 0;
}


