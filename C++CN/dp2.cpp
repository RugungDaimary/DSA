#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
//Min Cost Path
//using recusrion
int minCostPath_helper(int** input,int m,int n,int i,int j){
    //base case
    if(i==m-1 && j==n-1){
        return input[i][j];
    }
    if (i>=m || j>=n)
    {
        return INT_MAX;
    }
    int a = minCostPath_helper(input,m,n,i,j+1);
    int b = minCostPath_helper(input,m,n,i+1,j+1);
    int c = minCostPath_helper(input,m,n,i+1,j);
    int output=min(a,min(b,c))+input[i][j];
    return output;
}
int minCostPath(int** input,int m,int n){
    return minCostPath_helper(input,m,n,0,0);   
}
//using memoization
int minCostPath_Mem_helper(int **input, int m, int n, int i, int j,int ** output)
{
    // base case
    if (i == m - 1 && j == n - 1)
    {
        return input[i][j];
    }
    if (i >= m || j >= n)
    {
        return INT_MAX;
    }
    //check is output already exists
    if(output[i][j]!=-1){
        return output[i][j];
    }
    int a = minCostPath_Mem_helper(input, m, n, i, j + 1,output);
    int b = minCostPath_Mem_helper(input, m, n, i + 1, j + 1,output);
    int c = minCostPath_Mem_helper(input, m, n, i + 1, j,output);
    int x = min(a, min(b, c)) + input[i][j];
    //save output for future use
    output[i][j]=x;
    return x;
}
int minCostPath_Mem(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            output[i][j]=-1;
        }
    }
    return minCostPath_Mem_helper(input, m, n, 0, 0,output);
}
//using DP
int minCostPath_DP(int** input,int m,int n){
    int **output=new int*[m];
    for(int i=0;i<n;i++){
        output[i]=new int[n];
    }
    //fill the last cell ie. destination
    output[m-1][n-1]=input[m-1][n-1];
    //fill the last row(right to left)
    for (int j = n-2;j>=0 ; j--)
    {
        output[m-1][j]=output[m-1][j+1]+input[m-1][j];
    }
    //fill last column (bottom to top)
    for (int i = m-2; i >=0; i--)
    {
        output[i][n-1]=output[i+1][n-1]+input[i][n-1];
    }
    //fill remaining cells
    for (int i = m-2; i >=0; i--)
    {
        for (int j = n-2; j>=0; j--)
        {
            output[i][j]=min(output[i][j+1],min(output[i+1][j+1],output[i+1][j]))+input[i][j];
        }
        
    }
    return output[0][0];

}
//LCS
//using recursion
int LCS(string s,string t){
    //base case
    if(s.size()==0|| t.size()==0){
        return 0;
    }
    if(s[0]==t[0]){
        return 1+LCS(s.substr(1),t.substr(1));
    }else{
        int a = LCS(s.substr(1),t);
        int b = LCS(s,t.substr(1));
        int c = LCS(s.substr(1),t.substr(1));
        return max(a,max(b,c));
    }
}
//using memoization
int LCS_mem_helper(string s,string t,int ** output){
    int m = s.size();
    int n = t.size();
    //base case
    if(m==0||n==0){
        return 0;
    }
    //check if ouput already exists
    if(output[m][n]!=-1){
        return output[m][n];
    }
    int ans;
    if(s[0]==t[0]){
        ans=1+LCS_mem_helper(s.substr(1),t.substr(1),output);

    }else{
        int a=LCS_mem_helper(s.substr(1),t,output);
        int b=LCS_mem_helper(s,t.substr(1),output);
        int c=LCS_mem_helper(s.substr(1),t.substr(1),output);
        ans=max(a,max(b,c));
    }
    output[m][n]=ans;
    return ans;
}
int LCS_mem(string s,string t){
    int m=s.size();
    int n=t.size();
    int** output=new int*[m+1];
    for (int i = 0; i < m+1; i++)
    {
        output[i]=new int[n+1];
        for (int j = 0; j < n+1; j++)
        {
            output[i][j]=-1;
        }
        
    }
    return LCS_mem_helper(s,t,output);
}
//using DP
int LCS_dp(string s,string t){
    int m=s.size();
    int n=t.size();
    int** output=new int*[m+1];
    for (int i = 0; i < m+1; i++)
    {
        output[i]=new int[n+1];
    }

    output[0][0] = 0;
    // filling first column
    for (int i = 1; i < m + 1; i++)
    {
        output[i][0] = 0;
    }
    // filling first row
    for (int j = 1; j < n + 1; j++)
    {
        output[0][j] = 0;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            // check if first character matches
            if (s[s.size() - i] == t[t.size() - j])
            {
                output[i][j] = 1 + output[i - 1][j - 1];
            }
            else
            {
                int a = output[i][j - 1];
                int b = output[i - 1][j];
                int c = output[i - 1][j - 1];
                output[i][j] = max(a, max(b, c));
            }
        }
    }
    return output[m][n];
}

//edit distance
//using recursion
int minDistance(string s,string t){
    int m=s.size();
    int n=t.size();
    if(m==0 && n==0){
        return 0;
    }
    if(m==0 && n!=0){
        return n;
    }
    if(n==0 && m!=0){
        return m;
    }
    if(s[0]==t[0]){
        return minDistance(s.substr(1),t.substr(1));
    }else{
        int inserted=minDistance(s.substr(1),t);
        int deleted=minDistance(s,t.substr(1));
        int replaced=minDistance(s.substr(1),t.substr(1));
        return 1+min(inserted,min(deleted,replaced));
    }
}
//using memoization
int minDistance_mem_helper(string word1, string word2, int **output)
{
    int m = word1.size();
    int n = word2.size();
    

    if (m == 0 || n == 0)
    {
        return max(m,n);
    }
    // or below  cases
    //  if (m == 0 && n == 0)
    //  {
    //      return 0;
    //  }
    //  if (m == 0 && n != 0)
    //  {
    //      return n;
    //  }
    //  if (n == 0 && m != 0)
    //  {
    //      return m;
    //  }
    if (output[m][n] != -1)
    {
        return output[m][n];
    }
    int ans;
    if (word1[0] == word2[0])
    {
        ans = minDistance_mem_helper(word1.substr(1), word2.substr(1), output);
    }
    else
    {
        int inserted = 1 + minDistance_mem_helper(word1.substr(1), word2, output);
        int deleted = 1 + minDistance_mem_helper(word1, word2.substr(1), output);
        int replaced = 1 + minDistance_mem_helper(word1.substr(1), word2.substr(1), output);
        ans = min(inserted, min(deleted, replaced));
    }
    output[m][n] = ans;
    return output[m][n];
}
int minDistance_mem(string word1, string word2)
{
    int m = word1.size();
    int n = word2.size();
    int **output = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            output[i][j] = -1;
        }
    }
    return minDistance_mem_helper(word1, word2, output);
}
int minDistance_DP(string s,string t){
    int m=s.size();
    int n=s.size();
    int ** output=new int*[m+1];
    for(int i=0;i<m+1;i++){
        output[i]=new int[n+1];   
    }
    output[0][0]=0;
    //filling first row
    for (int j = 1; j < n+1; j++)
    {
       output[0][j]=j;
    }
    //filling first column
    for (int i= 1; i< m+1; i++)
    {
       output[i][0]=i;
    }
    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if(s[m-i]==t[n-j]){
                output[i][j]=output[i-1][j-1];
            }else{
                output[i][j]=min(output[i-1][j],min(output[i][j-1],output[i-1][j-1]))+1;
            }
            
        }  
    }
    return output[m][n];
}

// 0/1 knapsack using recursion O(2^n)
int maxProfit(int n,int* weight,int* value,int maxWeight){
    if(n==0|| maxWeight==0){
        return 0;
    }
    if(weight[0]>maxWeight){
        return maxProfit(n-1,weight+1,value+1,maxWeight);
    }
    int included =value[0]+maxProfit(n-1,weight+1,value+1,maxWeight-weight[0]);
    int notIncluded =maxProfit(n-1,weight+1,value+1,maxWeight);
    int ans=max(included,notIncluded);
    return ans;
}
//using memoization
int knapsack_helper(int n,int* weight,int* value,int maxWeight,int* output){
    if(n==0|| maxWeight==0){
        return 0;
    }
    if(output[n]!=-1){
        return output[n];
    }
    if(weight[0]>maxWeight){
        return knapsack_helper(n-1,weight+1,value+1,maxWeight,output);
    }
    int included =value[0]+knapsack_helper(n-1,weight+1,value+1,maxWeight-weight[0],output);
    int notIncluded =knapsack_helper(n-1,weight+1,value+1,maxWeight,output);
    int ans=max(included,notIncluded);
    output[n]=ans;
    return ans;

}
int knapsack(int n,int* weight,int* value,int maxWeight){
    int*output=new int[n+1];
    for(int i=0;i<n+1;i++){
        output[i]=-1;
    }
    return knapsack_helper(n,weight,value,maxWeight,output);

}
//using DP
// int knapsack_DP(int n,int* weight,int* value,int maxWeight){
//     int* output=new int[n+1];
//     output[0]=0;
    
// }

int main(){
    // int m,n;
    // cin>>m>>n;
    // int **input=new int*[m];
    // for (int i = 0; i < m; i++)
    // {
    //     input[i]=new int[n];
    //     for (int j = 0; j < n; j++)
    //     {
    //         cin>>input[i][j];
    //     }  
    // }
    // cout << "Min Cost Path : " << minCostPath_Mem(input, m, n) << endl;
    // cout << "Min Cost Path : " << minCostPath(input, m, n) << endl;
    // cout << "Min Cost Path : " << minCostPath_DP(input, m, n) << endl;
    

    string s="intention";
    string t = "execution";
    cout<<"LCS : "<<LCS(s,t)<<endl; 
    cout<<"LCS_mem : "<<LCS_mem(s,t)<<endl; 
    cout<<"LCS_dp : "<<LCS_dp(s,t)<<endl;
    cout<<"Min Distance "<<minDistance_mem(s,t)<<endl; 
    cout<<"Min Distance "<<minDistance_DP(s,t)<<endl; 
    int weight[]={1,2,4,5};
    int value[]={5,4,8,6};
    cout<<maxProfit(4,weight,value,5)<<endl;
    cout<<knapsack(4,weight,value,5)<<endl;

    return 0;
}