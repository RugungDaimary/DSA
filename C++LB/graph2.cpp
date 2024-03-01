//Implementation
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    public:
    unordered_map<T,list<T>>adjList;
    void addEdge(T u,T v,int direction){
        
        adjList[u].push_back(v);
        if(direction==0){
            adjList[v].push_back(u);
        }
    }
    void print(){
        for(auto node:adjList){
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

            for (auto neigh : adjList[fNode]) {
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
        for(auto neigh:adjList[src]){
            if(!visited[neigh])
                DFS(neigh,visited);
        }
    }
    //cyclic detection for directed graph
    bool checkCyclic_DFS(int src,unordered_map<int,bool>&visited,unordered_map<int,bool>&DFSvisited){
        visited[src]=true;
        DFSvisited[src] = true;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                bool aageKaAns=checkCyclic_DFS(nbr,visited,DFSvisited);
                if(aageKaAns){
                    return true;
                }
            }
            if(visited[nbr] && DFSvisited[nbr]){
                //cyclic found
                return true;
            }

        }
        //backtracking
        DFSvisited[src] = false;
        return false;
    }

    //Topological Sort
    void TopologicalSortDFS(int src,unordered_map<int,bool>&visited,stack<int>&st){
        
        visited[src]=true;
        for(auto neigh:adjList[src]){
            if(!visited[neigh])
                TopologicalSortDFS(neigh, visited, st);
        }
        //while returning store the  node in stack
        st.push(src);

    }
    //for both connected and disconnected graph
    void TopoSort_BFS(int n,vector<int>&ans){
        queue<int>q;
        unordered_map<int,int>indegree;
        //indegree calculate
        for(auto i:adjList){
            int src=i.first;
            for(auto nbr:i.second){
                indegree[nbr]++;
            }
        }
        //put all nodes in queue whose indegree is 0 ,imp for disconnected
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //bfs logic
        while(!q.empty()){
            int fNode=q.front(); 
            q.pop();
            ans.push_back(fNode);
            for(auto nbr:adjList[fNode]){
                indegree[nbr]--;
                //check for zero again
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        
    }

};
int main(){
    // Graph<int>g;
    // int n=8;//no of nodes
    // // cycle not present
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(1,3,1); 
    // g.addEdge(3,5,1);
    // g.addEdge(3,7,1);
    // g.addEdge(7,4,1);
    // g.addEdge(7,6,1);
    // g.print();

    //cycle present
    // int n=5;
    // g.addEdge(0, 1, 1);
    // g.addEdge(1, 2, 1);
    // g.addEdge(1, 3, 1);
    // g.addEdge(3, 4, 1);
    // g.addEdge(4, 1, 1);

    
    // for disconnected graph,run a loop for all nodes
    // cout << "BFS : ";
    // unordered_map<int, bool> visited;
    // for(int i=0;i<n;i++){
    //     if(!visited[i]){
    //         g.BFS(i, visited);
    //     }
    // }
    // cout<<endl;
    // unordered_map<int, bool> visited2;
    // cout<<"DFS : ";
    // for(int i=0;i<n;i++){
    //     if(!visited2[i]){
    //         g.DFS(i, visited2);
    //     }
    // }
    // cout<<endl;

    // bool dfsAns=false;
    // unordered_map<int,bool>visitedDFS;
    // unordered_map<int,bool>DFSvisited;
    // for(int i=0;i<n;i++){
    //     if (!visitedDFS[i]){
    //         dfsAns=g.checkCyclic_DFS(i,visitedDFS,DFSvisited);
    //     }
    //     if(dfsAns==true){
    //         break;
    //     }
    // }
    // if(dfsAns){
    //     cout<<"Cyclic\n";
    // }else{
    //     cout<<"Not Cyclic\n";
    // }




    //Topological Sort
    Graph<int>g;
    int n=8;//no of nodes
    // cycle not present
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1); 
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);
    unordered_map<int,bool>visited;
    stack<int>st;
    
    // for(int i=0;i<n;i++){
    //     if(!visited[i]){
    //         g.TopologicalSortDFS(i, visited, st);
    //     }
    // }
    // cout << "Topological Sort : ";
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }


    //

    vector<int>ans;
    g.TopoSort_BFS(n,ans);
    cout<<"Printing Topological Sort using BFS : \n";
    for(auto i:ans){
        cout<<i<<" , ";
    }cout<<endl;








    return 0;
}