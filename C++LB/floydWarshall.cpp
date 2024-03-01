#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;
    void addEdge(int u, int v, int wt, int direction)
    {
        // if direction=0 undirected
        adjList[u].push_back({v, wt});
        if (direction == 0)
        {
            adjList[v].push_back({u, wt});
        }
    }
    void print()
    {
        for (auto i : adjList)
        {
            cout << i.first << " :-> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << "),";
            }
            cout << endl;
        }
    }
    void floydWarshall(int n){
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        //mark all diagonals 0
        for(int i=0;i<n;i++){
           dist[i][i]=0;
        }
        //graph ke according dist insert kardiya hai
        for(auto t:adjList){
            for(auto nbr:t.second){
                int u=t.first;
                int v=nbr.first;
                int wt=nbr.second;
                dist[u][v]=wt;
            }
        }
        for(int helper=0;helper<n;helper++){
            for(int src=0;src<n;src++){
                for(int dest=0;dest<n;dest++){
                    dist[src][dest]=min(dist[src][dest],dist[src][helper]+dist[helper][dest]);
                }
            }
        }
        cout<<"Printing Distances : \n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }


    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0, 1, 3, 1);
    g.addEdge(0, 3, 5, 1);
    g.addEdge(1, 0, 2, 1);
    g.addEdge(1, 3, 4, 1);
    g.addEdge(2, 1, 1, 1);
    g.addEdge(3, 2, 2, 1);
   
    g.floydWarshall(4);

    return 0;
}
