/*
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>>adjList;
    void addEdge(int u,int v,int direction){
        //direction=0->undirected
        //direction=1->directed

        //create an edge from u to v
        adjList[u].push_back(v);
        if(direction==0){
            // undirected
            // create an edge from v to u
            adjList[v].push_back(u);
        }
    }
    void printAdjacency(){
        for(auto node:adjList){
            cout<<node.first<<":->";
            for(auto neighbour:node.second){
                cout<<neighbour<<" , ";

            }
            cout<<endl;
        }
    }

};
int main(){

    cout<<"Graph\n";
    cout<<"Enter no of nodes\n";
    int n;
    cin>>n;
    vector<vector<int>>adj(n,vector<int>(n,0));
    cout<<"Enter no of edges\n";
    int e;
    cin>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        //edge created
        adj[u][v]=1;
    }
    //printing the adjacency matrix
    cout<<"Adjacency matrix is printed \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    

    




    Graph g;
    //undirected graph
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);
    // g.printAdjacency();


    //directed graph
    g.addEdge(1,4,1);
    g.addEdge(1,3,1);
    g.addEdge(4,2,1);
    g.addEdge(4,3,1);
    g.addEdge(2,3,1);
    g.printAdjacency();


    return 0;
}

*/


/*

//for weighted graph
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    public:
    unordered_map<T,list<pair<T,T>>>adjList;
    void addEdge(T u,T v,T weight,int direction){
        //direction=0->undirected
        //direction=1->directed

        //create an edge from u to v
        adjList[u].push_back({v,weight});
        if(direction==0){
            // undirected
            // create an edge from v to u
            adjList[v].push_back({u,weight});
        }
    }
    void printAdjacency(){
        for(auto node:adjList){
            cout<<node.first<<":->";
            for(auto neighbour:node.second){
                cout<<"("<<neighbour.first<<" "<<neighbour.second<<")"<<" , ";

            }
            cout<<endl;
        }
    }

};
int main(){
    
    // cout<<"Graph\n";
    // cout<<"Enter no of nodes\n";
    // int n;
    // cin>>n;
    // vector<vector<int>>adj(n,vector<int>(n,0));
    // cout<<"Enter no of edges\n";
    // int e;
    // cin>>e;
    // for(int i=0;i<e;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     //edge created
    //     adj[u][v]=1;
    // }
    // //printing the adjacency matrix
    // cout<<"Adjacency matrix is printed \n";
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    




    Graph<int> g;
    //undirected graph
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);
    // g.printAdjacency();


    //directed graph
    //a.addEdge(scrNode,destNode,weight,direction)
    g.addEdge(1,4,2,1);
    g.addEdge(1,3,3,1);
    g.addEdge(4,2,4,1);
    g.addEdge(4,3,5,1);
    g.addEdge(2,3,6,1);

    g.printAdjacency();

    cout<<endl;
    Graph<char>c;
    c.addEdge('a','b',2,1);
    c.addEdge('b','c',3,1);
    c.printAdjacency();


    return 0;
}
*/


//Implementation
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    public:
    unordered_map<T,list<T>>adj;
    void addEdge(T u,T v,int direction){
        
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void print(){
        for(auto node:adj){
            cout<<node.first<<" -> ";
            for(auto neighbour:node.second){
                cout<<neighbour<<", ";
            }
            cout<<endl;
        }
    }

    //Breadth First Search using Queue and Map
    
    void BFS(T src, unordered_map<T, bool>& visited) {
        queue<T> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            T fNode = q.front();
            q.pop();
            cout << fNode << ", ";

            for (auto neigh : adj[fNode]) {
                if (!visited[neigh]) {
                    q.push(neigh);
                    visited[neigh] = true; // Mark the neighbor as visited here
                }
            }
        }
    }
    //Depth First Search using recursion like level wise print
    void DFS(int src,unordered_map<T,bool>&visited){
        cout<<src<<", ";
        visited[src]=true;
        for(auto neigh:adj[src]){
            if(!visited[neigh])
                DFS(neigh,visited);
        }
    }

    //cyclic check using BFS for undirected
    bool checkCyclic_BFS(int src, unordered_map<int, bool> &visited)
    {
        queue<int>q;
        unordered_map<int,int>parent;
        q.push(src);
        visited[src] = true;
        parent[src]=-1;
        while (!q.empty())
        {
            int fNode=q.front();
            q.pop();
            for(auto neigh:adj[fNode]){
                if(!visited[neigh]){
                    q.push(neigh);
                    visited[neigh]=true;
                    parent[neigh]=fNode;
                }else{
                    //already visited
                    if(visited[neigh]&& neigh!=parent[fNode]){
                        //cycle present
                        return true;
                    }
                   
                }
            }         
        }
        return false;
    }
    // cyclic check using DFS for undirected

    bool checkCyclic_DFS(int src,unordered_map<int,bool>&visited,int parent){
        visited[src]=true;
        for(auto neigh:adj[src]){
            if(!visited[neigh]){
                bool aageKaAns=checkCyclic_DFS(neigh,visited,src);
                if(aageKaAns==true){
                    return true;
                }
            }
            if(visited[neigh]&& neigh!=parent){
                //cycle present
                return true;
            }
        }
        return false;
    }
};
int main(){
    Graph<int>g;
    // int n=8;//no of nodes
    //cycle not present
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(1,3,0); 
    // g.addEdge(3,5,0);
    // g.addEdge(3,7,0);
    // g.addEdge(7,4,0);
    // g.addEdge(7,6,0);
    // g.print();

    //cycle present
    int n=5;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(4, 1, 0);

    cout<<"BFS : ";
    // g.BFS(0);

    // for disconnected graph,run a loop for all nodes
    unordered_map<int, bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.BFS(i, visited);
        }
    }
    cout<<endl;
    unordered_map<int, bool> visited2;
    cout<<"DFS : ";
    for(int i=0;i<n;i++){
        if(!visited2[i]){
            g.DFS(i, visited2);
        }
    }


    //checking cyclic using BFS
    unordered_map<int,bool>visited3;
    bool ansBFS=false;
    for(int i=0;i<n;i++){
        if (!visited3[i])
        {
            ansBFS = g.checkCyclic_BFS(0, visited3);
            if (ansBFS == true)
            {
                break;
            }
        }
    }
    cout<<endl;
    if(ansBFS){
        cout<<"Cyclic\n";
    }else{
        cout<<"Not cyclic\n";
    }

    //checking cyclic using DFS
    unordered_map<int,bool>visited4;
    bool ansDFS=false;
    for(int i=0;i<n;i++){
        if(!visited4[i]){
            ansDFS = g.checkCyclic_DFS(0, visited4, -1);
            if (ansDFS == true)
            {
                break;
            }
        }
    }
    cout<<endl;
    if (ansDFS)
    {
        cout<<"Cyclic \n";
    }
    else
    {
        cout<<"Not cyclic\n";
    }

    return 0;
}