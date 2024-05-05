//This is also call DSU
#include<bits/stdc++.h>
using namespace std;
static bool myCmp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
int findParent(vector<int>&parent,int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=findParent(parent,parent[node]);//path compression

}
void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
    u=findParent(parent,u);
    v=findParent(parent,v);
    if(rank[u]<rank[v]){
        parent[u]=v;
        rank[v]++;
    }else{
        parent[v] = u;
        rank[u]++;
    }
}
void getMeEdge(int n,vector<vector<int>>adj[],vector<vector<int>>&edges){
    for(int u=0;u<n;u++){
        for(auto& edge:adj[u]){
            int v=edge[0];
            int wt=edge[1];
            edges.push_back({u,v,wt});
        }
    }

}
int krushkalAlgo(int n,vector<vector<int>>adj[]){
    vector<int>parent(n);
    vector<int>rank(n,0);
    //initially all node are parent of itself
    for(int u=0;u<n;++u){
        parent[u]=u;
    }
    vector<vector<int>>edges;
    getMeEdge(n,adj,edges);
    sort(edges.begin(),edges.end(),myCmp);
    int ans=0;
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        int wt=edge[2];
        u=findParent(parent,u);
        v=findParent(parent,v);
        if(u!=v){
            //do union(merge them )
            unionSet(u,v,parent,rank);
            ans+=wt;
        }
    }
    return  ans;
}
int main(){
    int n;
    cout<<n<<endl;
    
    return 0;
}
