// edges to adjList

#include <bits/stdc++.h>
using namespace std;

// Directed graph
vector<vector<int>> edgeAdjD(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adjL(n);
    for (auto s : edges)
    {
        int u = s[0];
        int v = s[1];
        adjL[u].push_back(v);
    }
    return adjL;
}

// Undirected graph
vector<vector<int>> edgeAdjU(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adjL(n);
    for (auto s : edges)
    {
        int u = s[0];
        int v = s[1];
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
    return adjL;
}
// weighted directed graph
vector<vector<pair<int, int>>> edgetoAdjLW(vector<vector<int>> &edges, int n)
{
    vector<vector<pair<int, int>>> ans(n);
    for (auto &s : edges)
    {
        ans[s[0]].push_back({s[1], s[2]});
    }
    return ans;
}
