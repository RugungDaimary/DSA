//Finding the length of character array
// #include<iostream>
// #include<cstring>
// using namespace std;
// int getLength(char arr[],int n){
//     if(arr[0]=='\0'){
//         return 0;
//     }
//     else{
//         int small=getLength(arr+1,n);
//         return small+1;
//     }

// }
// int main(){
//     char arr[100];
//     cout<<"Enter string\n";
//     cin>>arr;
//     cout<<getLength(arr,100)<<endl;

    

//     return 0;
// }

//REMOVE all x
// #include<iostream>
// #include<cstring>
// using namespace std;
// // void removeX(char s[]){
// //     int l=strlen(s);
// //     if(s[0]=='x'){
// //         for(int i=0;i<l;i++){
// //             s[i]=s[i+1];
// //         }
// //         removeX(s);
// //     }
// //     else if (s[1] != '\0')
// //         removeX(s + 1);
// //     else
// //         return;
// // }
// void removeX(char s[]){
//     int l=strlen(s);
//     if(s[0]=='\0'){
//         return;
//     }
//     if(s[0]!='\0'){
//         removeX(s+1);
//     }
// }
// int main(){
//     char s[100];
//     cout<<"Enter the string\n";
//     cin>>s;
//     removeX(s);
//     for(int i=0;i<strlen(s);i++){
//         cout<<s[i];
//     }
//     cout<<endl;

    
    
//     return 0;
// }


//Merge Sort
// #include <iostream>
// using namespace std;
// void mergeTwoSorted(int arr[], int st, int mid, int e)
// {
//     int a[e-st+1];//creating a new array
//     int index1 = st;
//     int index2 = mid + 1;
//     int mainIndex = 0;

//     while (index1 <= mid && index2 <= e)
//     {
//         if (arr[index1] <= arr[index2])
//         {
//             a[mainIndex] = arr[index1];
//             index1++;
//         }
//         else
//         {
//             a[mainIndex] = arr[index2];
//             index2++;
//         }
//         mainIndex++;
//     }

//     while (index1 <= mid)//if 1st array if bigger than 2nd
//     {
//         a[mainIndex] = arr[index1];
//         index1++;
//         mainIndex++;
//     }

//     while (index2 <= e)
//     {
//         a[mainIndex] = arr[index2];
//         index2++;
//         mainIndex++;
//     }

//     mainIndex = 0;
//     for (int i = st; i <= e; i++)//for copying the elements back to main array
//     {
//         arr[i] = a[mainIndex];
//         mainIndex++;
//     }
    
// }

// void mergeSort(int arr[], int st, int e)
// {
//     if (st >= e)
//     {
//         return;
//     }
//     int mid = (st + e) / 2;
//     mergeSort(arr, st, mid);
//     mergeSort(arr, mid + 1, e);
//     mergeTwoSorted(arr, st, mid, e);
    
// }

// int main()
// {
//     int a[6] = {1, 0, 5, 8, 4, 1};
//     mergeSort(a, 0, 5);
//     for (int i = 0; i < 6; i++)
//     {
//         cout << a[i] << " ";
//     }

//         return 0;
// }


//QUICK SORT
// #include<iostream>
// #include<algorithm>
// using namespace std;
// int partition(int *a,int s,int e){
//     int count_smaller_Elements=0;
//     int Pivot=a[s];
//     for (int i = s + 1; i <= e; i++)
//     {
//         if (a[i] <= Pivot)
//         {
//             count_smaller_Elements++;
//         }
//     }

//     int PI=s+count_smaller_Elements;
//     swap(a[s], a[PI]);//don't place Pivot instead of a[s]
//     int i = s;
//     int j = e;
//     while (i <= PI && j >= PI)
//     {
//         if (a[i] < Pivot)
//         {
//             i++;
//         }
//         else if (a[j] > Pivot)
//         {
//             j--;
//         }
//         else
//         {
//             swap(a[i], a[j]);
//             i++;
//             j--;
//         }
//     }
//     return PI;
// }


// void QuickSort(int *a,int s,int e){
//     //base case,for 0 element or 1 element already sorted
//     if (s>= e)
//     {
//         return;
//     }
//     int PI=partition(a,s,e);
    
//     QuickSort(a,s,PI-1);
//     QuickSort(a,PI+1,e);
    
// }
// int main(){
//         int a[7] = {1, -1, 5,6, 9, 4, 3};
//         QuickSort(a, 0, 6);
//         for (int i = 0; i < 7; i++)
//         {
//             cout << a[i] << " ";
//         }

//     return 0;
// }


