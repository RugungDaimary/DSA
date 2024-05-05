#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
// Loot Houses
//using normal recursion
int maxLoot(int n,int* amount){
    if(n<=0){
        return 0;
    }
    int included=amount[0]+maxLoot(n-2,amount+2);
    int notIncluded=maxLoot(n-1,amount+1);
    return max(included,notIncluded);

}
//using memoization
int maxLoot_mem_helper(int n,int* amount,int* output){
    if(n<=0){
        return 0;
    }
    if(output[n]!=-1){
        return output[n];
    }
    int included=amount[0]+maxLoot(n-2,amount+2);
    int notIncluded=maxLoot(n-1,amount+1);
    output[n]= max(included,notIncluded);
    return output[n];
}
int maxLoot_mem(int n,int*amount){
    int*output=new int[n+1];
    for(int i=0;i<n+1;i++){
        output[i]=-1;
    }
    return maxLoot_mem_helper(n,amount,output);
}
//using DP
int maxLoot_DP(int n,int* amount){
    int *output=new int[n+1];
    output[0]=0;//max loot when no of house =0;
    output[1]=amount[0];//max loot when no of house=1;
    for (int i = 2; i < n+1; i++)
    {
        int included=output[i-2]+amount[i-1];
        int notIncluded=output[i-1];
        output[i]=max(included,notIncluded);
    }
    return output[n];//output[n] means max loot when no of hounse =n

}
//Longest Increasing Subsequence(DP)
int longestIncSub(int n,int* input){
    int *output=new int[n];
    output[0]=1;
    for(int i=1;i<n;i++){
        output[i]=1;
        for(int j=i-1;j>=0;j--){
            if(input[j]>=input[i]){
                continue;
            }
            int possibleAns=output[j]+1;
            if(possibleAns>output[i]){
                output[i]=possibleAns;
            }
        }
    }
    int best=0;
    for (int i = 0; i < n; i++)
    {
        if(best<output[i]){
            best=output[i];
        }
    }
    delete []output;
    return best;
}


//All possible ways
// int allPossibleWays(int a,int b){
//     int x=1;
//     for (int i = 1; i <=b; i++)
//     {  
//         x*=x;    
//     }
//     int ans=1+allPossibleWays(a-x);
    
// }

//Ways To Make Coin Change
// int totalWays(int n,int* denomations,int value){

// }


//Matrix chain multiplication(recursion)
int minMCM(int* a,int s,int e){
    if(s==e){
        return 0;
    }
    if( s==e-1){
        return 0;
    }
    int ans=INT_MAX;
    for(int k=s+1;k<=(e-1);k++){
        int temp=minMCM(a,s,k)+minMCM(a,k,e)+a[s]*a[k]*a[e];
        if(temp<ans){
            ans=temp;
        }
    }
    return ans;

}
//using memoization
int minMCMUtil(int* a, int s, int e, int** memo) {
    if (s == e) {
        return 0;
    }
    if (s == e - 1) {
        return 0;
    }
    if (memo[s][e] != -1) {
        return memo[s][e];
    }
    int ans = INT_MAX;
    for (int k = s + 1; k <= (e - 1); k++) {
        int temp = minMCMUtil(a, s, k, memo) + minMCMUtil(a, k, e, memo) + a[s] * a[k] * a[e];
        if (temp < ans) {
            ans = temp;
        }
    }
    memo[s][e] = ans;
    return ans;
}
int minMCM_mem(int* a,int s,int e ) {
    int n=e-s;
    int** memo = new int*[n + 1];
    for (int i = 0; i <= n; i++) {  
        memo[i] = new int[n + 1];
        for (int j = 0; j <= n; j++) {  
            memo[i][j] = -1;
        }
    }
    int result = minMCMUtil(a, 0, n, memo);
    for (int i = 0; i < n; i++) {
        delete[] memo[i];
    }
    delete[] memo;

    return result;
}



//Coin Tower
// void coinTower(int n,int x,int y){
    
// }

int main(){
    // int amount[] = { 3,3,3,3,3,3};
    // cout<<"Max loot : "<<maxLoot(6,amount)<<endl;
    // cout<<"Max loot : "<<maxLoot_mem(6,amount)<<endl;
    // cout<<"Max loot : "<<maxLoot_DP(6,amount)<<endl;
    // cout<<"Longest Inc Sub : "<<longestIncSub(6,amount)<<endl;
    int a[]={10,15,20,25};
    cout<<"min MCM : "<<minMCM_mem(a,0,3)<<endl;
    cout<<"min MCM : "<<minMCM(a,0,3)<<endl;

    return 0;
}