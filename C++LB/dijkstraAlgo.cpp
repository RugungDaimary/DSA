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
    
    void Dijkstra(int src,int n){
        
        vector<int> dist(n, INT_MAX);
        set<pair<int, int>> st;
        // intiial steps
        dist[src] = 0;
        st.insert(make_pair(0, src));

        while (!st.empty())
        {
            // fetch the smallest or first element from set
            auto topElement = *(st.begin());
            int nodeDistance = topElement.first;
            int node = topElement.second;

            // pop from set
            st.erase(st.begin());

            // neighbour traverse
            for (auto nbr : adjList[node])
            {
                if (nodeDistance + nbr.second < dist[nbr.first])
                {
                    // finding entry in set
                    auto result = st.find({dist[nbr.first], nbr.first});
                    // if found, then remove
                    if (result != st.end())
                    {
                        st.erase(result);
                    }
                    // updation in dist array and set
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert({dist[nbr.first], nbr.first} );
                }
            }
        }

        cout << "printing ans:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << dist[i] << ", ";
        }
        cout << endl;
    }
    
    
};
int main()
{
    Graph<int> g;
    int n = 8; // no of nodes
   
    // cyclic
    g.addEdge(6, 3, 2,0);
    g.addEdge(6, 1, 14,0);
    g.addEdge(3, 1, 9,0);
    g.addEdge(3, 2, 10,0);
    g.addEdge(1, 2, 7,0);
    g.addEdge(2, 4, 15,0);
    g.addEdge(4, 3, 11,0);
    g.addEdge(6, 5,9,0);
    g.addEdge(4, 5,6,0);
    g.print();
   
    

    

    return 0;
}

