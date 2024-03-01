//Strongly Connected Components
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Graph
{
public:
    unordered_map<int, list<int> >adjList;
    void addEdge(int u, int v, int direction)
    {
        // if direction=0 undirected
        adjList[u].push_back(v );
        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void topoSort(int src, stack<int> &st, unordered_map<int, bool> &vis)
    {
        vis[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!vis[nbr])
            {
                topoSort(nbr, st, vis);
            }
        }
        st.push(src);
    }

    void dfs(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjNew)
    {
        visited[src] = true;
        cout << src << ", ";

        for (auto nbr : adjNew[src])
        {
            if (!visited[nbr])
            {
                dfs(nbr, visited, adjNew);
            }
        }
    }

    int countSCC(int n)
    {
        stack<int> st;
        unordered_map<int, bool> vis;

        // find topo ordering
        for (int i = 0; i < n; i++)//this loop is for disconnected components
        {
            if (!vis[i])
            {
                topoSort(i, st, vis);
            }
        }

        // reverse all edges
        unordered_map<int, list<int>> adjNew;

        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr;
                // v-> u insert
                adjNew[v].push_back(u);
            }
        }

        // traversse using DFS
        int count = 0;
        unordered_map<int, bool> visited;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!visited[node])
            {
                cout << "Printing " << count + 1 << "th SCC: ";
                dfs(node, visited, adjNew);
               
                count++;
            }
        }

        return count;
    }



    //finding no of bridges in graph
    void findBridges(int src, int parent, int &timer, vector<int> &tin, vector<int> &low, unordered_map<int, bool>& vis)
    {

        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for (auto nbr : adjList[src])
        {
            if (nbr == parent)
                continue;
            if (!vis[nbr])
            {
                // dfs call
                findBridges(nbr, src, timer, tin, low, vis);
                // low update
                low[src] = min(low[src], low[nbr]);
                // check for bridge
                if (low[nbr] > tin[src])
                {
                    cout << nbr << "--" << src << " is a bridge" << endl;
                }
            }
            else
            {
                // node is visited and not a parent
                // low update
                low[src] = min(low[src], low[nbr]);
            }
        }
    }


  
};
int main()
{
    Graph<int> g;
/*
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 0, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 4, 1);
    g.addEdge(6, 7, 1);
    cout<<g.countSCC(8)<<endl;
*/
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 1, 0);
    g.addEdge(0, 3, 0);
    g.addEdge(3, 4, 0);
    int n=5;
    unordered_map<int,bool>visited;
    int timer=0;
    vector<int>tin(n);
    vector<int>low(n);
    g.findBridges(0,-1,timer,tin,low,visited);
   

    return 0;
}
