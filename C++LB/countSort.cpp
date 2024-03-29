#include<bits/stdc++.h>
using namespace std;
//TC=>O(n+k)
//SC=>O(k)
//Non comparison algorithm
//this algorithm is not inPlace algorithm(uses extra space of k size,where k is the maximum element)
void countSort(vector<int>&arr){
    int n=arr.size();
    //intially we make count array which will store the frequency of all elements
    int maxi=*max_element(arr.begin(),arr.end());
    vector<int>count(maxi+1,0);//means all numbers will be in range up to max element only
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=0;i<count.size();i++){
        cout<<count[i]<<" ";
    }
    cout<<endl;
    arr.resize(0);
    // we will change in original array only
    for(int i=0;i<count.size();i++){
        if(count[i]>0){
            for(int j=0;j<count[i];j++){
                arr.push_back(i);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
int main(){
    vector<int>arr{9,9,9,9,9,9,9};
    countSort(arr);
    
    return 0;
}