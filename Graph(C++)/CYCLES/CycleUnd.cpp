// cycle detection in undirected graph

// using BFS
#include <bits/stdc++.h>
using namespace std;

bool isCycle(int node, vector<int> &vs, vector<vector<int>> &adjL)
{
    queue<pair<int, int>> pool;
    pool.push({node, -1});
    vs[node] = 1;
    while (!pool.empty())
    {
        int node = pool.front().first;
        int parent = pool.front().second;
        pool.pop();
        for (auto s : adjL[node])
        {
            if (!vs[s])
            {
                vs[s] = 1;
                pool.push({s, node});
            }
            else if (s != parent)
            {
                return true;
            }
        }
    }
    return false;
}
// for multiple components
bool isCycleInGraph(int V, vector<vector<int>> &adjL)
{
    vector<int> vs(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vs[i])
        {
            if (isCycle(i, vs, adjL)) // uses above or below fxn function
                return true;
        }
    }
    return false;
}

// using DFS
bool dfs(int node, vector<int> &vs, vector<vector<int>> &adjL, int parent)
{
    vs[node] = 1;
    for (auto s : adjL[node])
    {
        if (!vs[s])
        {
            if (dfs(s, vs, adjL, node))
                return true;
        }
        else if (s != parent)
            return true;
    }
    return false;
}