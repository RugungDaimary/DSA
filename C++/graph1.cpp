//implementation using Adjacency Matrix
#include<iostream>
using namespace std;
int main(){
    int n;//no of vertices
    int e;//no of edges
    cin>>n>>e;
    int** edges=new int[n];
    for (int i = 0; i < n; i++)
    {
        edges[i]=new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j]=0;
        }
        
    }
    

    
    
    return 0;
}