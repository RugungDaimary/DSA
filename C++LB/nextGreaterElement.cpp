#include<bits/stdc++.h>
using namespace std;
vector<int>nextGreaterToRight(vector<int>&nums){
    int n=nums.size();
    stack<int>st;
    vector<int>next(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty()&& nums[i]>nums[st.top()]){
            int kid=st.top();
            st.pop();
            next[kid]=nums[i];

        }
        st.push(i);
    }
    return next;

}
vector<int>nextGreaterToleft(vector<int>&nums){
    int n=nums.size();
    stack<int>st;
    vector<int>next(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&& nums[i]>nums[st.top()]){
            int kid=st.top();
            st.pop();
            next[kid]=nums[i];

        }
        st.push(i);
    }
    return next;

}
vector<int>nextSmallerToRight(vector<int>nums){
    int n=nums.size();
    stack<int>st;
    vector<int>index(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty()&& nums[i]<nums[st.top()]){
            int kid=st.top();
            st.pop();
            index[kid]=nums[i];
        }
        st.push(i);
    }
    return index;
}
vector<int>nextSmallerToLeft(vector<int>nums){
    int n=nums.size();
    stack<int>st;
    vector<int>index(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&& nums[i]<nums[st.top()]){
            int kid=st.top();
            st.pop();
            index[kid]=nums[i];
        }
        st.push(i);
    }
    return index;
}

int main(){
    
    return 0;
}