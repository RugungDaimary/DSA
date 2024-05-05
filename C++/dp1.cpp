#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
// fibonacci using memoization(top down)
int fibo_helper(int n,int * ans){
    if(n<=1){
        return n;
    }
    //check is answer already exists or not
    if(ans[n]!=-1){
        return ans[n];
    }
    int a=fibo_helper(n-1,ans);
    int b=fibo_helper(n-2,ans);

    //save output for future use
    ans[n]=a+b;

    //return the final output
    return ans[n];

}
int fibo(int n){
    int * ans=new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        ans[i]=-1;
    }
    
    return fibo_helper(n,ans);

}
//using iteration(DP) ->bottom up
int fib(int n){
    int *ans=new int[n+1];
    ans[0]=0;
    ans[1]=1;
    for (int i = 2; i < n+1; i++)
    {
        ans[i]=ans[i-1]+ans[i-2];
    }
    return ans[n];
}



//count min steps using recursion
int minSteps(int n){
    //base case
    if(n<=1){
        return 0;
    }
    int x = minSteps(n - 1);
    int y=INT_MAX;
    int z=INT_MAX;
    if (n % 3 == 0)
    {
        y = minSteps(n / 3);
    }
    if (n % 2 == 0)
    {
        z = minSteps(n / 2);
    }
   
    return min(x,min(y,z))+1;
}
//using memoization
int minimumSteps_helper(int n,int *ans){
    if(n<=1){
        return 0;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    // ans[i]= minsteps required to reach from i to 1
    int x = minimumSteps_helper(n - 1,ans);
    int y = INT_MAX;
    int z = INT_MAX;
    if (n % 3 == 0)
    {
        y = minimumSteps_helper(n / 3,ans);
    }
    if (n % 2 == 0)
    {
        z = minimumSteps_helper(n / 2,ans);
    }

    int temp=min(x, min(y, z)) + 1;
    ans[n]=temp;
    return temp;
}
int minimumSteps(int n){
    int * ans=new int[n+1];
    for(int i=0;i<n+1;i++){
        ans[i]=-1;
    }
    return minimumSteps_helper(n,ans);
}
//using DP
int minSTEPS(int n){
    int * ans=new int[n+1];
    ans[1]=0;
    for (int i = 1; i < n+1; i++)
    {

        int subtract1 = ans[i - 1];
        int divideBy2 =INT_MAX;
        int divideBy3 = INT_MAX;
        if(i % 2 == 0){
            divideBy2 = ans[i / 2];
        }       
        if(i % 3 == 0) {
            divideBy3=ans[i / 3];
        }
        ans[i] = 1 + min(subtract1, min(divideBy2, divideBy3));
    }
    int output=ans[n];
    return output;

}

// Staircase using normal recursion O(3^n)
int staircase(int n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    int x=staircase(n-1);
    int y=staircase(n-2);
    int z=staircase(n-3);
    return x+y+z;
}
//using memoization
int stair_helper(int n,int *ans){
    if(n<0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    int x = stair_helper(n - 1,ans);
    int y = stair_helper(n - 2,ans);
    int z = stair_helper(n - 3,ans);
    int result=x+y+z;
    ans[n]=result;
    return result;
}
int stair(int n){
    int *ans=new int[n+1];
    for (int i = 0; i < n+1; i++)
    {
        ans[i]=-1;
    }
    
    return stair_helper(n,ans);
}
//using dp
int STAIR(int n){
    if(n==0||n==1){
        return 1;
    }
    int * ans=new int[n+1];
    ans[0]=1;
    ans[1]=1;
    ans[2]=2;
    for(int i=3;i<n+1;i++){
        ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
    }
    return ans[n];
}


// Minimum Count
//using recursion
int minCount(int n){
    if(n==0){
        return 0;
    }
    int ans=INT_MAX;
    for (int i = 1; i <=sqrt(n); i++)
    {
        int x = minCount(n-i*i);
        if(x<ans){
            ans=x;
        }
    }
    return ans+1;
}
//using Memoization
int minimumCount_helper(int n,int * ans){
    if(n==0){
        return 0;
    }
    if(ans[n]!=-1){
        return ans[n];
    }
    int x=INT_MAX;
    for (int i = 1; i <=sqrt(n); i++)
    {
        int y=minimumCount_helper(n-i*i,ans);
        if(y<x){
            x=y;
        }
    }
    ans[n]=x+1;
    return ans[n];
    
}
int minimumCount(int n){
    int * ans=new int[n+1];
    for(int i=0;i<n+1;i++){
        ans[i]=-1;
    }
    return minimumCount_helper(n,ans);
}
//using DP
// int MinCount(int n){
//     int* ans=new int[n+1];
//     ans[0]=0;
//     for (int i = 1; i <= sqrt(n); i++)
//     {   

//         ans[i]=min(ans[n-i*i],);
//     }
//     return ans[n];   
// }


//No of balanced binary tree
int numBalanced(int h){
    if(h<=1){
        return 1;
    }
    int mod=(int)(pow(10,9))+7;
    int x = numBalanced(h - 1) ;
    int y = numBalanced(h - 2);
    int temp1=(int)(((long)(x)*x)%mod);
    int temp2=(int)((2*(long)(x)*y)%mod);
    int ans=temp1+temp2;
    
    return ans;
}
//using memoization
int numBalancedBinary_helper(int h, int *ans)
{
    if(h<=1){
        return 1;
    }
    if(ans[h]!=-1){
        return ans[h];
    }
    int mod = (int)(pow(10, 9)) + 7;
    int x = numBalancedBinary_helper(h - 1,ans);
    int y = numBalancedBinary_helper(h - 2,ans);
    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);
    int output = temp1 + temp2;
    ans[h]=output;
    return ans[h];
}
int numBalancedBinary(int h){
    int *ans=new int[h+1];
    for (int i = 0; i < h+1; i++)
    {
        ans[i]=-1;
    }
    return numBalancedBinary_helper(h,ans);
    
}
//using DP(some changes to be done for overflow condition)
int numBalancedBTrees(int h){
    int *ans=new int[h+1];
    ans[0]=1;
    ans[1]=1;
    int mod = (int)(pow(10, 9)) + 7;
    for (int i = 2; i < h+1; i++)
    {
        ans[i]=ans[i-1]* ans[i-1]+2*ans[i-2]* ans[i-1];
    
    }
    return ans[h];
}

int main(){
    // cout<<fib(7)<<endl;

    // cout << "Min steps : " << minSTEPS(10) << endl;
    // cout << "Min steps : " << minimumSteps(10) << endl;

    // cout<<staircase(7)<<endl;
    // cout<<stair(7)<<endl;
    // cout<<STAIR(7)<<endl;


    // cout<<minCount(15)<<endl;
    // cout<<minimumCount(15)<<endl;
    // cout << MinCount(10) << endl;

    cout<<numBalanced(8)<<endl;
    cout << numBalancedBinary(8) << endl;
    cout << numBalancedBTrees(8) << endl;

    return 0;
}