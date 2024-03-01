#include<bits/stdc++.h>
using namespace std;
int getMinValue(vector<int>&key,vector<bool>&mst){
    int index=-1;//represents node having min value
    int temp=INT_MAX;
    for(int i=0;i<key.size();i++){
        if(key[i]<temp && mst[i]==false){
            temp=key[i];
            index=i;
        }
    }
    return index;

}
//finding minimum spanning tree
int primAlgo(int n,vector<vector<int>>adj[]){//v is the no of nodes
    vector<int>key(n,INT_MAX);
    key[0]=0;
    vector<bool>mst(n,false);//to keep track all which nodes are added into mst
    vector<int>parent(n,-1);
    while (true)
    {
        //step 1
        int u=getMinValue(key,mst);
        if(u==-1) break;
        //step 2
        mst[u]=true;
        //step 3: process all adjacent nodes to u
        for(auto nbr:adj[u]){
            int v=nbr[0];
            int wt=nbr[1];
            if(mst[v]==false && wt<key[v]){
                key[v]=wt;
                parent[v]=u;
            }
        }

    }
    int sum=0;
    //now traverse in parent vector
    for(int u=0;u<parent.size();u++){
        if(parent[u]==-1) continue;
        for(auto edges:adj[u]){
            int v=edges[0];
            int wt=edges[1];
            if(v==parent[u]){
                sum+=wt;
            }
        }
    }
    return sum;
}
int main(){
    
    return 0;
}