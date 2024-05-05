//shortest path 
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<pair<int,int>>>adjList;
    void addEdge(int u,int v,int wt,int direction){
        //if direction=0 undirected
        adjList[u].push_back({v,wt});
        if(direction==0){
            adjList[v].push_back({u,wt});
        }
    }
    void print(){
        for(auto i:adjList){
            cout<<i.first<<" :-> ";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<"),";
            }
            cout<<endl;
        }


    }


    // For directed Graph and if all weights are equal 
    void shortestPath(int src, int dest)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();

            for (auto nbr : adjList[fNode])
            {
                if (!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                    parent[nbr.first] = fNode;
                }
            }
        }

        if (visited[dest])
        {
            vector<int> path;
            int node = dest;
            while (node != -1)
            {
                path.push_back(node);
                node = parent[node];
            }
            reverse(path.begin(), path.end());

            cout << "Shortest Path: ";
            for (auto i : path)
            {
                cout << i;
                if (i != dest)
                {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
        else
        {
            cout << "No path exists between " << src << " and " << dest << endl;
        }
    }

    //Topological Sort
    void TopologicalSort_DFS(int src,unordered_map<int,bool>&visited,stack<int>&st){
        
        visited[src]=true;
        for(auto neigh:adjList[src]){
            if(!visited[neigh.first])
                TopologicalSort_DFS(neigh.first, visited, st);
        }
        //while returning store the  node in stack
        st.push(src);

    }
    
    void shortestPath_DFS(int dest,stack<int>&topoOrder,int n){
        //distance vector
        vector<int>distance(n,INT_MAX);
        int src=topoOrder.top();
        topoOrder.pop();//source has been removed
        distance[src]=0;


        for(auto nbr:adjList[src]){
            if(distance[src]+nbr.second<distance[nbr.first]){
                distance[nbr.first]=distance[src]+nbr.second;
            }
        }

        while(!topoOrder.empty()){
            int topElement=topoOrder.top();
            topoOrder.pop();
            if(distance[topElement]!=INT_MAX){
                for(auto nbr:adjList[topElement]){
                    if (distance[topElement] + nbr.second < distance[nbr.first])
                    {
                        distance[nbr.first] = distance[topElement] + nbr.second;
                    }
                }
                
            }
        }
        cout<<"Printing: ";
        for(int i=0;i<n;i++){
            cout<<i<<" -> "<<distance[i]<<endl;
        }
    }

    
};
int main(){
    Graph g;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(2,1,2,1);

    g.addEdge(1,3,3,1);
    g.addEdge(2,3,5,1);
    g.addEdge(2,4,6,1);

    g.addEdge(4,3,1,1);
    // g.addEdge(6,3,1,1); 
    // g.print();
    int src=0;
    int dest=3;
    // g.shortestPath(src,dest);
    unordered_map<int,bool>visited;
    stack<int>topoOrder;
    g.TopologicalSort_DFS(src,visited,topoOrder);
    g.shortestPath_DFS(dest,topoOrder,5);

    
    
    
    return 0;
}