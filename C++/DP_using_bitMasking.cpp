/*
Problem Statement

Let there be N workers and N jobs. Any worker can be assigned to perform any job,
incurring some cost that may vary depending on the work-job assignment. It is
required to perform all jobs by assigning exactly one worker to each job and
exactly one job to each agent in such a way that the total cost of the assignment is minimized.

Input Format
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

Sample Input
4

[
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
]

Sample Output
13

Constraints
1<=N<=20
*/

// USING DP
#include <bits/stdc++.h>
using namespace std;
int n;
vector<bool> visited;
vector<vector<int>> dp;
int miniCost(int i, int val, vector<vector<int>> &cost)
{
    if (i == n)
    {
        return val;
    }
    if (dp[i][val] != -1)
        return dp[i][val];

    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        if (!visited[j])
        {
            visited[j] = true;
            ans = min(ans, miniCost(i + 1, val + cost[i][j], cost));
            visited[j] = false;
        }
    }
    return dp[i][val] = ans;
}
// using BitMasking
vector<vector<int>> DP;
int solve(int i, int mask, vector<vector<int>> &cost)
{
    if (i == n)
    {
        return 0;
    }
    if (DP[i][mask] != -1)
    {
        return DP[i][mask];
    }

    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        if ((mask >> j) & 1)
        { // means j-th job is available
            int newMask = mask ^ (1 << j);
            ans = min(ans, cost[i][j] + solve(i + 1, newMask, cost));
        }
    }

    return DP[i][mask] = ans;
}

int main()
{
    vector<vector<int>> cost = {{9, 2, 7, 8}, {6, 4, 3, 7}, {5, 8, 1, 8}, {7, 6, 9, 4}};
    n = cost.size();

    // dp.resize(n + 1, vector<int>(5000, -1));
    // visited.resize(n, false);
    // cout << miniCost(0, 0, cost) << endl;

    DP.resize(n, vector<int>(1 << n, -1)); // Resize DP to handle up to 2^n states

    int initialMask = (1 << n) - 1; // All jobs are available initially (1111 in binary for n=4)
    cout << solve(0, initialMask, cost) << endl;

    return 0;
}

/*



#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> dp;
int startNode = 0;

int travellingSalesman(int current, int mask, vector<vector<int>>& cost) {
    if (mask == (1 << n) - 1) {  // All nodes have been visited
        return cost[current][startNode];  // Return to the start node
    }
    if (dp[current][mask] != -1) {
        return dp[current][mask];
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!((mask >> i) & 1)) {  // If node i has not been visited
            int newMask = mask | (1 << i);
            ans = min(ans, cost[current][i] + travellingSalesman(i, newMask, cost));
        }
    }
    return dp[current][mask] = ans;
}

int main() {
    vector<vector<int>> cost = {
        {0, 1, 2, 3},
        {1, 0, 4, 6},
        {2, 4, 0, 5},
        {3, 6, 5, 0}
    };

    n = cost.size();
    dp.resize(n, vector<int>(1 << n, -1));

    int mask = 1 << startNode;  // Only the start node is visited initially

    cout << "Minimum cost of travelling salesman tour: "
         << travellingSalesman(startNode, mask, cost) << endl;

    return 0;
}

*/


//Count Tiling Using bits mapulation