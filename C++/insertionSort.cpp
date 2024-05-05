#include<iostream>
using namespace std;
void insertionSort(int arr[ ],int n){
    for (int i=1; i<n; i++) {//i starts from 1,as 1st element(0th index element) is sorted(assumed),ie.FOR ROUNDS
        int temp=arr[i];//to compare the i th element   
        int j=i-1;
        for (; j>=0; j--) {
            if (arr[j]>temp) {
                //shift
                arr[j+1]=arr[j];
            }
            else{
                //ruk jao
                break;
            }
        }
        arr[j+1]=temp;
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
    insertionSort(arr, 10);//(arr,N);
    cout << "Sorted array: by InsertionSort \n";
    printArray(arr, 10);//(arr,N);
    return 0;
}

