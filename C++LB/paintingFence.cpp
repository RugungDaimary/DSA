#include<bits/stdc++.h>
using namespace std;
int solveUsingRecursion(int n,int k){
    if(n==1){
        return k;//k is the no of colours
    }
    if(n==2){
        return k+(k*(k-1));//k*(k-1) is the permutation of k colours in two place
    }
    int ans=(solveUsingRecursion(n-1,k)+solveUsingRecursion(n-2,k))*(k-1);
    return ans;

}
int solveUsingMem(int n,int k,vector<int>&dp){
    if(n==1){
        return k;//k is the no of colours
    }
    if(n==2){
        return k+(k*(k-1));//k*(k-1) is the permutation of k colours in two place
    }
    if(dp[n-1]!=-1){
        return dp[n-1];
    }
    dp[n-1]=(solveUsingMem(n-1,k,dp)+solveUsingMem(n-2,k,dp))*(k-1);
    return dp[n-1];

}
int solveUsingTabulation(int n,int k){
    vector<int>dp(n+1,0);
    dp[1]=k;
    dp[2]=k+k*(k-1);
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])*(k-1);
    }
    return dp[n];
}

int spaceOptimization(int n,int k){
    int prev2=k;
    int prev1=k+k*(k-1);
    int curr;
    for(int i=3;i<=n;i++){
        curr=(prev2+prev1)*(k-1);
        prev2=prev1;
        prev1=curr;
    }
    return curr;

}
int main(){
    int n=4;
    int k=3;
    cout<<solveUsingRecursion(n,k)<<endl;
    vector<int>dp(n,-1);
    cout<<solveUsingMem(n,k,dp)<<endl;
    cout<<solveUsingTabulation(n,k)<<endl;
    cout<<spaceOptimization(n,k)<<endl;

    
    return 0;
}