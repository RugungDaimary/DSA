// Online C++ compiler to run C++ program online
// Merge Sort
#include <iostream>
using namespace std;
void mergeTwoSorted(int arr[], int st, int mid, int e)
{
    int a[e - st + 1];
    int index1 = st;
    int index2 = mid + 1;
    int mainIndex = 0;

    while (index1 <= mid && index2 <= e)
    {
        if (arr[index1] <= arr[index2])
        {
            a[mainIndex] = arr[index1];
            index1++;
        }
        else
        {
            a[mainIndex] = arr[index2];
            index2++;
        }
        mainIndex++;
    }

    while (index1 <= mid) // if 1st array if bigger than 2nd
    {
        a[mainIndex] = arr[index1];
        index1++;
        mainIndex++;
    }

    while (index2 <= e)
    {
        a[mainIndex] = arr[index2];
        index2++;
        mainIndex++;
    }

    mainIndex = 0;
    for (int i = st; i <= e; i++) // for copying the elements back to main array
    {
        arr[i] = a[mainIndex];
        mainIndex++;
    }
}

void mergeSort(int arr[], int st, int e)
{
    if (st >= e)
    {
        return;
    }
    int mid = (st + e) / 2;
    mergeSort(arr, st, mid);
    mergeSort(arr, mid + 1, e);
    mergeTwoSorted(arr, st, mid, e);
}

int main()
{
    int a[6] = {1, 0, 5, 9, 4, 1};
    mergeSort(a, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

//or

// #include <iostream>
// using namespace std;
// void merge(int *arr, int s, int e)
// {

//     int mid = s + (e - s) / 2;
//     int len1 = mid - s + 1;
//     int len2 = e - mid;
//     int *first = new int[len1];
//     int *second = new int[len2];
//     // copying values
//     int mainArrayIndex = s;
//     for (int i = 0; i < len1; i++)
//     {
//         first[i] = arr[mainArrayIndex++];
//     }
//     mainArrayIndex = mid + 1;
//     for (int i = 0; i < len2; i++)
//     {
//         second[i] = arr[mainArrayIndex++];
//     }
//     // merge two sorted arrays;
//     int index1 = 0;
//     int index2 = 0;
//     mainArrayIndex = s;
//     while (index1 < len1 && index2 < len2)
//     {
//         if (first[index1] < second[index2])
//         {
//             arr[mainArrayIndex++] = first[index1++];
//         }
//         else
//         {
//             arr[mainArrayIndex++] = second[index2++];
//         }
//     }
//     while (index1 < len1)
//     {
//         arr[mainArrayIndex++] = first[index1++];
//     }
//     while (index2 < len2)
//     {
//         arr[mainArrayIndex++] = second[index2++];
//     }
//     delete []first;
//     delete []second;
   
// }
// void mergeSort(int arr[], int s, int e)
// {
//     // base case
//     int mid = s + (e - s) / 2;
//     if (s >= e)
//     {
//         return ;
//     }
//     // left part sort
//     mergeSort(arr, 0, mid);
//     // right part sort
//     mergeSort(arr, mid + 1, e);
//     merge(arr, s, e);
    
// }

// int main()
// {
//     int arr[] = {3, 6, 10, 8, 1, 6};
//     int n =6;
//     mergeSort(arr, 0, n - 1);
//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
    
//     return 0;
// }