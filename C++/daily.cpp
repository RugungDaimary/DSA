#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>nums={1,3,6,8,9};
    int sum=accumulate(nums.begin()+2,nums.end(),0);
    cout<<sum<<endl;
    
    return 0;
}