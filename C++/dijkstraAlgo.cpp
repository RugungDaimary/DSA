#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
public:

    //we can create adjList by this
    // vector<int> adjList[n]; // have created vector<int> of array
                            // 0->[1,2]
                            // 1->[0,2]
                            // 2->[0,1]
    // vector<bool>visited;

    vector<vector<pair<int, int>>> adjList;

    Graph(int n)
    { // Constructor to initialize the adjacency list
        adjList.resize(n);
    }

    void addEdge(int u, int v, int wt, int direction = 0)
    { // Default direction 0 for undirected
        adjList[u].push_back({v, wt});
        if (direction == 0)
        {
            adjList[v].push_back({u, wt});
        }
    }


    void Dijkstra(int src, int n)
    {
        vector<int> distance(n, INT_MAX);
        set<pair<int, int>> st; // Set to find the node with the smallest distance
        distance[src] = 0;
        st.insert({0, src});

        while (!st.empty())
        {
            auto top = *st.begin();
            st.erase(st.begin());
            int dist = top.first;
            int node = top.second;

            // cout << "Visiting node " << node << " with distance " << dist << endl;

            for (auto &nbr : adjList[node])
            {
                int v = nbr.first;
                int d = nbr.second;

                if (dist + d < distance[v])
                {
                    auto it = st.find({distance[v], v});
                    if (it != st.end())
                    {
                        st.erase(it);
                    }
                    distance[v] = dist + d;
                    st.insert({distance[v], v});
                    // cout << "Updating distance of node " << v << " to " << distance[v] << endl;
                }
            }
        }

        // Optionally print distances from src
        for (int i = 0; i < n; ++i)
        {
            cout << "Distance from " << src << " to " << i << " is " << distance[i] << endl;
        }
    }
};
int main()
{
    int n = 8;       // Number of nodes
    Graph<int> g(n); // Initialize graph with n nodes

    // Adding edges
    g.addEdge(6, 3, 2, 0);
    g.addEdge(6, 1, 14, 0);
    g.addEdge(3, 1, 9, 0);
    g.addEdge(3, 2, 10, 0);
    g.addEdge(1, 2, 7, 0);
    g.addEdge(2, 4, 15, 0);
    g.addEdge(4, 3, 11, 0);
    g.addEdge(6, 5, 9, 0);
    g.addEdge(4, 5, 6, 0);

    g.Dijkstra(6, n); // Run Dijkstra starting from node 0

    return 0;
}
