#include <bits/stdc++.h>
#include <limits> // Include for std::numeric_limits
using namespace std;
#include <bits/stdc++.h>
#include <limits> // Include for std::numeric_limits
using namespace std;

void dijkstra(int src, vector<vector<pair<int, double>>> &adjList, vector<double> &Dist)
{
    Dist[src] = 1.0;
    set<pair<double, int>, greater<pair<double, int>>> st; // increasing set // distance, node
    st.insert({Dist[src], src});
    while (!st.empty())
    {
        auto top = *st.begin();
        st.erase(st.begin());
        int node = top.second;
        double dist = top.first;
        for (auto &nbr : adjList[node])
        {
            double d = nbr.second;
            int v = nbr.first;
            double x = dist * d;
            if (x > Dist[v])
            {
                auto result = st.find({Dist[v], v});
                if (result != st.end())
                {
                    st.erase(result);
                }
                Dist[v] = x;
                st.insert({x, v});
            }
        }
    }
}

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
{
    vector<double> Dist(n, 0);                    // Initialization of Double value with 0
    vector<vector<pair<int, double>>> adjList(n); // node,weight
    for (int i = 0; i < edges.size(); i++)
    {
        adjList[edges[i][0]].push_back({edges[i][1], succProb[i]});
        adjList[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }
    dijkstra(start_node, adjList, Dist);
    return Dist[end_node];
}
int main()
{
    int n = 5; // Example size
    // std::vector<double> distance;
    // distance.resize(n, numeric_limits<double>::lowest());

    // // Optional: Print to verify
    // for (double d : distance)
    // {
    //     cout << d << " "<<endl;
    // }
    // double x=1;
    // cout<<x<<endl;
    // cout<<log2(10)<<endl;
    vector<vector<int>>edges={{2,3},{1,2},{3,4},{1,3},{1,4},{0,1},{2,4},{0,4},{0,2}};
    vector<double>succProb={0.06,0.26,0.49,0.25,0.2,0.64,0.23,0.21,0.77};
    int start=0;
    int end=3;
    cout << maxProbability(n, edges, succProb, start, end) << endl;

    return 0;
}