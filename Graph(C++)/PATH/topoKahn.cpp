// topological sort is done for dag.
// we have to sort the graph vertices in seach way that if uv is edge u must come before;
#include <bits/stdc++.h>
using namespace std;

void dfsSort(int node, vector<int> &vs, stack<int> &pool, vector<int> adj[])
{
    vs[node] = 1;
    for (auto it : adj[node])
    {
        if (!vs[it])
        {
            dfsSort(it, vs, pool, adj);
        }
    }
    pool.push(node);
    return;
}

vector<int> TopoSort(int v, vector<int> adj[])
{
    stack<int> pool;
    vector<int> vs(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!vs[i])
        {
            dfsSort(i, vs, pool, adj);
        }
    }
    vector<int> ans;
    while (!pool.empty())
    {
        ans.push_back(pool.top());
        pool.pop();
    }

    return ans;
}

// topo sort for bfs(kahn algo)
vector<int> TopoSort(int node, int v, vector<vector<int>> adj)
{
    vector<int> indeg(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            indeg[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        ans.push_back(curr);

        for (auto s : adj[curr])
        {
            indeg[s]--;
            if (indeg[s] == 0)
                q.push(s);
        }
    }

    return ans;
}
