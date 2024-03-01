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
    void bellmannFord(int n,int src){
        //assuming directed weighted graph
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        //n-1 relaxation step
        for(int i=0;i<n-1;i++){
            for(auto t:adjList){
                for(auto nbr:t.second){
                    int u=t.first;
                    int v=nbr.first;
                    int wt=nbr.second;
                    if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
                        dist[v]=dist[u]+wt;
                    }
                }
            }

        }
        cout<<"Printing Distances : ";
        for(auto i:dist){
            cout<<i<<" ";
        }
        cout<<endl;

        //to check for -ve cycle
        bool negativeCycle=false;
        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                {
                    negativeCycle=true;
                    break;
                }
            }
        }
        if(negativeCycle){
            cout<<"-Ve Cycle Present\n";
        }else{
            cout<<"Not Present\n";
        }
    }

};
int main()
{
    Graph<int> g;
    g.addEdge(0,1,-1,1);
    g.addEdge(0,2,4,1);
    g.addEdge(1,2,3,1);
    g.addEdge(1,3,2,1);
    g.addEdge(1,4,2,1);
    g.addEdge(3,1,1,1);
    g.addEdge(3,2,5,1);
    g.addEdge(4,3,-3,1);
    g.bellmannFord(5,0);

    return 0;
}
