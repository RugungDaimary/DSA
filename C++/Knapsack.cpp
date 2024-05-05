#include<bits/stdc++.h>
using namespace std;
// int solveUsingRecursion(vector<int> &weights, vector<int> &values, int capacity, int index)
// {
//     if (index == weights.size() - 1)
//     {
//         if (weights[index] <= capacity)
//         {
//             return values[index];
//         }
//         else
//         {
//             return 0;
//         }
//     }
//     int include = 0;
//     if (weights[index] <= capacity)
//     {
//         include = values[index] + solveUsingRecursion(weights, values, capacity - values[index], index - 1);
//     }
//     int exclude = 0 + solveUsingRecursion(weights, values, capacity, index - 1);
//     return max(include, exclude);
// }


// index=index of last element
// traversing from right to left'
int solveUsingRecursion(vector<int>&weights,vector<int>&values,int capacity,int index){

    
    if(index==0){//only 1 element
        if(weights[0]<=capacity){
            return values[0];
        }else{
            return 0;
        }

    }
    int include=0;
    if(weights[index]<=capacity){
        include=values[index]+solveUsingRecursion(weights,values,capacity-values[index],index-1);

    }
    int exclude=0+solveUsingRecursion(weights,values,capacity,index-1);
    return max(include,exclude);

}
int solveUsingMem(vector<int>&weights,vector<int>&values,int capacity,int index,vector<vector<int>>&dp){
    // if(index==weights.size()-1){
    //     if(capacity>=weights[index]){
    //         return values[index];
    //     }else{
    //         return 0;
    //     }
    // }
    if (index == 0)
    { // only 1 element
        if (weights[0] <= capacity)
        {
            return values[0];
        }
        else
        {
            return 0;
        }
    }
    if(dp[index][capacity]!=-1){
        return dp[index][capacity];
    }
    int include = 0;
    if (weights[index] <= capacity)
    {
        include = values[index] + solveUsingMem(weights, values, capacity - values[index], index - 1,dp);
    }
    int exclude = 0 + solveUsingMem(weights, values, capacity, index - 1,dp);
    return dp[index][capacity]=max(include, exclude);
}
int solveUsingTabulation(vector<int> &weights, vector<int> &values, int capacity, int index)
{
    int n=weights.size();
    vector<vector<int>>dp(n,vector<int>(capacity+1,0));
    for(int w=weights[0];w<=capacity;w++){
        if(weights[0]<=capacity){
            dp[0][w]=values[0];
        }else{
            dp[0][w]=0;
        }
    }
    for(int index=1;index<n;index++){
        for(int wt=0;wt<=capacity;wt++){
            //include exclude
            int included=0;
            if(weights[index]<=wt){
                included=values[index]+dp[index-1][wt-weights[index]];
            }
            int excluded=dp[index-1][wt];
            dp[index][wt]=max(included,excluded);
        }
        
    }
    return dp[n-1][capacity];


}

//space Optimization
int spaceOptm(vector<int> &weights, vector<int> &values, int capacity, int index){
    int n=weights.size();
    vector<int>prev(capacity+1,0);
    vector<int>curr(capacity+1,0);
    for(int w=weights[0];w<=capacity;w++){
        if(weights[0]<=capacity){
            curr[w]=values[0];
        }else{
            curr[w]=0;
        }
    }
    for(int index=1;index<n;index++){
        for(int wt=capacity;wt>=0;wt--){
            //include exclude
            int include=0;
            if(weights[index]<=wt){
                include=values[index]+curr[wt-weights[index]];

            }
            int exclude=0+curr[wt];
            curr[wt]=max(include,exclude);

        }

    }
    return curr[capacity];
}
int main(){
    vector<int>weights={4,5,1};
    vector<int>values={1,2,3};
    int capacity=4;
    int n=3;
    cout<<solveUsingRecursion(weights,values,capacity,n-1)<<endl;

    vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
    cout<<solveUsingMem(weights,values,capacity,n-1,dp)<<endl;
    cout<<solveUsingTabulation(weights,values,capacity,n-1)<<endl;
    cout<<spaceOptm(weights,values,capacity,n-1)<<endl;

    return 0;
}






